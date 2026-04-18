# 🔺 Ternary Search Algorithm

## 📖 Overview
Ternary Search divides the sorted array into **three parts** using two midpoints (`mid1` and `mid2`). It compares the target with both midpoints to determine which third of the array to explore next. While theoretically elegant, it's rarely used in practice for standard arrays due to higher constant factors compared to Binary Search.

## ⚙️ How It Works
1. Initialize `left = 0`, `right = n - 1`
2. Calculate two division points:
   - `mid1 = left + (right - left) / 3`
   - `mid2 = right - (right - left) / 3`
3. Compare target:
   - If `target == arr[mid1]` or `arr[mid2]` → return index
   - If `target < arr[mid1]` → search left third (`right = mid1 - 1`)
   - If `target > arr[mid2]` → search right third (`left = mid2 + 1`)
   - Else → search middle third (`left = mid1 + 1`, `right = mid2 - 1`)
4. Repeat until `left > right`.

## 📊 Complexity
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best          | O(1)            | O(1)             |
| Average       | O(log₃ n)       | O(1)             |
| Worst         | O(log₃ n)       | O(1)             |

*Note: `log₃ n` is asymptotically `O(log n)`, but requires ~2 comparisons per iteration vs Binary Search's 1.*

## 🚀 How to Run
- **C++**: `g++ ternary_search.cpp -o ternary_search && ./ternary_search`
- **Python**: `python ternary_search.py`
- **JavaScript**: `node ternary_search.js`

## 📝 Notes
- ✅ Requires **sorted** array.
- ✅ Excellent for finding **extremum** (max/min) of unimodal functions.
- ❌ **Slower in practice** than Binary Search for standard arrays due to extra comparisons per iteration.
- 📐 Primarily used in competitive programming, mathematical optimization, or educational contexts to demonstrate divide-and-conquer variations.