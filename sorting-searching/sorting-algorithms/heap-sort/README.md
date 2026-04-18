# Heap Sort

## Overview

Heap Sort is a comparison-based sorting algorithm that uses a **binary heap** data structure.  
It first builds a **max heap** and then repeatedly extracts the largest element to sort the array.

---

## Quick Facts

- **Category:** Sorting Algorithm
- **Difficulty:** Intermediate
- **Stable:** No
- **In-place:** Yes
- **Comparison Based:** Yes
- **Recursive:** No (can be implemented iteratively)

---

## Intuition

A **max heap** ensures that the largest element is always at the root.

Heap Sort works by:
1. Building a max heap from the array
2. Swapping the root (largest element) with the last element
3. Reducing heap size and re-heapifying

This process continues until the array is sorted.

---

## How It Works

1. Build a max heap from the input array
2. Swap the first element with the last element
3. Reduce heap size
4. Heapify the root element
5. Repeat until the array is sorted

---

## Visual Explanation

Example: `[4, 10, 3, 5, 1]`

```mermaid
flowchart TD
    A[4 10 3 5 1] --> B[10 5 3 4 1]
    B --> C[1 5 3 4 10]
    C --> D[5 4 3 1 10]
    D --> E[4 1 3 5 10]
    E --> F[1 4 3 5 10]