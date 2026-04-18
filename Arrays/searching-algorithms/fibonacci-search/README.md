# 🐇 Fibonacci Search Algorithm

## 📖 Overview
Fibonacci Search is a comparison-based algorithm that uses **Fibonacci numbers** to divide the array into unequal parts. Unlike Binary Search which splits at the midpoint, Fibonacci Search uses ratios derived from the Fibonacci sequence to determine probe positions. It's particularly useful in environments where division/multiplication operations are expensive (e.g., embedded systems, older hardware).

## ⚙️ How It Works
1. Find the smallest Fibonacci number `F[m]` ≥ array length `n`.
2. Maintain three consecutive Fibonacci numbers: `F[m-2]`, `F[m-1]`, `F[m]`.
3. Compare target with element at `offset + F[m-2]`:
   - If `target > arr[i]` → move right, decrement `m` by 1, update `offset = i`
   - If `target < arr[i]` → move left, decrement `m` by 2
   - If equal → return index
4. Repeat until `F[m-1]` becomes 1.
5. Check the final remaining element if necessary.

## 📊 Complexity
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best          | O(1)            | O(1)             |
| Average       | O(log n)        | O(1)             |
| Worst         | O(log n)        | O(1)             |

## 🚀 How to Run
- **C++**: `g++ fibonacci_search.cpp -o fibonacci_search && ./fibonacci_search`
- **Python**: `python fibonacci_search.py`
- **JavaScript**: `node fibonacci_search.js`

## 📝 Notes
- ✅ Requires **sorted** array.
- ✅ Uses only **addition/subtraction** (no division or bit-shifting), making it ideal for hardware with slow multiplication/division units.
- ⚖️ Asymptotically identical to Binary Search `O(log n)`, but slightly fewer comparisons on average.
- ❌ Overhead of Fibonacci generation makes it marginally slower in practice on modern CPUs compared to Binary Search.