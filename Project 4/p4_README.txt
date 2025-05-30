
CUDA Project: Performance Analysis of CPU and GPU Kernels  
Group 9  
Cleveland State University  
CIS 345

Contributors  
- Rached Arda: 2817303   
- Michael Hylton:   

---

Project Overview  
This project analyzes the computational performance differences between CPU-based computation, a single-block GPU kernel (1_block_GPU_kernel), and a multi-block GPU kernel (m_block_GPU_kernel). The implementation was carried out using CUDA, and the project includes performance benchmarks and observations.


Execution Details  
To compile and execute the code, use the following commands:

1. Compilation: 
   bash
   nvcc -o p4_template p4_template.cu
   ```

2. Execution:
   bash
   ./p4_template
   


 Observations on Computational Performance  

 Performance Analysis  
- CPU Execution:  
  The CPU implementation performed significantly slower compared to GPU-based implementations. This was expected due to the lack of parallelization.  
- 1_block_GPU_kernel Execution:  
  This implementation showed improved performance over the CPU version, leveraging some level of parallelism. However, it was limited by the single block's resource constraints.  
- m_block_GPU_kernel Execution:  
  The multi-block kernel exhibited the best performance, taking full advantage of CUDA's ability to distribute computations across multiple blocks and threads.


Key Observations  
1. Performance Differences: 
   - CPU: Slowest due to sequential execution.  
   - 1_block_GPU_kernel: Moderate improvement, limited by single block resources.  
2. Reason for Differences:  
   - The CPU executes tasks sequentially, leading to higher execution time.  
   - A single-block GPU kernel, while parallel, is constrained by the number of threads in a single block.  


Sample Output:  
mainfaxpyCudaOverall: 1051.045 ms               [0.213 GB/s]
xy array --> device 8.835 ms
GPU computation duration 1037.438 ms
CPU computation duration 19.465 ms
device faxpy outputs are correct!


- All modules are functional.  
- If issues arise during execution, possible causes include insufficient GPU memory allocation or a mismatch in thread configuration.

