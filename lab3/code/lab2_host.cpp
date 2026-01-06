#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

// ============================================================================
// 1. Kernel Function Declaration
// ============================================================================
// We must declare the function prototype here so the testbench knows how to call it.
extern "C" void image_diff_sharpen(const int *in1, const int *in2, int *out_r, int width, int height);

// ============================================================================
// 2. Simulation Settings
// ============================================================================
#define WIDTH 128
#define HEIGHT 128
#define DATA_SIZE (WIDTH * HEIGHT)

// ============================================================================
// 3. Software Reference (Golden Model)
// ============================================================================
void sw_reference(const std::vector<int> &in1,
                  const std::vector<int> &in2,
                  std::vector<int> &out_sw) {

    // Temp buffer for the intermediate Posterize step
    std::vector<int> temp_diff(DATA_SIZE);

    // Step A: Difference & Posterize
    for (int i = 0; i < DATA_SIZE; i++) {
        int val_a = in1[i];
        int val_b = in2[i];
        int diff = std::abs(val_a - val_b);

        if (diff < 32) temp_diff[i] = 0;
        else if (diff < 96) temp_diff[i] = 128;
        else temp_diff[i] = 255;
    }

    // Step B: Sharpen Filter
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int idx = y * WIDTH + x;

            // Boundary check: Copy value if on edge
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                out_sw[idx] = temp_diff[idx];
            } else {
                // Apply 3x3 Filter
                int center = temp_diff[y * WIDTH + x];
                int top    = temp_diff[(y - 1) * WIDTH + x];
                int bottom = temp_diff[(y + 1) * WIDTH + x];
                int left   = temp_diff[y * WIDTH + (x - 1)];
                int right  = temp_diff[y * WIDTH + (x + 1)];

                int sum = (5 * center) - top - bottom - left - right;

                // Clip
                if (sum < 0) sum = 0;
                if (sum > 255) sum = 255;
                out_sw[idx] = sum;
            }
        }
    }
}

// ============================================================================
// 4. Main Testbench
// ============================================================================
int main() {
    std::cout << "Starting Vitis HLS C Simulation..." << std::endl;

    // Allocate Memory
    std::vector<int> source_in1(DATA_SIZE);
    std::vector<int> source_in2(DATA_SIZE);
    std::vector<int> hw_results(DATA_SIZE); // Output from the Kernel
    std::vector<int> sw_results(DATA_SIZE); // Output from CPU Reference

    // Initialize Inputs with Random Data
    for(int i = 0; i < DATA_SIZE; i++) {
        source_in1[i] = rand() % 256;
        source_in2[i] = rand() % 256;
        hw_results[i] = 0; // Clear output
    }

    // ------------------------------------------------------
    // RUN SOFTWARE REFERENCE
    // ------------------------------------------------------
    std::cout << "Running Software Reference..." << std::endl;
    sw_reference(source_in1, source_in2, sw_results);

    // ------------------------------------------------------
    // RUN HARDWARE KERNEL (Direct C Call)
    // ------------------------------------------------------
    std::cout << "Running Hardware Kernel (C Model)..." << std::endl;
    // Note: In HLS C-Sim, we pass pointers to the vectors directly
    image_diff_sharpen(source_in1.data(),
                       source_in2.data(),
                       hw_results.data(),
                       WIDTH,
                       HEIGHT);

    // ------------------------------------------------------
    // VERIFY RESULTS
    // ------------------------------------------------------
    int errors = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (hw_results[i] != sw_results[i]) {
            std::cout << "Error at index " << i
                      << " SW: " << sw_results[i]
                      << " HW: " << hw_results[i] << std::endl;
            errors++;
            // Stop after 10 errors to avoid spamming the console
            if (errors > 10) break;
        }
    }

    if (errors == 0) {
        std::cout << "Test Passed! All results match." << std::endl;
        return 0;
    } else {
        std::cout << "Test Failed with " << errors << " errors." << std::endl;
        return 1;
    }
}
