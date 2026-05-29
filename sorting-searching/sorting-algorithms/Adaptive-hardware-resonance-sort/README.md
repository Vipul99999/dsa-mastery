# Adaptive Hardware Resonance Sort (AHRS)

A self-optimizing hybrid sorting framework that dynamically selects the most suitable sorting strategy based on:

* Dataset characteristics
* Memory availability
* Hardware profile
* Cache approximations
* Duplicate density
* Sortedness
* Stability requirements
* Latency constraints

AHRS combines classical algorithms with adaptive runtime decision-making to create a practical architecture-aware sorting engine.

---

# Features

## Adaptive Strategy Selection

AHRS analyzes runtime conditions and automatically selects among:

| Strategy             | Best For                                |
| -------------------- | --------------------------------------- |
| Insertion Sort       | Small or nearly sorted arrays           |
| Three-Way Quick Sort | Duplicate-heavy datasets                |
| Radix Sort           | Large integer arrays with bounded range |
| Resonance Wave Sort  | Semi-ordered stable datasets            |
| Stable Merge Sort    | Stability-critical workloads            |
| std::sort            | Low-latency fallback                    |

---

## Hardware-Aware Decisions

The framework estimates:

* CPU core count
* Cache sizes
* Memory budget
* Dataset memory footprint

This allows AHRS to avoid inefficient algorithms under constrained memory conditions.

---

## Data-Aware Optimization

AHRS profiles input data before sorting:

* Sortedness estimation
* Duplicate ratio
* Integer range analysis
* Non-negative detection
* Data size evaluation

---

## Stability-Aware Execution

Supports explicit constraints:

```cpp
SortConstraints constraints;
constraints.requireStable = true;
constraints.lowLatency = false;
```

---

## Resonance Wave Sort

AHRS introduces a custom experimental algorithm:

### Resonance Wave Sort

The algorithm:

1. Detects naturally ordered waves/runs
2. Groups monotonic segments
3. Reorders wave blocks
4. Applies stable refinement

This is inspired by:

* TimSort run detection
* Cache locality principles
* Natural ordering exploitation

---

# Architecture Overview

```text
                +----------------------+
                |     Input Dataset    |
                +----------+-----------+
                           |
                           v
                +----------------------+
                |   Data Profiler      |
                |----------------------|
                | Sortedness           |
                | Duplicate Ratio      |
                | Value Range          |
                | Distribution         |
                +----------+-----------+
                           |
                           v
                +----------------------+
                | Hardware Profiler    |
                |----------------------|
                | CPU Cores            |
                | Cache Estimates      |
                | Memory Budget        |
                +----------+-----------+
                           |
                           v
                +----------------------+
                | Strategy Selector    |
                +----------+-----------+
                           |
          +----------------+----------------+
          |                |                |
          v                v                v
  Insertion Sort   Radix Sort   Three-Way Quick
          |
          v
  Resonance Wave Sort
          |
          v
    Stable Merge Sort
```

---

# Build Instructions

## Linux / macOS

```bash
g++ -std=c++20 -O2 adaptive_hardware_resonance_sort.cpp -o ahrs
./ahrs
```

---

## Windows (MinGW)

```bash
g++ -std=c++20 -O2 adaptive_hardware_resonance_sort.cpp -o ahrs.exe
ahrs.exe
```

---

# Example Output

```text
========== Adaptive Hardware Resonance Sort ==========
Elements:          21
Sortedness:        0.55
Duplicate Ratio:   0.38
Value Range:       89
CPU Cores:         8
L3 Cache (bytes):  8388608
Memory Budget:     536870912
Selected Strategy: Three-Way Quick Sort

Sorted Data:
[1, 2, 2, 2, 5, 5, 5, 9, 9, 12, 12, 12, 23, ...]
```

---

# Sorting Strategy Logic

## 1. Insertion Sort

Chosen when:

* Dataset size ≤ 64
* Very high sortedness
* Fits inside cache efficiently

### Advantages

* Minimal overhead
* Cache friendly
* Excellent for tiny datasets

---

## 2. Three-Way Quick Sort

Chosen when:

* Duplicate ratio is high
* General-purpose fast sorting needed

### Advantages

* Efficient partitioning
* Handles repeated values well
* Reduced recursion overhead

---

## 3. Radix Sort

Chosen when:

* Integer dataset
* Non-negative values
* Bounded value range
* Large dataset size

### Advantages

* Linear-like complexity
* Very fast on structured integer data

### Limitations

* Integer-only optimization
* Additional memory usage

---

## 4. Resonance Wave Sort

Chosen when:

* Dataset already contains ordered regions
* Moderate sortedness
* Duplicate-heavy stable workloads

### Core Concept

AHRS attempts to exploit naturally ordered "waves" already present in memory.

Example:

```text
[1 2 3] [0 4 5 6] [2 8 9]
```

Each wave is detected and merged intelligently.

### Goals

* Reduce unnecessary swaps
* Improve locality
* Leverage pre-existing order

---

## 5. Stable Merge Sort

Chosen when:

* Stable ordering required
* No specialized optimization applicable

Uses:

```cpp
std::stable_sort(...)
```

---

## 6. Low-Latency std::sort

Chosen when:

* Memory pressure is high
* Low latency requested explicitly

Uses:

```cpp
std::sort(...)
```

