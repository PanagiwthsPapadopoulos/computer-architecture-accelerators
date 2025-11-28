#include <stdint.h>
#include <stdlib.h>


#define lW 6
#define lH 6
#define WIDTH  (1 << lW)
#define HEIGHT (1 << lH)

#define T1 32
#define T2 96

typedef uint8_t pixel_t;

void image_diff_posterize(
    pixel_t A[HEIGHT][WIDTH],
    pixel_t B[HEIGHT][WIDTH],
    pixel_t C[HEIGHT][WIDTH])
{
    #pragma HLS INTERFACE m_axi port=A bundle=gmem0 offset=slave depth=4096 max_read_burst_length=64
    #pragma HLS INTERFACE m_axi port=B bundle=gmem1 offset=slave depth=4096 max_read_burst_length=64
    #pragma HLS INTERFACE m_axi port=C bundle=gmem2 offset=slave depth=4096 max_read_burst_length=64
    #pragma HLS INTERFACE s_axilite port=return

    // 1. Create Local BRAM Buffers
    // Static ensures they are allocated in global memory simulation
    static pixel_t rowA[WIDTH];
    static pixel_t rowB[WIDTH];
    static pixel_t rowC[WIDTH];

    // 2. PARTITION the Local BRAMs
    // cyclic factor=8 splits BRAM to allow 8 parallel reads/writes
    #pragma HLS ARRAY_PARTITION variable=rowA cyclic factor=8
    #pragma HLS ARRAY_PARTITION variable=rowB cyclic factor=8
    #pragma HLS ARRAY_PARTITION variable=rowC cyclic factor=8

    int j;

    Row_Loop: for (int i = 0; i < HEIGHT; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=HEIGHT max=HEIGHT

        // --- THE MAGIC LINE ---
        // Uncomment this to run Read/Compute/Write in parallel
        // Leave commented if you want the standard buffer behavior
        // #pragma HLS DATAFLOW
        // ----------------------

        // 3. Burst Read (DDR -> BRAM)
        Read_Loop: for (j = 0; j < WIDTH; j++) {
            #pragma HLS PIPELINE II=1
            #pragma HLS LOOP_TRIPCOUNT min=WIDTH max=WIDTH
            rowA[j] = A[i][j];
            rowB[j] = B[i][j];
        }

        // 4. Compute (BRAM -> BRAM)
        Col_Loop: for (j = 0; j < WIDTH; j++) {
            #pragma HLS PIPELINE II=1
            #pragma HLS UNROLL factor=8 // Processing 8 pixels in parallel
            #pragma HLS LOOP_TRIPCOUNT min=WIDTH max=WIDTH

            int16_t diff_temp = (int16_t)rowA[j] - (int16_t)rowB[j];

            // Branchless absolute value check
            uint8_t diff = (diff_temp < 0) ? (uint8_t)(-diff_temp) : (uint8_t)(diff_temp);

            if (diff < T1) rowC[j] = 0;
            else if (diff < T2) rowC[j] = 128;
            else rowC[j] = 255;
        }

        // 5. Burst Write (BRAM -> DDR)
        Write_Loop: for (j = 0; j < WIDTH; j++) {
            #pragma HLS PIPELINE II=1
            #pragma HLS LOOP_TRIPCOUNT min=WIDTH max=WIDTH
            C[i][j] = rowC[j];
        }
    }
}
