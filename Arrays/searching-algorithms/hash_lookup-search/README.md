# 🔑 Hash-based Lookup Algorithm

## 📖 Overview
Hash-based lookup trades memory for speed by preprocessing the array into a **hash table** (dictionary/map). This enables near-instantaneous `O(1)` average-case lookups at the cost of `O(n)` preprocessing time and `O(n)` auxiliary space. It's the standard approach in modern software when the array is queried repeatedly and order doesn't matter.

## ⚙️ How It Works
1. **Preprocessing Phase**: Iterate through the array once. For each element, compute its hash and store `(value → index)` in the hash table.
2. **Query Phase**: Compute the hash of the target value. Jump directly to the corresponding bucket.
3. **Collision Handling**: If collisions occur, modern hash tables use chaining or open addressing. The implementations above use language-native optimized hash maps.
4. Return the stored index if present, else `-1`.

## 📊 Complexity
| Phase         | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Preprocessing | O(n)            | O(n)             |
| Single Lookup | O(1) avg        | O(1)             |
| Worst Lookup  | O(n)            | O(n)             |

*Note: Worst case O(n) occurs only under extreme hash collisions or adversarial inputs, which are mitigated by modern randomized hash functions.*

## 🚀 How to Run
- **C++**: `g++ hash_lookup.cpp -o hash_lookup && ./hash_lookup`
- **Python**: `python hash_lookup.py`
- **JavaScript**: `node hash_lookup.js`

## 📝 Notes
- ✅ Ideal for **frequent queries** on static or semi-static data.
- ✅ Ignores array order; works on **unsorted** data.
- ⚠️ Not suitable for range queries, nearest-neighbor searches, or memory-constrained environments.
- 🔒 Duplicate values store the **first occurrence** index by default. Modify `if (!has)` logic to store last/nearest if needed.