/**
 * Vitis Host Application for image_diff_sharpen
 * Logic: Setup OpenCL -> Run Software Ref -> Run Hardware Kernel -> Compare
 */

#include "xcl2.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>

// Dimensions matching HLS Testbench settings
#define WIDTH 128
#define HEIGHT 128
#define DATA_SIZE (WIDTH * HEIGHT)

// ============================================================================
// Software Reference (Golden Model)
// This logic matches host_vitis_hls.cpp exactly to ensure fair verification
// ============================================================================
void sw_reference(const std::vector<int, aligned_allocator<int>> &in1,
                  const std::vector<int, aligned_allocator<int>> &in2,
                  std::vector<int, aligned_allocator<int>> &out_sw) {

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

                // Clip result to 0-255
                if (sum < 0) sum = 0;
                if (sum > 255) sum = 255;
                out_sw[idx] = sum;
            }
        }
    }
}

// ============================================================================
// Main Application
// ============================================================================
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    cl_int err;
    cl::CommandQueue q;
    cl::Context context;
    cl::Kernel krnl_sharpen;

    // ------------------------------------------------------------------------
    // 1. Initialize Host Memory (Using aligned_allocator for XRT optimization)
    // ------------------------------------------------------------------------
    size_t vector_size_bytes = sizeof(int) * DATA_SIZE;

    std::vector<int, aligned_allocator<int>> source_in1(DATA_SIZE);
    std::vector<int, aligned_allocator<int>> source_in2(DATA_SIZE);
    std::vector<int, aligned_allocator<int>> source_hw_results(DATA_SIZE);
    std::vector<int, aligned_allocator<int>> source_sw_results(DATA_SIZE);

    // Fill with Random Data
    srand(12345);
    for(int i = 0; i < DATA_SIZE; i++) {
        source_in1[i] = rand() % 256;
        source_in2[i] = rand() % 256;
        source_hw_results[i] = 0; // Clear HW output buffer
    }

    // ------------------------------------------------------------------------
    // 2. Run Software Reference
    // ------------------------------------------------------------------------
    std::cout << "Running Software Reference..." << std::endl;
    sw_reference(source_in1, source_in2, source_sw_results);

    // ------------------------------------------------------------------------
    // 3. Setup OpenCL / Vitis Device
    // ------------------------------------------------------------------------
    auto devices = xcl::get_xil_devices();
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    bool valid_device = false;

    for (unsigned int i = 0; i < devices.size(); i++) {
        auto device = devices[i];
        OCL_CHECK(err, context = cl::Context(device, nullptr, nullptr, nullptr, &err));
        OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));

        std::cout << "Programming device: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
        cl::Program program(context, {device}, bins, nullptr, &err);
        if (err != CL_SUCCESS) {
            std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
        } else {
            // ------------------------------------------------------------
            // Correct Kernel Name "image_diff_sharpen"
            // ------------------------------------------------------------
            std::cout << "Creating Kernel object for 'image_diff_sharpen'..." << std::endl;
            OCL_CHECK(err, krnl_sharpen = cl::Kernel(program, "image_diff_sharpen", &err));
            valid_device = true;
            break;
        }
    }
    if (!valid_device) {
        std::cout << "Failed to program any device found, exit!\n";
        return EXIT_FAILURE;
    }

    // ------------------------------------------------------------------------
    // 4. Allocate Device Buffers
    // ------------------------------------------------------------------------
    // We use CL_MEM_USE_HOST_PTR so the FPGA accesses the host vectors directly via PCIe/DMA
    OCL_CHECK(err, cl::Buffer buffer_in1(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
            vector_size_bytes, source_in1.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_in2(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
            vector_size_bytes, source_in2.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_out(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
            vector_size_bytes, source_hw_results.data(), &err));

    // ------------------------------------------------------------------------
    // 5. Set Kernel Arguments
    // ------------------------------------------------------------------------
    // HLS Signature: void image_diff_sharpen(const int *in1, const int *in2, int *out_r, int width, int height)
    int width = WIDTH;
    int height = HEIGHT;

    int narg = 0;
    OCL_CHECK(err, err = krnl_sharpen.setArg(narg++, buffer_in1)); // Arg 0: in1
    OCL_CHECK(err, err = krnl_sharpen.setArg(narg++, buffer_in2)); // Arg 1: in2
    OCL_CHECK(err, err = krnl_sharpen.setArg(narg++, buffer_out)); // Arg 2: out_r
    OCL_CHECK(err, err = krnl_sharpen.setArg(narg++, width));      // Arg 3: width
    OCL_CHECK(err, err = krnl_sharpen.setArg(narg++, height));     // Arg 4: height

    // ------------------------------------------------------------------------
    // 6. Execution (Migrate -> Execute -> Migrate)
    // ------------------------------------------------------------------------
    std::cout << "Migrating memory to device..." << std::endl;
    // Migrate inputs (in1, in2) to device memory
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_in1, buffer_in2}, 0));

    std::cout << "Launching Kernel..." << std::endl;
    OCL_CHECK(err, err = q.enqueueTask(krnl_sharpen));

    std::cout << "Getting results..." << std::endl;
    // Migrate output (out) back to host memory
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_out}, CL_MIGRATE_MEM_OBJECT_HOST));
    q.finish();

    // ------------------------------------------------------------------------
    // 7. Verify Results
    // ------------------------------------------------------------------------
    int errors = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (source_hw_results[i] != source_sw_results[i]) {
            std::cout << "Error at index " << i
                      << " SW: " << source_sw_results[i]
                      << " HW: " << source_hw_results[i] << std::endl;
            errors++;
            if (errors > 10) break; // Stop after 10 errors
        }
    }

    if (errors == 0) {
        std::cout << "TEST PASSED! All results match." << std::endl;
        return 0;
    } else {
        std::cout << "TEST FAILED with " << errors << " errors." << std::endl;
        return 1;
    }
}
