#include <cstring>
#include <ap_int.h> // REQUIRED for 512-bit vector types

// Optimizations for Lab 3 [cite: 2128]
#define MAX_WIDTH 4096
#define TILE_HEIGHT 128
#define HALO 1
#define INPUT_BUFF_HEIGHT (TILE_HEIGHT + 2 * HALO)

// Use 1D buffers as requested in Lab 3 Hint 2
#define TOTAL_BUFF_SIZE (INPUT_BUFF_HEIGHT * MAX_WIDTH)
#define OUT_BUFF_SIZE (TILE_HEIGHT * MAX_WIDTH)

// Define a 512-bit vector type (16 integers * 32 bits) [cite: 1714]
typedef ap_uint<512> uint512_dt;

// Helper for Lab 2 Logic [cite: 3158]
int clip(int x) {
    if (x < 0) return 0;
    if (x > 255) return 255;
    return x;
}

// ========================================================================
// OPTIMIZATION: 1D BUFFERS (As requested by Hint 2 )
// We flatten [ROWS][COLS] into [ROWS * MAX_WIDTH + COLS]
// ========================================================================
static int local_A[TOTAL_BUFF_SIZE];
static int local_B[TOTAL_BUFF_SIZE];
static int temp_diff[TOTAL_BUFF_SIZE];
static int local_Out[OUT_BUFF_SIZE];

