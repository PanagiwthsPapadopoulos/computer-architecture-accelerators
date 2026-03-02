# 🚀 Hardware-Software System Design & Accelerators: Lab Solutions

Welcome to the repository for the Hardware-Software System Design and Advanced Computer Architecture & Accelerators course! 🎓 This project focuses on designing, implementing, and optimizing hardware accelerators on FPGA platforms—specifically the **Alveo U200 Data Center Accelerator Card**—using **Xilinx Vitis** and **Vitis HLS**.

## 📑 Table of Contents
* [🧪 Lab 1: Vitis HLS Introduction & Image Posterization](#-lab-1-vitis-hls-introduction--image-posterization)
* [🖥️ Lab 2: Vitis System Integration & Image Sharpening](#️-lab-2-vitis-system-integration--image-sharpening)
* [⚡ Lab 3: Data Transfer Optimization & Memory Banking](#-lab-3-data-transfer-optimization--memory-banking)

---

### 🧪 Lab 1: Vitis HLS Introduction & Image Posterization
**🎯 Objective:** Familiarization with the High-Level Synthesis (HLS) design flow, utilizing C/C++ to create hardware kernels. 

* **🛠️ Task:** Designed the `IMAGE_DIFF_POSTERIZE` hardware accelerator.
* **⚙️ Functionality:** The accelerator takes two grayscale images as input, computes the absolute difference between their pixels, and applies a non-linear posterization transformation based on two thresholds (T1=32 and T2=96).
* **📈 Optimizations & Findings:**
    * Evaluated different HLS directives, including Loop Unrolling, Array Partitioning, and Pipelining.
    * Discovered that the algorithm is heavily **"Memory Bound,"** meaning its performance is restricted by the memory bandwidth rather than computational limits.
    * The optimal implementation utilized the `PIPELINE` directive (achieving a throughput of 1 pixel/cycle).
    * This resulted in a **4x speedup** over the baseline serial implementation, without exceeding the physical limits of the DRAM.

---

### 🖥️ Lab 2: Vitis System Integration & Image Sharpening
**🎯 Objective:** Transitioning to the unified Vitis platform to run the accelerator on the Alveo U200 FPGA, utilizing the Host-Kernel execution model (OpenCL for the Host, C++ for the Kernel.

* **🛠️ Task:** Extended the Lab 1 accelerator into `IMAGE_DIFF_SHARPEN`.
* **⚙️ Functionality:** After calculating the posterized difference of the two input images, the kernel applies a 3x3 sharpen filter convolution to highlight abrupt changes and edges.
* **📈 Optimizations & Findings:**
    * **🧩 Strip Tiling (Line Buffering):** Because storing a full image in BRAM is impossible, the image was divided into horizontal tiles of 64 lines (`TILE_HEIGHT=64`) to optimize DDR memory burst transactions.
    * **🛡️ Halo Management:** To properly apply the 3x3 stencil filter at the tile boundaries, overlapping rows (one above and one below) were read from memory to prevent visual artifacts.
    * Hardware emulation confirmed that adding aggressive loop unrolling (factor=8) actually increased the execution time (from 0.375 ms to 0.401 ms), heavily reinforcing the fact that the application remains strictly Memory Bound.

---

### ⚡ Lab 3: Data Transfer Optimization & Memory Banking
**🎯 Objective:** Maximizing system performance by alleviating the memory bottleneck and optimizing data transfers between the x86-host CPU and the FPGA accelerator.

* **🛠️ Task:** Applying advanced memory-level optimizations to the `IMAGE_DIFF_SHARPEN` kernel from Lab 2.
* **⚙️ Optimizations Applied:**
    * **🛣️ Vectorization (512-bit Interface):** Widened the memory bus interface from 32-bit to 512-bit (using the `uint512_dt` data type) to process 16 integers per clock cycle simultaneously.
    * **🏦 Memory Banking:** Mitigated memory channel contention by assigning the kernel's arguments to separate physical DDR banks: `in1` to DDR[0], `in2` to DDR[1], and `out` to DDR[2].
    * **🚦 Access Resolution:** Used `#pragma HLS ARRAY_PARTITION cyclic factor=16` to split local BRAM into 16 independent physical banks (Horizontal Access), and relied on Shift Registers via `#pragma HLS PIPELINE` to resolve vertical conflicts inherent to the 3x3 stencil algorithm.
* **🏆 Results:** Kernel execution time dropped from 0.325 ms (Lab 2 baseline) to 0.265 ms. This achieved an **over 22% speedup** due to parallel/overlapping memory reads and writes.

