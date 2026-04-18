# Selection Sort

## Overview
Selection Sort is a simple sorting algorithm that repeatedly finds the smallest element from the unsorted part of the array and places it at the beginning.

## Quick Facts
- Category: Sorting Algorithm
- Difficulty: Beginner
- Stable: No
- In-place: Yes
- Comparison Based: Yes
- Recursive: No

## Intuition
Divide the array into two parts:
- sorted part
- unsorted part

In every step, pick the minimum element from the unsorted part and move it to the correct position in the sorted part.

## How It Works
1. Start from index `0`
2. Find the smallest element in the remaining array
3. Swap it with the current index
4. Move to the next index
5. Repeat until the array is sorted

## Visual Explanation

### Example
Array: `[64, 25, 12, 22, 11]`

### Pass 1
Find minimum in entire array → `11`

```mermaid
flowchart LR
    A[64 25 12 22 11] --> B[11 25 12 22 64]