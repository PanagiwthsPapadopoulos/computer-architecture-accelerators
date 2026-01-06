#include <cstring>

#define MAX_WIDTH 4096
#define TILE_HEIGHT 128
#define HALO 1
#define INPUT_BUFF_HEIGHT (TILE_HEIGHT + 2 * HALO)

int clip(int x) {
    if (x < 0) return 0;
    if (x > 255) return 255;
    return x;
}

static int local_A[INPUT_BUFF_HEIGHT][MAX_WIDTH];
static int local_B[INPUT_BUFF_HEIGHT][MAX_WIDTH];
static int temp_diff[INPUT_BUFF_HEIGHT][MAX_WIDTH];
static int local_Out[TILE_HEIGHT][MAX_WIDTH];

extern "C" {

void image_diff_sharpen(const int *in1, const int *in2, int *out_r, int width, int height) {

    // Interfaces: Kept the Dual-Port fix (gmem0 + gmem1)
    #pragma HLS INTERFACE m_axi port = in1 offset = slave bundle = gmem0
    #pragma HLS INTERFACE m_axi port = in2 offset = slave bundle = gmem1
    #pragma HLS INTERFACE m_axi port = out_r offset = slave bundle = gmem0
    #pragma HLS INTERFACE s_axilite port = in1 bundle = control
    #pragma HLS INTERFACE s_axilite port = in2 bundle = control
    #pragma HLS INTERFACE s_axilite port = out_r bundle = control
    #pragma HLS INTERFACE s_axilite port = width bundle = control
    #pragma HLS INTERFACE s_axilite port = height bundle = control
    #pragma HLS INTERFACE s_axilite port = return bundle = control



    // ========================================================================
    // FINAL FIX: 2D PARTITIONING FOR TEMP_DIFF
    // ========================================================================
    // 1. Row Partition (dim=1): Needed for Vertical Unrolling (8 rows at once)
    #pragma HLS ARRAY_PARTITION variable=local_A cyclic factor=8 dim=1
    #pragma HLS ARRAY_PARTITION variable=local_B cyclic factor=8 dim=1
    #pragma HLS ARRAY_PARTITION variable=local_Out cyclic factor=8 dim=1
    #pragma HLS ARRAY_PARTITION variable=temp_diff cyclic factor=8 dim=1

    // 2. Column Partition (dim=2): Needed for Horizontal Stencil (Left/Right/Center)
    // We add this ONLY to temp_diff because it's the only one doing 3x3 reads.
    // Factor 4 ensures j, j-1, and j+1 are always in different banks.
    #pragma HLS ARRAY_PARTITION variable=temp_diff cyclic factor=4 dim=2

    for (int y = 0; y < height; y += TILE_HEIGHT) {

        int current_tile_h = TILE_HEIGHT;
        if (y + current_tile_h > height) current_tile_h = height - y;

        // READ LOOP (Optimized for Burst)
        read_loop: for (int local_y = -HALO; local_y < current_tile_h + HALO; local_y++) {
            int global_y = y + local_y;
            int buff_idx = local_y + HALO;

            if (global_y >= 0 && global_y < height) {
                int global_offset = global_y * width;
                read_row_loop: for (int k = 0; k < width; k++) {
                    #pragma HLS PIPELINE II=1
                    local_A[buff_idx][k] = in1[global_offset + k];
                    local_B[buff_idx][k] = in2[global_offset + k];
                }
            } else {
                pad_row_loop: for (int k = 0; k < width; k++) {
                    #pragma HLS PIPELINE II=1
                    local_A[buff_idx][k] = 0;
                    local_B[buff_idx][k] = 0;
                }
            }
        }

        // COMPUTE LOOP 1 (Difference)
        compute_diff: for (int i = 0; i < current_tile_h + 2*HALO; i++) {
            #pragma HLS UNROLL factor=8
            for (int j = 0; j < width; j++) {
            #pragma HLS PIPELINE II=1

                int val_a = local_A[i][j];
                int val_b = local_B[i][j];
                int diff = (val_a > val_b) ? (val_a - val_b) : (val_b - val_a);

                int val_new = 0;
                if (diff < 32)       val_new = 0;
                else if (diff < 96)  val_new = 128;
                else                 val_new = 255;

                temp_diff[i][j] = val_new;
            }
        }

        // COMPUTE LOOP 2 (Sharpen) - Now runs at II=1
        compute_sharpen: for (int i = 0; i < current_tile_h; i++) {
            #pragma HLS UNROLL factor=8
            for (int j = 0; j < width; j++) {
            #pragma HLS PIPELINE II=1

                if ((y+i) == 0 || (y+i) == height-1 || j == 0 || j == width-1) {
                    local_Out[i][j] = temp_diff[i+HALO][j];
                } else {
                    // Thanks to dim=2 partition, these 3 reads map to different banks
                    int center = temp_diff[i+HALO][j];    // Bank A
                    int top    = temp_diff[i+HALO-1][j];
                    int bottom = temp_diff[i+HALO+1][j];
                    int left   = temp_diff[i+HALO][j-1];  // Bank B
                    int right  = temp_diff[i+HALO][j+1];  // Bank C

                    int sum = (5 * center) - top - bottom - left - right;
                    local_Out[i][j] = clip(sum);
                }
            }
        }

        // WRITE LOOP
        write_loop: for (int i = 0; i < current_tile_h; i++) {
            int global_offset = (y + i) * width;
            write_row_loop: for (int k = 0; k < width; k++) {
                #pragma HLS PIPELINE II=1
                out_r[global_offset + k] = local_Out[i][k];
            }
        }
    }
}
}
