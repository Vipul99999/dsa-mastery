# 🦘 Jump Search Algorithm

## 📖 Overview
Jump Search is an algorithm designed for **sorted arrays**. It improves upon Linear Search by jumping ahead by fixed steps (typically `√n`) and then performing a linear search within the identified block. It's particularly useful when jumping backward is expensive (e.g., in linked lists or certain external storage systems), though it's less efficient than Binary Search for pure arrays.

## ⚙️ How It Works
1. Calculate step size: `step = √n`
2. Jump forward by `step` until `arr[step] >= target` or end of array.
3. Once the correct block is identified, perform a **linear search** between `prev_step` and `current_step`.
4. Return index if found, else `-1`.

## 📊 Complexity
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best          | O(1)            | O(1)             |
| Average       | O(√n)           | O(1)             |
| Worst         | O(√n)           | O(1)             |

## 🚀 How to Run
- **C++**: `g++ jump_search.cpp -o jump_search && ./jump_search`
- **Python**: `python jump_search.py`
- **JavaScript**: `node jump_search.js`

## 📝 Notes
- ✅ Requires **sorted** array.
- ✅ Optimal step size is mathematically proven to be `√n`.
- ✅ Useful when backward traversal is costly or restricted.
- ❌ Slower than Binary Search `O(log n)` for large arrays.