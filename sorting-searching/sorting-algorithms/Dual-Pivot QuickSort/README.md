# Dual-Pivot QuickSort

Dual-Pivot QuickSort is an advanced version of the classic QuickSort algorithm.  
Instead of using a single pivot, it uses **two pivots** to partition the array into three sections:

- Elements less than `pivot1`
- Elements between `pivot1` and `pivot2`
- Elements greater than `pivot2`

---

## 📌 Idea

- **Normal QuickSort** → uses one pivot.  
- **Dual-Pivot QuickSort** → uses two pivots:
  - `pivot1 = first element`
  - `pivot2 = last element`
  - If `pivot1 > pivot2`, swap them.

The array is then divided into three parts:

```
[ smaller than pivot1 | between pivot1 and pivot2 | greater than pivot2 ]
```

---

## 🧩 Example

**Input:**
```
[24, 8, 42, 75, 29, 77, 38, 57]
```

**Choose pivots:**
```
pivot1 = 24
pivot2 = 57
```

**After partition:**
```
[8] [24] [42, 29, 38] [57] [75, 77]
```

**Recursive sort:**
```
[8] [24] [29, 38, 42] [57] [75, 77]
```

**Final result:**
```
[8, 24, 29, 38, 42, 57, 75, 77]
```

---

## ⚙️ Algorithm Steps

1. Choose two pivots.  
2. Ensure the left pivot is smaller than the right pivot.  
3. Partition the array into three sections:
   - Less than left pivot
   - Between both pivots
   - Greater than right pivot  
4. Recursively sort all three parts.  

---

## ⏱️ Complexity

| Case          | Time Complexity |
|---------------|-----------------|
| Best Case     | O(n log n)      |
| Average Case  | O(n log n)      |
| Worst Case    | O(n²)           |

**Space Complexity:** O(log n) (due to recursion)

---

## ⚖️ Stability

- Dual-Pivot QuickSort is **not stable**.  
- Equal elements may not retain their original order.

---

## ✅ Advantages

- Faster than traditional QuickSort in many practical cases  
- Efficient for primitive arrays  
- In-place sorting algorithm  
- Used in Java for sorting primitive arrays  

---

## ❌ Disadvantages

- Not stable  
- Worst-case time complexity is O(n²)  
- More complex than normal QuickSort  
- Performance depends on pivot selection  

---

## 📚 Use Cases

Dual-Pivot QuickSort is useful for:

- Sorting primitive data  
- Competitive programming  
- System-level sorting  
- Large numeric arrays  
- Learning advanced partitioning techniques  


