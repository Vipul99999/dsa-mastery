# Branchless Sorting

Branchless Sorting is a sorting technique that tries to reduce or eliminate:

```txt
if-else branches
````

during comparisons and swaps.

Instead of using traditional branching:

```cpp
if (a > b)
    swap(a, b);
```

branchless sorting uses arithmetic, bitwise operations, masks, or conditional moves.

---

# Why Branchless Sorting?

Modern CPUs use:

* branch prediction
* instruction pipelines
* speculative execution

Frequent unpredictable branches can slow down execution.

Branchless algorithms help CPUs run more efficiently.

---

# Main Idea

Traditional comparison:

```cpp
if (a > b)
    swap(a, b);
```

Branchless style:

```cpp
minValue = min(a, b)
maxValue = max(a, b)

a = minValue
b = maxValue
```

No explicit branch is needed.

---

# Visual Example

## Normal Sorting

```txt
Compare 8 and 3

if 8 > 3:
    swap
```

CPU may mispredict the branch.

---

## Branchless Sorting

```txt
min = 3
max = 8

Store:
[3, 8]
```

No branch decision needed.

---

# Common Techniques

Branchless sorting often uses:

* min/max operations
* bitwise masks
* conditional move instructions
* SIMD compare-and-swap
* sorting networks

---

# Example Compare-and-Swap

Traditional:

```cpp
if (x > y)
    swap(x, y);
```

Branchless:

```cpp
small = min(x, y)
large = max(x, y)

x = small
y = large
```

---

# Where Branchless Sorting Is Used

Branchless techniques are useful in:

* high-performance systems
* game engines
* SIMD sorting
* GPU sorting
* databases
* low-latency systems
* CPU optimization
* vectorized algorithms

---

# Sorting Networks

Many branchless algorithms are based on:

```txt
Sorting Networks
```

Examples:

* Bitonic Sort
* Odd-Even Merge Sort
* Bose-Nelson Network

These use fixed compare-and-swap patterns.

---

# Complexity

Complexity depends on the base algorithm.

Examples:

| Algorithm               | Complexity               |
| ----------------------- | ------------------------ |
| Branchless Bubble Style | O(n²)                    |
| Bitonic Sort            | O(log² n) parallel depth |
| Branchless QuickSort    | O(n log n) average       |

---

# Space Complexity

Usually:

```txt
O(1)
```

for in-place implementations.

---

# Stability

Most branchless sorting algorithms are:

```txt
Not Stable
```

unless specifically designed otherwise.

---

# Advantages

* Reduces branch misprediction
* Better CPU pipeline usage
* Good for SIMD/vectorization
* Useful for parallel systems
* Faster for predictable hardware execution

---

# Disadvantages

* Harder to understand
* More low-level optimization knowledge needed
* Sometimes less readable
* Can increase instruction count
* Performance gain depends on hardware

---

# Beginner-Friendly Explanation

Think of normal sorting like this:

```txt
CPU asks:
"Should I swap?"
```

Branchless sorting tries to avoid asking.

Instead:

```txt
CPU directly computes:
small value
large value
```

This reduces decision-making overhead.

---

# Example Used Here

The implementations in this folder demonstrate:

* branchless compare-and-swap
* min/max-based swapping
* branchless bubble-sort style logic

These are educational examples for understanding branchless ideas.