---

# Time Complexity

| Algorithm            | Average     | Worst      | Stable |
| -------------------- | ----------- | ---------- | ------ |
| Insertion Sort       | O(n²)       | O(n²)      | Yes    |
| Three-Way Quick Sort | O(n log n)  | O(n²)      | No     |
| Radix Sort           | O(nk)       | O(nk)      | Yes    |
| Resonance Wave Sort  | ~O(n log n) | O(n log n) | Yes    |
| Stable Merge Sort    | O(n log n)  | O(n log n) | Yes    |

---

# Data Profiling Metrics

## Sortedness

Computed as:

```text
ordered adjacent pairs / total adjacent pairs
```

Range:

```text
0.0 -> completely random
1.0 -> perfectly sorted
```

---

## Duplicate Ratio

Computed as:

```text
1 - unique_elements / total_elements
```

Higher values indicate:

* heavy duplication
* clustered datasets
* better suitability for 3-way partitioning

---

## Value Range

For integer datasets:

```text
max_value - min_value
```

Used for:

* Radix Sort feasibility
* Memory efficiency estimation

---

# Benchmark Utilities

Included benchmark datasets:

| Dataset         | Purpose                       |
| --------------- | ----------------------------- |
| Random Data     | General performance           |
| Nearly Sorted   | Adaptive optimization testing |
| Duplicate Heavy | Duplicate-aware performance   |

Example benchmark call:

```cpp
benchmark(
    "AHRS (Random)",
    [](vector<int>& v) {
        adaptiveHardwareResonanceSort(v, {}, false);
    },
    generateRandomData(100000)
);
```

---

# Example Usage

## Basic Usage

```cpp
vector<int> data = {5, 2, 8, 1, 9};

adaptiveHardwareResonanceSort(data);
```

---

## Stable Sorting

```cpp
SortConstraints constraints;
constraints.requireStable = true;

adaptiveHardwareResonanceSort(data, constraints);
```

---

## Low-Latency Mode

```cpp
SortConstraints constraints;
constraints.lowLatency = true;

adaptiveHardwareResonanceSort(data, constraints);
```

---

# Project Structure

```text
adaptive_hardware_resonance_sort.cpp
│
├── Utility Functions
├── Hardware Profiler
├── Data Profiler
├── Sorting Algorithms
├── Resonance Wave Engine
├── Strategy Selector
├── Benchmark Utilities
└── Dataset Generators
```

---

# Design Philosophy

Traditional sorting libraries usually use:

* One universal algorithm
* Static heuristics
* Minimal runtime adaptation

AHRS instead treats sorting as:

```text
Sorting Strategy = f(Data, Hardware, Constraints)
```

Where:

```text
S = f(D, H, C)
```

* D = Data profile
* H = Hardware profile
* C = Runtime constraints

---

# Potential Future Improvements

## Parallel Sorting

* Multi-threaded merge stages
* NUMA-aware partitioning
* Work-stealing schedulers

---

## SIMD Optimization

Potential acceleration using:

* AVX2
* AVX-512
* ARM NEON

---

## Machine-Learned Strategy Prediction

Replace heuristic rules with:

* Reinforcement learning
* Online profiling
* Performance history feedback

---

## External Memory Sorting

Support:

* SSD-backed datasets
* Streaming sort
* Out-of-core sorting

---

## GPU Offloading

Future support for:

* CUDA
* HIP
* OpenCL

---

# Limitations

Current implementation is:

* Experimental
* Heuristic-driven
* Approximate in hardware detection
* Single-threaded

Resonance Wave Sort is currently a research-oriented prototype rather than a mathematically proven optimal algorithm.

---

# Research Inspiration

AHRS draws inspiration from:

* TimSort
* Introsort
* Cache-aware algorithms
* Adaptive sorting theory
* Distribution-sensitive sorting
* Hardware-conscious computing

---

# Recommended Use Cases

AHRS performs best in:

* Analytics engines
* Database preprocessing
* Log aggregation systems
* Semi-ordered datasets
* Duplicate-heavy streams
* Runtime-adaptive infrastructure

---

# Verification

The framework validates correctness using:

```cpp
isSorted(data)
```

All benchmark executions automatically verify sorted order.

---

# Sample Benchmark Scenarios

```text
AHRS (Random)           -> 12034 us | Sorted: YES
AHRS (Nearly Sorted)    -> 1840 us  | Sorted: YES
AHRS (Duplicate Heavy)  -> 5021 us  | Sorted: YES
```

---

# Compiler Recommendations

Recommended compilers:

| Compiler | Version |
| -------- | ------- |
| GCC      | 11+     |
| Clang    | 14+     |
| MSVC     | VS2022+ |

---

# Optimization Flags

Recommended:

```bash
-O2
```

Optional advanced optimizations:

```bash
-O3 -march=native -flto
```

---

# License

MIT License

You are free to:

* Use
* Modify
* Distribute
* Research
* Benchmark
* Extend

with attribution.

---

# Final Notes

Adaptive Hardware Resonance Sort is not merely a sorting algorithm.

It is an experimental adaptive sorting framework exploring the idea that:

```text
The best sorting algorithm depends on
both the data and the machine executing it.
```

The project demonstrates how runtime introspection and hybrid execution models can improve general-purpose algorithmic systems.
