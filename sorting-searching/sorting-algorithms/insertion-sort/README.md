# Insertion Sort

## Overview
Insertion Sort builds the final sorted array one element at a time by taking each element and inserting it into its correct position.

## Quick Facts
- Category: Sorting Algorithm
- Difficulty: Beginner
- Stable: Yes
- In-place: Yes
- Comparison Based: Yes
- Recursive: No

## Intuition
Think of arranging playing cards in your hand. You pick one card at a time and insert it into the correct place among the already arranged cards.

## How It Works
1. Assume the first element is already sorted
2. Pick the next element
3. Compare it with elements in the sorted part
4. Shift larger elements one position to the right
5. Insert the current element into its correct position

## Visual Explanation

Example: `[5, 3, 4, 1, 2]`

```mermaid
flowchart LR
    A[5 3 4 1 2] --> B[3 5 4 1 2]
    B --> C[3 4 5 1 2]
    C --> D[1 3 4 5 2]
    D --> E[1 2 3 4 5]

Algorithm
Start from the second element
Compare it with previous elements
Shift larger elements to the right
Insert into correct position
Complexity Analysis

Case	Time Complexity
Best	O(n)
Average	O(n²)
Worst	O(n²)
Space Complexity

O(1)