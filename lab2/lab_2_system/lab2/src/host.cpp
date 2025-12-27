#include "xcl2.hpp"
#include "event_timer.hpp"
#include <algorithm>
#include <vector>

// Define dimensions as per Lab 2 instructions (Small dimensions for emulation)
#define WIDTH 128
#define HEIGHT 128
#define DATA_SIZE (WIDTH * HEIGHT)

// Software Reference Implementation (Gold Standard)
// This mimics the exact logic the FPGA should perform
void sw_reference(std::vector<int, aligned_allocator<int>> &in1,
                  std::vector<int, aligned_allocator<int>> &in2,
                  std::vector<int, aligned_allocator<int>> &out_sw) {

    // Temp buffer for the intermediate Posterize step
    std::vector<int> temp_diff(DATA_SIZE);

    // Step 1: Difference & Posterize
    for (int i = 0; i < DATA_SIZE; i++) {
        int val_a = in1[i];
        int val_b = in2[i];
        int diff = std::abs(val_a - val_b);

        if (diff < 32) temp_diff[i] = 0;
        else if (diff < 96) temp_diff[i] = 128;
        else temp_diff[i] = 255;
    }

    // Step 2: Sharpen Filter
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

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
        return EXIT_FAILURE;
    }

    EventTimer et;
    std::string binaryFile = argv[1];
    size_t vector_size_bytes = sizeof(int) * DATA_SIZE;
    cl_int err;
    cl::Context context;
    cl::Kernel krnl_image_diff;
    cl::CommandQueue q;

    et.add("Allocate Memory in Host Memory");
    std::vector<int, aligned_allocator<int>> source_in1(DATA_SIZE);
    std::vector<int, aligned_allocator<int>> source_in2(DATA_SIZE);
    std::vector<int, aligned_allocator<int>> source_hw_results(DATA_SIZE);
    std::vector<int, aligned_allocator<int>> source_sw_results(DATA_SIZE);
    et.finish();

    // Create test data (Random pixels 0-255)
    et.add("Fill the buffers");
    for(int i=0; i<DATA_SIZE; i++) {
        source_in1[i] = rand() % 256;
        source_in2[i] = rand() % 256;
        source_hw_results[i] = 0;
    }
    et.finish();

    // Calculate Software Reference
    et.add("Run Software Reference");
    sw_reference(source_in1, source_in2, source_sw_results);
    et.finish();

    // OPENCL HOST CODE AREA START
    auto devices = xcl::get_xil_devices();
    et.add("Load Binary File to Alveo U200");
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    int valid_device = 0;

    for (unsigned int i = 0; i < devices.size(); i++) {
        auto device = devices[i];
        OCL_CHECK(err, context = cl::Context(device, NULL, NULL, NULL, &err));
        OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));

        cl::Program program(context, {device}, bins, NULL, &err);
        if (err != CL_SUCCESS) {
            std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
        } else {
            std::cout << "Device[" << i << "]: program successful!\n";
            // Note: Kernel name must match the one in kernel.cpp (extern "C")
            OCL_CHECK(err, krnl_image_diff = cl::Kernel(program, "image_diff_sharpen", &err));
            valid_device++;
            break;
        }
    }
    if (valid_device == 0) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }
    et.finish();

    et.add("Allocate Buffer in Global Memory");
    OCL_CHECK(err, cl::Buffer buffer_in1(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, vector_size_bytes, source_in1.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_in2(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, vector_size_bytes, source_in2.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_output(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, vector_size_bytes, source_hw_results.data(), &err));
    et.finish();

    et.add("Set the Kernel Arguments");
    int width = WIDTH;
    int height = HEIGHT;
    // Args: in1, in2, out, width, height
    OCL_CHECK(err, err = krnl_image_diff.setArg(0, buffer_in1));
    OCL_CHECK(err, err = krnl_image_diff.setArg(1, buffer_in2));
    OCL_CHECK(err, err = krnl_image_diff.setArg(2, buffer_output));
    OCL_CHECK(err, err = krnl_image_diff.setArg(3, width));
    OCL_CHECK(err, err = krnl_image_diff.setArg(4, height));
    et.finish();

    et.add("Copy input data to device global memory");
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_in1, buffer_in2}, 0));
    et.finish();

    et.add("Launch the Kernel");
    OCL_CHECK(err, err = q.enqueueTask(krnl_image_diff));
    et.finish();

    et.add("Copy Result from Device Global Memory to Host Local Memory");
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output}, CL_MIGRATE_MEM_OBJECT_HOST));
    OCL_CHECK(err, err = q.finish());
    et.finish();

    // Compare results
    et.add("Compare the results of the Device to the simulation");
    bool match = true;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (source_hw_results[i] != source_sw_results[i]) {
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                      << " Device result = " << source_hw_results[i] << std::endl;
            match = false;
            break;
        }
    }
    et.finish();

    std::cout <<"----------------- Key execution times -----------------" << std::endl;
    et.print();

    std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
    return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}
