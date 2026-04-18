# 📈 Exponential Search Algorithm

## 📖 Overview
Exponential Search (also called Galloping Search or Doubling Search) is an algorithm for **sorted arrays** that works in two phases:
1. **Exponential Phase**: Finds a range where the target might exist by doubling the index (`1, 2, 4, 8, 16...`).
2. **Binary Search Phase**: Performs a standard binary search within that identified range.

It's highly efficient when the target is likely to be near the beginning of the array or when working with unbounded/infinite streams.

## ⚙️ How It Works
1. Check if `target` is at index `0`.
2. Start at index `i = 1`.
3. While `i < n` and `arr[i] <= target`, double `i` (`i *= 2`).
4. Once `arr[i] > target` or `i` exceeds bounds, perform binary search between `i/2` and `min(i, n-1)`.
5. Return index if found, else `-1`.

## 📊 Complexity
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best          | O(1)            | O(1)             |
| Average       | O(log n)        | O(1)             |
| Worst         | O(log n)        | O(1)             |

## 🚀 How to Run
- **C++**: `g++ exponential_search.cpp -o exponential_search && ./exponential_search`
- **Python**: `python exponential_search.py`
- **JavaScript**: `node exponential_search.js`

## 📝 Notes
- ✅ Requires **sorted** array.
- ✅ Extremely fast when target is near index `0`.
- ✅ Can be adapted for **unbounded/infinite arrays** where size isn't known upfront.
- 🔒 Uses iterative binary search to guarantee `O(1)` auxiliary space.
- ⚖️ Mathematically equivalent to Binary Search in worst-case asymptotic complexity, but often faster in practice for skewed distributions.