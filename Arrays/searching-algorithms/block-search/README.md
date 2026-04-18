# 🧱 Block Search (Indexed Sequential Search)

## 📖 Overview
Block Search divides a **sorted array** into equal-sized blocks and maintains a separate **index table** containing the first (or maximum) value of each block. It performs a two-phase search:
1. **Index Phase**: Scans the index table to identify the correct block.
2. **Block Phase**: Performs a linear search within the identified block.

This approach bridges the gap between Linear Search and Binary Search, offering predictable performance and excellent cache locality. It's widely used in database indexing and file systems.

## ⚙️ How It Works
1. **Preprocessing**: Split array into `√n` blocks. Store the starting value of each block in `indexTable`.
2. **Index Search**: Traverse `indexTable` until `indexTable[i] > target`. The target must reside in block `i-1`.
3. **Block Search**: Perform a standard linear scan within the bounds of block `i-1`.
4. Return index if found, else `-1`.

## 📊 Complexity
| Phase         | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Preprocessing | O(n)            | O(√n)            |
| Single Search | O(√n)           | O(1)             |
| Best Case     | O(1)            | O(1)             |
| Worst Case    | O(√n)           | O(1)             |

## 🚀 How to Run
- **C++**: `g++ block_search.cpp -o block_search && ./block_search`
- **Python**: `python block_search.py`
- **JavaScript**: `node block_search.js`

## 📝 Notes
- ✅ Requires **sorted** array for correct index-based routing.
- ✅ Precomputes a lightweight `O(√n)` index, making it ideal for **repeated queries** on large datasets.
- ✅ Excellent **cache performance** due to localized block scanning.
- ⚖️ Slightly slower than Binary Search for single queries, but often faster in I/O-bound systems where jumping to arbitrary memory pages is costly.
- 🔧 Block size can be tuned based on hardware cache lines or storage sector sizes for maximum throughput.