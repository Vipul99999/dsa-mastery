# External Merge Sort

External Merge Sort is a sorting algorithm used for sorting:

```txt
Very large data that cannot fit into RAM
````

It is one of the most important algorithms in:

* databases
* big data systems
* distributed systems
* file systems
* search engines

---

# Why External Merge Sort?

Normal sorting algorithms assume:

```txt
Entire data fits in memory
```

But sometimes data is huge:

```txt
100 GB
1 TB
10 TB
```

while RAM may be only:

```txt
8 GB
16 GB
32 GB
```

So data must be sorted using disk storage.

---

# Main Idea

External Merge Sort works in two phases:

---

# Phase 1: Create Sorted Chunks

1. Read small chunks from disk
2. Sort chunk in RAM
3. Write sorted chunk back to disk

These sorted chunks are called:

```txt
Runs
```

---

# Phase 2: Merge Runs

All sorted runs are merged together using:

```txt
K-way merge
```

until one fully sorted file remains.

---

# Visual Example

## Input File

```txt
8 3 7 4 9 2 6 1
```

Memory can hold only 4 numbers.

---

## Step 1: Create Runs

### Read first chunk

```txt
8 3 7 4
```

Sort in RAM:

```txt
3 4 7 8
```

Write:

```txt
run1.txt
```

---

### Read second chunk

```txt
9 2 6 1
```

Sort:

```txt
1 2 6 9
```

Write:

```txt
run2.txt
```

---

## Step 2: Merge Runs

Merge:

```txt
3 4 7 8
1 2 6 9
```

Final output:

```txt
1 2 3 4 6 7 8 9
```

---

# Algorithm Steps

## Phase 1

1. Read chunk from input file
2. Sort chunk in memory
3. Save sorted chunk to temporary file
4. Repeat until all data processed

---

## Phase 2

1. Open all sorted run files
2. Read smallest elements
3. Use min heap for k-way merge
4. Write smallest values to output file
5. Continue until all runs finish

---

# Complexity

Let:

```txt
n = total elements
m = memory size
```

## Sorting Runs

```txt
O(n log m)
```

## Merge Phase

```txt
O(n log k)
```

where:

```txt
k = number of runs
```

---

# Disk I/O Complexity

External Merge Sort is mainly optimized for:

```txt
Disk reads and writes
```

because disk access is much slower than RAM.

---

# Space Complexity

```txt
O(m)
```

for in-memory chunk sorting.

Additional disk space is needed for temporary files.

---

# Stability

External Merge Sort is usually:

```txt
Stable
```

if merge operations are implemented carefully.

---

# Advantages

* Can sort extremely large files
* Used in real databases
* Sequential disk access is efficient
* Scales well
* Works with limited RAM

---

# Disadvantages

* Slower than in-memory sorting
* Requires temporary files
* Heavy disk usage
* More complex implementation
* File handling overhead

---

# Real-World Uses

External Merge Sort is used in:

* database systems
* Hadoop
* Spark
* MapReduce
* search engines
* log processing
* big data analytics

---

# Beginner-Friendly Explanation

Imagine sorting millions of books.

You cannot place all books on one table.

So you:

1. Sort small piles separately
2. Merge sorted piles together

That is exactly how External Merge Sort works.

---

# Simplified Educational Version

The implementations here demonstrate:

* chunk-based sorting
* temporary sorted runs
* merging sorted runs

using simplified file handling for learning purposes.
