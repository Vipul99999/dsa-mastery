# 🔍 Interpolation Search Algorithm

## 📖 Overview
Interpolation Search is an improved variant of Binary Search for **sorted arrays with uniformly distributed values**. Instead of always checking the middle element, it estimates the likely position of the target using a mathematical formula based on the values at the search boundaries.

## 🧮 The Formula
pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low])

This formula mimics how humans search a phonebook: if the target is closer to the high end, we jump further ahead rather than splitting exactly in half.

## ⚙️ How It Works
1. Check if `target` lies within the current `arr[low]` and `arr[high]`. If not, it's not in the array.
2. Calculate the estimated position `pos` using the interpolation formula.
3. Compare `arr[pos]` with `target`:
   - If equal → return `pos`.
   - If `arr[pos] < target` → search right subarray (`low = pos + 1`).
   - If `arr[pos] > target` → search left subarray (`high = pos - 1`).
4. Repeat until found or bounds cross.

## 📊 Complexity
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best          | O(1)            | O(1)             |
| Average       | O(log log n)    | O(1)             |
| Worst         | O(n)            | O(1)             |

*Note: Worst case occurs when values grow exponentially (e.g., `[1, 10, 100, 1000, ...]`), causing the formula to degenerate into linear probing.*

## 🚀 How to Run
- **C++**: `g++ interpolation_search.cpp -o interpolation_search && ./interpolation_search`
- **Python**: `python interpolation_search.py`
- **JavaScript**: `node interpolation_search.js`

## 📝 Notes
- ✅ Requires the array to be **sorted**.
- ✅ Extremely fast for **uniformly distributed** numeric data (e.g., sensor readings, evenly spaced IDs).
- ⚠️ Handles edge cases like `arr[low] == arr[high]` to prevent division-by-zero errors.
- ❌ Not recommended for non-uniform or heavily skewed datasets; Binary Search is safer in those cases.