
---

# 📁 `sorting-algorithms/counting-sort/README.md`

```md
# Counting Sort

## Overview

Counting Sort is a **non-comparison sorting algorithm** that sorts elements by counting occurrences of each value.

It is efficient when the range of input values is small.

---

## Quick Facts

- **Category:** Sorting Algorithm
- **Difficulty:** Intermediate
- **Stable:** Yes
- **In-place:** No
- **Comparison Based:** No
- **Recursive:** No

---

## Intuition

Instead of comparing elements, Counting Sort:
1. Counts how many times each number appears
2. Uses this information to place elements in correct positions

---

## How It Works

1. Find the maximum value in the array
2. Create a count array
3. Store frequency of each element
4. Compute cumulative count
5. Place elements into output array

---

## Visual Explanation

Example: `[4, 2, 2, 8, 3, 3, 1]`

```mermaid
flowchart LR
    A[Input Array] --> B[Count Array]
    B --> C[Cumulative Count]
    C --> D[Sorted Output]