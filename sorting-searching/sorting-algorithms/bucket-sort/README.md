
---

# 📁 `sorting-algorithms/bucket-sort/README.md`

```md
# Bucket Sort

## Overview

Bucket Sort is a **distribution-based sorting algorithm** that divides elements into multiple buckets, sorts each bucket, and then combines them.

---

## Quick Facts

- **Category:** Sorting Algorithm
- **Difficulty:** Advanced
- **Stable:** Yes (depends on implementation)
- **In-place:** No
- **Comparison Based:** Partially
- **Recursive:** No

---

## Intuition

Bucket Sort works best when data is uniformly distributed.

It:
1. Divides data into buckets
2. Sorts each bucket individually
3. Combines results

---

## How It Works

1. Create empty buckets
2. Distribute elements into buckets
3. Sort each bucket
4. Concatenate all buckets

---

## Visual Explanation

Example: `[0.78, 0.17, 0.39, 0.26, 0.72]`

```mermaid
flowchart LR
    A[Input] --> B[Bucket Distribution]
    B --> C[Sort Each Bucket]
    C --> D[Merge Buckets]