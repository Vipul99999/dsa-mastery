# Tree Sort

## Overview

Tree Sort is a comparison-based sorting algorithm that uses a Binary Search Tree.

It inserts all elements into a Binary Search Tree and then performs an inorder traversal to get the elements in sorted order.

---

## Quick Facts

- **Category:** Sorting Algorithm
- **Difficulty:** Intermediate
- **Stable:** No
- **In-place:** No
- **Comparison Based:** Yes
- **Recursive:** Yes

---

## Intuition

A Binary Search Tree follows this rule:

- values smaller than the root go to the left
- values greater than or equal to the root go to the right

When we perform inorder traversal on a Binary Search Tree, we visit elements in sorted order.

---

## How It Works

1. Create an empty Binary Search Tree
2. Insert every array element into the tree
3. Perform inorder traversal
4. Store visited values in an output array

---

