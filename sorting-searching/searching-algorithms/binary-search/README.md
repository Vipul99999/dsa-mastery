# 🔍 Binary Search Algorithm

## 📖 Overview
Binary Search is an efficient algorithm for finding an item in a **sorted** array. It repeatedly divides the search interval in half, drastically reducing the number of comparisons needed.

## ⚙️ How It Works
1. Initialize `left = 0` and `right = n - 1`.
2. Calculate the middle index: `mid = left + (right - left) / 2`.
3. Compare `arr[mid]` with the target:
   - If equal → return `mid`.
   - If `arr[mid] < target` → search right half (`left = mid + 1`).
   - If `arr[mid] > target` → search left half (`right = mid - 1`).
4. Repeat until `left > right`. If not found, return `-1`.

## 📊 Complexity
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best          | O(1)            | O(1)             |
| Average       | O(log n)        | O(1)             |
| Worst         | O(log n)        | O(1)             |

## 🚀 How to Run
- **C++**: `g++ binary_search.cpp -o binary_search && ./binary_search`
- **Python**: `python binary_search.py`
- **JavaScript**: `node binary_search.js`

## 📝 Notes
- ✅ Requires the array to be **sorted** beforehand.
- ✅ Highly efficient for large, static datasets.
- ❌ Overhead of sorting makes it unsuitable for frequently updated arrays unless maintained in sorted order.
- 🔒 The `mid` calculation uses `left + (right - left) / 2` to prevent integer overflow in C++/JS.