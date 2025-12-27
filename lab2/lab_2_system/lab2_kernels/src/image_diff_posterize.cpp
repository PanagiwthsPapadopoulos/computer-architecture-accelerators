/*
    Image Difference & Sharpening Kernel
    Based on Vitis Lab 2 Requirements
*/


#define MAX_WIDTH 4096      // Support 4K images (max width 4096)
#define TILE_HEIGHT 128      // Process 64 rows at a time (Chunk size)
#define HALO 1              // 3x3 filter requires 1 pixel radius

// Internal BRAM buffer size: Tile Height + Top Halo + Bottom Halo
#define INPUT_BUFF_HEIGHT (TILE_HEIGHT + 2 * HALO)

// Helper function to clip values between 0-255
int clip(int x) {
    if (x < 0) return 0;
    if (x > 255) return 255;
    return x;
}

extern "C" {
void image_diff_sharpen(const int *in1,      // Image A
                        const int *in2,      // Image B
                        int *out_r,          // Output Image
                        int width,           // Image Width
                        int height           // Image Height
                        ) {

    // Standard AXI Interfaces
#pragma HLS INTERFACE m_axi port = in1 offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = in2 offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = out_r offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = in1 bundle = control
#pragma HLS INTERFACE s_axilite port = in2 bundle = control
#pragma HLS INTERFACE s_axilite port = out_r bundle = control
#pragma HLS INTERFACE s_axilite port = width bundle = control
#pragma HLS INTERFACE s_axilite port = height bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control


    // Local BRAM Buffers
    // We need enough space for the Tile + Halo rows
    int local_A[INPUT_BUFF_HEIGHT][MAX_WIDTH];
    int local_B[INPUT_BUFF_HEIGHT][MAX_WIDTH];
    int temp_diff[INPUT_BUFF_HEIGHT][MAX_WIDTH]; // Intermediate Posterized Result
    int local_Out[TILE_HEIGHT][MAX_WIDTH];

    #pragma HLS ARRAY_PARTITION variable=local_A cyclic factor=8 dim=2
    #pragma HLS ARRAY_PARTITION variable=local_B cyclic factor=8 dim=2
    #pragma HLS ARRAY_PARTITION variable=temp_diff cyclic factor=8 dim=2
    #pragma HLS ARRAY_PARTITION variable=local_Out cyclic factor=8 dim=2

    // Loop over the image in Chunks (Tiles)
    for (int y = 0; y < height; y += TILE_HEIGHT) {

        // Determine actual chunk size (handle last chunk if image height isn't multiple of 64)
        int current_tile_h = TILE_HEIGHT;
        if (y + current_tile_h > height) current_tile_h = height - y;

        // ============================================================
        // 1. BURST READ (With Halo)
        // ============================================================
        read_loop: for (int local_y = -HALO; local_y < current_tile_h + HALO; local_y++) {
             #pragma HLS UNROLL factor=8 // Removed outer unroll to avoid conflicts with inner pipelined loop
            int global_y = y + local_y;
            int buff_idx = local_y + HALO; // Map -1 to 0, 0 to 1, etc.

            if (global_y >= 0 && global_y < height) {
                // Read row from DDR to BRAM using loop instead of memcpy
                // Pipelining inside this loop infers burst read behavior
                int global_offset = global_y * width;
                read_row_loop: for (int k = 0; k < width; k++) {
                    #pragma HLS PIPELINE II=1
                    local_A[buff_idx][k] = in1[global_offset + k];
                    local_B[buff_idx][k] = in2[global_offset + k];
                }
            } else {
                // Zero out the row (Padding)
                // Manual loop replacement for memset
                pad_row_loop: for (int k = 0; k < width; k++) {
                    #pragma HLS PIPELINE II=1
                    local_A[buff_idx][k] = 0;
                    local_B[buff_idx][k] = 0;
                }
            }
        }

        // ============================================================
        // 2. COMPUTE: Difference & Posterize
        // ============================================================
        // We compute this for the whole buffer (including Halo) because
        // the Sharpen filter needs the posterized values of the neighbors.
        compute_diff: for (int i = 0; i < current_tile_h + 2*HALO; i++) {
            #pragma HLS UNROLL factor=8
            for (int j = 0; j < width; j++) {
            #pragma HLS PIPELINE II=1

                int val_a = local_A[i][j];
                int val_b = local_B[i][j];
                int diff = (val_a > val_b) ? (val_a - val_b) : (val_b - val_a); // abs()

                // Posterize Thresholds T1=32, T2=96
                int val_new = 0;
                if (diff < 32)       val_new = 0;
                else if (diff < 96)  val_new = 128;
                else                 val_new = 255;

                temp_diff[i][j] = val_new;
            }
        }

        // ============================================================
        // 3. COMPUTE: Sharpen Filter (3x3)
        // ============================================================
        // Only iterate over the VALID output rows (exclude halo rows from output)
        compute_sharpen: for (int i = 0; i < current_tile_h; i++) {
            #pragma HLS UNROLL factor=8
            for (int j = 0; j < width; j++) {
            #pragma HLS PIPELINE II=1

                // If on image boundary, just copy the value (Simplification)
                if ((y+i) == 0 || (y+i) == height-1 || j == 0 || j == width-1) {
                    local_Out[i][j] = temp_diff[i+HALO][j];
                } else {
                    // Apply Convolution
                    // Kernel:  0 -1  0
                    //         -1  5 -1
                    //          0 -1  0
                    // Center pixel in temp_diff is at [i + HALO][j]

                    int center = temp_diff[i+HALO][j];
                    int top    = temp_diff[i+HALO-1][j];
                    int bottom = temp_diff[i+HALO+1][j];
                    int left   = temp_diff[i+HALO][j-1];
                    int right  = temp_diff[i+HALO][j+1];

                    int sum = (5 * center) - top - bottom - left - right;
                    local_Out[i][j] = clip(sum); // Clip result
                }
            }
        }

        // ============================================================
        // 4. BURST WRITE
        // ============================================================
        write_loop: for (int i = 0; i < current_tile_h; i++) {
             #pragma HLS UNROLL factor=8 // Removed outer unroll to avoid conflicts
            // Write row from BRAM to DDR using loop instead of memcpy
            // Pipelining inside this loop infers burst write behavior
            int global_offset = (y + i) * width;
            write_row_loop: for (int k = 0; k < width; k++) {
                #pragma HLS PIPELINE II=1
                out_r[global_offset + k] = local_Out[i][k];
            }
        }
    }
}
}
