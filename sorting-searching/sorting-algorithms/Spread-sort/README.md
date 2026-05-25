# SpreadSort

SpreadSort is a hybrid high-performance sorting algorithm that combines ideas from:

- Radix Sort
- Bucket Sort
- Comparison Sorting

It is designed to achieve:

```txt
Extremely fast sorting for integers and strings
````

especially when data is well distributed.

SpreadSort is known for outperforming traditional comparison sorts in many cases.

---

# Main Idea

Instead of comparing every element repeatedly:

```txt id="7x5xlq"
Spread elements into buckets based on value ranges
```

Then sort buckets individually.

The algorithm dynamically adapts based on:

* value distribution
* key ranges
* bucket sizes

---

# Why SpreadSort?

Traditional comparison sorting has a lower bound:

```txt id="q0kl4p"
O(n log n)
```

SpreadSort can approach:

```txt id="4f5u5n"
Near linear performance
```

for suitable datasets.

---

# Core Concept

Suppose we sort:

```txt id="cijh46"
[42, 7, 99, 15, 63, 28, 84]
```

SpreadSort:

1. Finds value range
2. Spreads elements into buckets
3. Recursively sorts buckets
4. Combines results

---

# Visual Example

## Input

```txt id="1j97qj"
[42, 7, 99, 15, 63, 28, 84]
```

---

# Step 1: Find Range

```txt id="yv3n36"
Min = 7
Max = 99
```

---

# Step 2: Spread Into Buckets

```txt id="58yx9s"
Bucket 1:
[7, 15]

Bucket 2:
[28, 42]

Bucket 3:
[63]

Bucket 4:
[84, 99]
```

---

# Step 3: Sort Buckets

Each bucket is sorted independently.

---

# Step 4: Merge

Final result:

```txt id="3e65sp"
[7, 15, 28, 42, 63, 84, 99]
```

---

# Hybrid Nature

SpreadSort combines:

| Technique          | Purpose              |
| ------------------ | -------------------- |
| Bucketing          | Distribution         |
| Radix-like ideas   | Fast grouping        |
| Comparison sorting | Small bucket sorting |

---

# Adaptive Behavior

SpreadSort changes behavior depending on:

* bucket size
* distribution quality
* recursion depth
* key characteristics

This makes it very efficient in practice.

---

# Complexity

Typical performance:

| Case    | Complexity |
| ------- | ---------- |
| Average | Near O(n)  |
| Worst   | O(n log n) |

Performance depends on key distribution.

---

# Space Complexity

Usually:

```txt id="lf6y9z"
O(n)
```

because buckets are used.

---

# Stability

SpreadSort is usually:

```txt id="1mp5cl"
Not Stable
```

unless specially implemented.

---

# Advantages

* Extremely fast for integers
* Good cache behavior
* Adaptive
* Near linear performance
* High practical performance

---

# Disadvantages

* Complex implementation
* Extra memory usage
* Distribution-sensitive
* Harder than standard sorting

---

# Real-World Uses

SpreadSort is useful in:

* high-performance systems
* scientific computing
* databases
* analytics engines
* large-scale numeric sorting

---

# Comparison

| Algorithm  | Average Complexity    |
| ---------- | --------------------- |
| QuickSort  | O(n log n)            |
| Merge Sort | O(n log n)            |
| Radix Sort | O(d × n)              |
| SpreadSort | Near O(n) in practice |

---

# Beginner-Friendly Explanation

Imagine organizing books by:

```txt id="c0jvzc"
Putting similar-sized books on nearby shelves
```

instead of comparing every book with every other book.

SpreadSort first groups similar values together.

Then each group becomes easy to sort.

---

# Simplified Educational Version

The implementations here demonstrate:

* range-based spreading
* bucket partitioning
* recursive bucket sorting
* adaptive sorting ideas

using simplified educational logic.