extern "C" {

void image_diff_sharpen(const uint512_dt *in1, const uint512_dt *in2, uint512_dt *out_r, int width, int height) {

    // Interfaces: Dedicated Memory Banks (gmem0, gmem1, gmem2)
    // This allows simultaneous data transfer for A, B, and C.
    #pragma HLS INTERFACE m_axi port = in1 offset = slave bundle = gmem0
    #pragma HLS INTERFACE m_axi port = in2 offset = slave bundle = gmem1
    #pragma HLS INTERFACE m_axi port = out_r offset = slave bundle = gmem2

    // Control interfaces
    #pragma HLS INTERFACE s_axilite port = in1 bundle = control
    #pragma HLS INTERFACE s_axilite port = in2 bundle = control
    #pragma HLS INTERFACE s_axilite port = out_r bundle = control
    #pragma HLS INTERFACE s_axilite port = width bundle = control
    #pragma HLS INTERFACE s_axilite port = height bundle = control
    #pragma HLS INTERFACE s_axilite port = return bundle = control

    // ========================================================================
    // PARTITIONING FOR 1D ARRAYS [cite: 2127]
    // ========================================================================
    // Cyclic factor 16 ensures we can read/write 16 continuous integers
    // (one 512-bit vector) in a single clock cycle without port conflicts.
    #pragma HLS ARRAY_PARTITION variable=local_A cyclic factor=16 dim=1
    #pragma HLS ARRAY_PARTITION variable=local_B cyclic factor=16 dim=1
    #pragma HLS ARRAY_PARTITION variable=local_Out cyclic factor=16 dim=1
    #pragma HLS ARRAY_PARTITION variable=temp_diff cyclic factor=16 dim=1

    // Process image in Tiles to fit in BRAM
    for (int y = 0; y < height; y += TILE_HEIGHT) {

        int current_tile_h = TILE_HEIGHT;
        if (y + current_tile_h > height) current_tile_h = height - y;

        // --- READ LOOP (Wide Bus -> 1D Array) ---
        // Transfer 512 bits (16 pixels) at a time [cite: 2128]
        read_loop: for (int local_y = -HALO; local_y < current_tile_h + HALO; local_y++) {
            int global_y = y + local_y;
            int buff_row_idx = local_y + HALO;

            if (global_y >= 0 && global_y < height) {
                // Calculate global offset for 512-bit pointer (divide by 16)
                int global_offset_512 = (global_y * width) / 16;

                // Calculate base index in local 1D buffer: i * DIM
                int local_base_idx = buff_row_idx * MAX_WIDTH;

                read_row_wide: for (int k = 0; k < width / 16; k++) {
                    #pragma HLS PIPELINE II=1
                    uint512_dt val_wide_a = in1[global_offset_512 + k];
                    uint512_dt val_wide_b = in2[global_offset_512 + k];

                    // Unpack 512 bits -> 16 integers using .range()
                    for (int v = 0; v < 16; v++) {
                        #pragma HLS UNROLL
                        // Access 32-bit data from 512-bit vector
                        int pixel_a = val_wide_a.range(32 * (v + 1) - 1, 32 * v);
                        int pixel_b = val_wide_b.range(32 * (v + 1) - 1, 32 * v);

                        // 1D Access: base + column_offset
                        local_A[local_base_idx + k * 16 + v] = pixel_a;
                        local_B[local_base_idx + k * 16 + v] = pixel_b;
                    }
                }
            } else {
                // Zero padding for HALO rows
                int local_base_idx = buff_row_idx * MAX_WIDTH;
                pad_row_loop: for (int k = 0; k < width; k++) {
                    #pragma HLS PIPELINE II=1
                    local_A[local_base_idx + k] = 0;
                    local_B[local_base_idx + k] = 0;
                }
            }
        }

        // --- COMPUTE LOOP 1 (Difference + Posterize) [cite: 3004, 3010] ---
        compute_diff: for (int i = 0; i < current_tile_h + 2*HALO; i++) {
            #pragma HLS UNROLL factor=16
            for (int j = 0; j < width; j++) {
            #pragma HLS PIPELINE II=1

                // 1D Indexing: i * MAX_WIDTH + j
                int idx = i * MAX_WIDTH + j;

                int val_a = local_A[idx];
                int val_b = local_B[idx];
                // D(i,j) = |A - B| [cite: 3007]
                int diff = (val_a > val_b) ? (val_a - val_b) : (val_b - val_a);

                // Posterize based on T1=32, T2=96 [cite: 2995]
                int val_new = 0;
                if (diff < 32)       val_new = 0;
                else if (diff < 96)  val_new = 128;
                else                 val_new = 255;

                temp_diff[idx] = val_new;
            }
        }

        // --- COMPUTE LOOP 2 (Sharpen Filter) [cite: 3153] ---
        // Kernel: [[0,-1,0], [-1,5,-1], [0,-1,0]] [cite: 3155]
        compute_sharpen: for (int i = 0; i < current_tile_h; i++) {
            #pragma HLS UNROLL factor=16
            for (int j = 0; j < width; j++) {
            #pragma HLS PIPELINE II=1

                // Output 1D Index
                int out_idx = i * MAX_WIDTH + j;

                // Input (temp_diff) Row Indices
                int row_center = i + HALO;
                int row_top    = i + HALO - 1;
                int row_bottom = i + HALO + 1;

                // Border Handling: Copy Value or Set to 0 [cite: 3166]
                if ((y+i) == 0 || (y+i) == height-1 || j == 0 || j == width-1) {
                    local_Out[out_idx] = temp_diff[row_center * MAX_WIDTH + j];
                } else {
                    // 1D Stencil Access [cite: 3156]
                    int center = temp_diff[row_center * MAX_WIDTH + j];
                    int top    = temp_diff[row_top    * MAX_WIDTH + j];
                    int bottom = temp_diff[row_bottom * MAX_WIDTH + j];
                    int left   = temp_diff[row_center * MAX_WIDTH + (j - 1)];
                    int right  = temp_diff[row_center * MAX_WIDTH + (j + 1)];

                    int sum = (5 * center) - top - bottom - left - right;
                    local_Out[out_idx] = clip(sum); // Clip to [0,255] [cite: 3158]
                }
            }
        }

        // --- WRITE LOOP (1D Array -> Wide Bus) ---
        write_loop: for (int i = 0; i < current_tile_h; i++) {
            int global_offset_512 = ((y + i) * width) / 16;
            int local_base_idx = i * MAX_WIDTH;

            write_row_wide: for (int k = 0; k < width / 16; k++) {
                #pragma HLS PIPELINE II=1
                uint512_dt val_wide_out = 0;

                // Pack 16 integers into 512 bits
                for (int v = 0; v < 16; v++) {
                    #pragma HLS UNROLL
                    int pixel = local_Out[local_base_idx + k * 16 + v];
                    val_wide_out.range(32 * (v + 1) - 1, 32 * v) = pixel;
                }
                out_r[global_offset_512 + k] = val_wide_out;
            }
        }
    }
}
}
