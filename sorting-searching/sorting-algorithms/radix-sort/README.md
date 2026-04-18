
---

# 📁 `sorting-algorithms/radix-sort/README.md`

```md
# Radix Sort

## Overview

Radix Sort is a **non-comparison sorting algorithm** that sorts numbers digit by digit using another stable sorting algorithm (like Counting Sort).

---

## Quick Facts

- **Category:** Sorting Algorithm
- **Difficulty:** Advanced
- **Stable:** Yes
- **In-place:** No
- **Comparison Based:** No
- **Recursive:** No

---

## Intuition

Instead of comparing numbers directly, Radix Sort:
- sorts numbers digit by digit (from least significant digit to most significant)

---

## How It Works

1. Find the maximum number
2. Sort numbers based on each digit (units, tens, hundreds...)
3. Use Counting Sort for each digit
4. Repeat until all digits are processed

---

## Visual Explanation

Example: `[170, 45, 75, 90, 802, 24, 2, 66]`

```mermaid
flowchart TD
    A[Original Array] --> B[Sort by Units]
    B --> C[Sort by Tens]
    C --> D[Sort by Hundreds]
    D --> E[Sorted Array]