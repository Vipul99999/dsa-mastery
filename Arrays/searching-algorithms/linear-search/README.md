# 🔍 Linear Search Algorithm

## 📖 Overview
Linear Search is the simplest searching algorithm. It sequentially checks each element of the array until a match is found or the entire array has been traversed.

## ⚙️ How It Works
1. Start from the first element.
2. Compare the current element with the target value.
3. If they match, return the current index.
4. If not, move to the next element.
5. If the end of the array is reached without a match, return `-1`.

## 📊 Complexity
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best          | O(1)            | O(1)             |
| Average       | O(n)            | O(1)             |
| Worst         | O(n)            | O(1)             |

## 🚀 How to Run
- **C++**: `g++ linear_search.cpp -o linear_search && ./linear_search`
- **Python**: `python linear_search.py`
- **JavaScript**: `node linear_search.js`

## 📝 Notes
- ✅ Works on **unsorted** arrays.
- ✅ Ideal for small datasets or when data is frequently modified.
- ❌ Inefficient for large arrays compared to logarithmic search algorithms.