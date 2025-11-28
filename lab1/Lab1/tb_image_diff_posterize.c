#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define lW 8
#define lH 8
#define WIDTH  (1 << lW)  // 2^8 = 256
#define HEIGHT (1 << lH)  // 2^8 = 256

#define T1 32
#define T2 96

typedef uint8_t pixel_t;

void image_diff_posterize(
    pixel_t A[HEIGHT][WIDTH],
    pixel_t B[HEIGHT][WIDTH],
    pixel_t C[HEIGHT][WIDTH]
);

void image_diff_posterize_sw_ref(
    pixel_t A[HEIGHT][WIDTH],
    pixel_t B[HEIGHT][WIDTH],
    pixel_t C_ref[HEIGHT][WIDTH])
{
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int16_t diff_temp = (int16_t)A[i][j] - (int16_t)B[i][j];
            uint8_t diff = (diff_temp < 0) ? (uint8_t)(-diff_temp) : (uint8_t)(diff_temp);

            if (diff < T1) {
                C_ref[i][j] = 0;
            } else if (diff < T2) {
                C_ref[i][j] = 128;
            } else {
                C_ref[i][j] = 255;
            }
        }
    }
}

void init_gradient_image(pixel_t img[HEIGHT][WIDTH], int offset, int scale) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int value = (i * scale + j + offset) % 256;
            img[i][j] = (pixel_t)value;
        }
    }
}

void init_random_image(pixel_t img[HEIGHT][WIDTH], unsigned int seed) {
    int i, j;
    srand(seed);
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            img[i][j] = (pixel_t)(rand() % 256);
        }
    }
}

void print_image_subset(pixel_t img[HEIGHT][WIDTH], int rows, int cols, const char* title) {
    int i, j;
    printf("\n%s (%d*%d pixels):\n", title, rows, cols);
    for (i = 0; i < rows && i < HEIGHT; i++) {
        for (j = 0; j < cols && j < WIDTH; j++) {
            printf("%3d ", img[i][j]);
        }
        printf("\n");
    }
}

void calculate_statistics(pixel_t C[HEIGHT][WIDTH]) {
    int i, j;
    int count_0 = 0;
    int count_128 = 0;
    int count_255 = 0;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (C[i][j] == 0) count_0++;
            else if (C[i][j] == 128) count_128++;
            else if (C[i][j] == 255) count_255++;
        }
    }

    printf("\nImage statistics:\n");
    printf("  Black pixels (0):     %d (%.2f%%)\n", count_0, 100.0 * count_0 / (HEIGHT * WIDTH));
    printf("  Gray pixels (128):    %d (%.2f%%)\n", count_128, 100.0 * count_128 / (HEIGHT * WIDTH));
    printf("  White pixels (255):   %d (%.2f%%)\n", count_255, 100.0 * count_255 / (HEIGHT * WIDTH));
    printf("  Total pixels:         %d\n", HEIGHT * WIDTH);
}

int main() {
    int i, j;
    int errors;
    int first_error_i, first_error_j;

    static pixel_t A[HEIGHT][WIDTH];
    static pixel_t B[HEIGHT][WIDTH];
    static pixel_t C_hw[HEIGHT][WIDTH];
    static pixel_t C_sw[HEIGHT][WIDTH];

    printf("=================================================\n");
    printf("IMAGE_DIFF_POSTERIZE TESTBENCH\n");
    printf("=================================================\n");
    printf("Dimensions: %d x %d\n", HEIGHT, WIDTH);
    printf("Thresholds: T1 = %d, T2 = %d\n", T1, T2);
    printf("=================================================\n");

    // Test Case 1: Gradient patterns
    printf("\n--- Test Case 1: Gradient Patterns ---\n");
    init_gradient_image(A, 0, 1);
    init_gradient_image(B, 50, 1);

    print_image_subset(A, 8, 8, "Image A");
    print_image_subset(B, 8, 8, "Image B");

    printf("\nRunning software reference...\n");
    image_diff_posterize_sw_ref(A, B, C_sw);

    printf("Running hardware accelerator...\n");
    image_diff_posterize(A, B, C_hw);

    printf("\nComparing results...\n");
    errors = 0;
    first_error_i = -1;
    first_error_j = -1;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (C_hw[i][j] != C_sw[i][j]) {
                errors++;
                if (first_error_i == -1) {
                    first_error_i = i;
                    first_error_j = j;
                }
            }
        }
    }

    if (errors == 0) {
        printf("[PASS] Test Case 1 PASSED!\n");
    } else {
        printf("[FAIL] Test Case 1 FAILED! Found %d errors.\n", errors);
        printf("  First error at [%d][%d]: HW=%d, SW=%d\n",
               first_error_i, first_error_j,
               C_hw[first_error_i][first_error_j],
               C_sw[first_error_i][first_error_j]);
    }

    print_image_subset(C_hw, 8, 8, "Output Image C (Hardware)");
    calculate_statistics(C_hw);

    // Test Case 2: Random Values
    printf("\n--- Test Case 2: Random Values ---\n");
    init_random_image(A, 12345);
    init_random_image(B, 67890);

    printf("\nRunning software reference...\n");
    image_diff_posterize_sw_ref(A, B, C_sw);

    printf("Running hardware accelerator...\n");
    image_diff_posterize(A, B, C_hw);

    printf("\nComparing results...\n");
    errors = 0;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (C_hw[i][j] != C_sw[i][j]) {
                errors++;
                if (errors == 1) {
                    first_error_i = i;
                    first_error_j = j;
                }
            }
        }
    }

    if (errors == 0) {
        printf("[PASS] Test Case 2 PASSED!\n");
    } else {
        printf("[FAIL] Test Case 2 FAILED! Found %d errors.\n", errors);
        printf("  First error at [%d][%d]: HW=%d, SW=%d\n",
               first_error_i, first_error_j,
               C_hw[first_error_i][first_error_j],
               C_sw[first_error_i][first_error_j]);
    }

    calculate_statistics(C_hw);

    // Test Case 3: Edge Cases
    printf("\n--- Test Case 3: Edge Cases ---\n");

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if ((i + j) % 3 == 0) {
                A[i][j] = 0;
                B[i][j] = T1 - 1;
            } else if ((i + j) % 3 == 1) {
                A[i][j] = 0;
                B[i][j] = T1 + 1;
            } else {
                A[i][j] = 0;
                B[i][j] = T2;
            }
        }
    }

    printf("\nRunning software reference...\n");
    image_diff_posterize_sw_ref(A, B, C_sw);

    printf("Running hardware accelerator...\n");
    image_diff_posterize(A, B, C_hw);

    printf("\nComparing results...\n");
    errors = 0;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (C_hw[i][j] != C_sw[i][j]) {
                errors++;
            }
        }
    }

    if (errors == 0) {
        printf("[PASS] Test Case 3 PASSED!\n");
    } else {
        printf("[FAIL] Test Case 3 FAILED! Found %d errors.\n", errors);
    }

    calculate_statistics(C_hw);

    // Final Result
    printf("\n=================================================\n");
    printf("FINAL TESTBENCH RESULT\n");
    printf("=================================================\n");

    if (errors == 0) {
        printf(">>> ALL TESTS PASSED <<<\n");
        printf("Hardware accelerator works correctly.\n");
        return 0;
    } else {
        printf(">>> SOME TESTS FAILED <<<\n");
        printf("Please check the hardware accelerator implementation.\n");
        return 1;
    }
	return 0;
}
