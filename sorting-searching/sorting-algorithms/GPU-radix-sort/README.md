# GPU Radix Sort

GPU Radix Sort is a high-performance non-comparative integer sorting algorithm optimized for massively parallel execution on GPUs.

Unlike comparison-based algorithms like QuickSort or MergeSort, Radix Sort sorts numbers digit-by-digit (or bit-by-bit), making it ideal for GPU architectures because operations can be parallelized efficiently.

This project provides implementations in:

- C++
- JavaScript
- Python
- Java

---

# Features

- Integer sorting
- Stable sorting
- Parallel-friendly design
- High throughput
- Linear time complexity for fixed-width integers
- Suitable for CUDA/OpenCL adaptation

---

# Time Complexity

| Case | Complexity |
|------|-------------|
| Best | O(nk) |
| Average | O(nk) |
| Worst | O(nk) |

Where:

- `n` = number of elements
- `k` = number of digits/bits

---

# Space Complexity

```text
O(n + b)
```
Where:

n = input size
b = radix bucket count
GPU-Oriented Design

## GPU Radix Sort typically uses:

Histogram computation
Prefix scan (exclusive scan)
Scatter operation
Multiple radix passes

This repository demonstrates CPU simulation of GPU-style radix sort logic.

## Algorithm Steps

Example:

Input:
[170, 45, 75, 90, 802, 24, 2, 66]

Pass 1 (1s place):
[170, 90, 802, 2, 24, 45, 75, 66]

Pass 2 (10s place):
[802, 2, 24, 45, 66, 170, 75, 90]

Pass 3 (100s place):
[2, 24, 45, 66, 75, 90, 170, 802]

## Advantages

Very fast for integers
Excellent GPU utilization
Stable sorting
Predictable runtime
Parallelizable

## Disadvantages

Not ideal for floating-point values without transformation
Additional memory required
More complex GPU implementation

## Applications

GPU databases
Real-time analytics
Scientific computing
Big data processing
Parallel computing
Graphics pipelines
Sorting millions of integers
CUDA/OpenCL Adaptation

## Real GPU implementation generally uses:

CUDA kernels
Shared memory
Warp-level primitives
Parallel prefix scan

This project focuses on algorithm understanding and CPU-compatible implementations.

Example

Input:

[329, 457, 657, 839, 436, 720, 355]

Output:

[329, 355, 436, 457, 657, 720, 839]
Files
GPU-Radix-Sort.cpp
GPU-Radix-Sort.py
GPU-Radix-Sort.js
GPU-Radix-Sort.java

## Future Improvements
CUDA implementation
OpenCL version
Multi-GPU support
Parallel prefix optimization
Distributed radix sort
License
