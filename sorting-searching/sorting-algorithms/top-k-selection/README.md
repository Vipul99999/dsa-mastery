# Top-K Selection

Top-K Selection is used to find the:

- largest K elements  
OR  
- smallest K elements  

from a dataset without fully sorting the entire array.

---

## Example

```txt
Array:
[12, 5, 7, 19, 3, 25, 8]

K = 3

Top 3 largest:
[25, 19, 12]
```

---

## Why Top-K Selection?

Suppose you only need:

- top 10 scores  
- top 100 search results  
- top trending videos  
- highest salaries  
- most frequent words  

Sorting the entire array is unnecessary.  
Top-K Selection is faster.

---

## Main Idea

Instead of sorting all elements:

- **O(n log n)**

we maintain only K important elements.  
Usually done using:

- Min Heap  
- Max Heap  
- QuickSelect  
- Partial Sorting  

---

## Common Approaches

| Method              | Complexity       |
|---------------------|------------------|
| Full Sorting        | O(n log n)       |
| Min Heap            | O(n log k)       |
| QuickSelect         | Average O(n)     |
| Max Heap Extraction | O(n + k log n)   |

---

## Heap-Based Approach

For **Top K Largest**:

1. Create a min heap of size K  
2. Insert first K elements  
3. For remaining elements:  
   - if element > heap top  
     - remove smallest  
     - insert new element  

This keeps only the K largest values.

---

## Visual Example

Input:  
`[12, 5, 7, 19, 3, 25, 8]`  

K = 3  

Heap:  
`[5, 12, 7]`  

Read 19:  
Remove 5  
Heap: `[7, 12, 19]`  

Read 25:  
Remove 7  
Heap: `[12, 19, 25]`  

Read 8:  
Ignore  

Final Top 3:  
`[12, 19, 25]`

---

## Complexity

**Min Heap Approach**

| Operation          | Complexity       |
|--------------------|------------------|
| Build Heap         | O(k)             |
| Process Remaining  | O((n-k) log k)   |
| **Total**          | O(n log k)       |

**Space Complexity**: O(k)

---

## Stability

Top-K selection itself is not usually stable.  
Order may change depending on implementation.

---

## Advantages

- Faster than full sorting  
- Efficient for large datasets  
- Low memory usage  
- Very common in real systems  
- Useful for streaming data  

---

## Disadvantages

- Does not fully sort data  
- Heap implementation is more complex  
- Different methods behave differently  

---

## Real-World Uses

Top-K Selection is used in:

- Search engines  
- Recommendation systems  
- Trending systems  
- Leaderboards  
- Databases  
- Analytics  
- AI ranking systems  
- Streaming data processing  

---

## Largest vs Smallest

**Top K Largest**  
- Use Min Heap  

**Top K Smallest**  
- Use Max Heap  

---

## Example

Input:  
`[40, 10, 30, 20, 50]`  

K = 2  

Top 2 largest:  
`[50, 40]`
