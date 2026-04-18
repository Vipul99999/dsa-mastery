
---

## Full starter content for `bubble-sort/README.md`

```md
# Bubble Sort

## Overview
Bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order.

## Difficulty
Beginner

## Intuition
The largest unsorted element moves to the end of the array after each pass, like a bubble rising to the top.

## How It Works
1. Start from the first element
2. Compare adjacent elements
3. Swap if the left element is greater than the right element
4. Continue until the end of the array
5. Repeat until no swaps are needed

## Visual Explanation

### Pass 1

```mermaid
flowchart LR
    A[5 3 8 4 2] --> B[3 5 8 4 2]
    B --> C[3 5 8 4 2]
    C --> D[3 5 4 8 2]
    D --> E[3 5 4 2 8]

Example

Input:
[5, 3, 8, 4, 2]

Output:
[2, 3, 4, 5, 8]

Dry Run

Initial array:
[5, 3, 8, 4, 2]

Pass 1
Compare 5 and 3 → swap → [3, 5, 8, 4, 2]
Compare 5 and 8 → no swap
Compare 8 and 4 → swap → [3, 5, 4, 8, 2]
Compare 8 and 2 → swap → [3, 5, 4, 2, 8]
Pass 2
Compare 3 and 5 → no swap
Compare 5 and 4 → swap → [3, 4, 5, 2, 8]
Compare 5 and 2 → swap → [3, 4, 2, 5, 8]
Pass 3
Compare 3 and 4 → no swap
Compare 4 and 2 → swap → [3, 2, 4, 5, 8]
Pass 4
Compare 3 and 2 → swap → [2, 3, 4, 5, 8]
Algorithm
Compare adjacent elements
Swap when needed
After every pass, the largest remaining element settles at the end
Stop early if no swap happens in a full pass
Complexity Analysis
Case	Time Complexity
Best	O(n)
Average	O(n²)
Worst	O(n²)
Space Complexity

O(1)

Properties
Stable: Yes
In-place: Yes
Recursive: No
Advantages
Very easy to understand
Good for learning sorting basics
Easy to implement
Disadvantages
Too slow for large inputs
Not efficient for real-world large datasets
When to Use
For teaching and learning
For very small datasets
When simplicity matters more than performance