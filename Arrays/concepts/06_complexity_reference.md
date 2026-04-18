# 06 — Complexity Reference

This chapter helps beginners understand:

🟩 how fast array operations are
🟩 why some are cheap
🟥 why others are slow

---

# 1. What complexity means

Complexity describes:

* time used
* memory used

We usually write:

```text id="v9wnz5"
O(...)
```

Examples:

```text id="91e3w0"
O(1)  → constant
O(n)  → grows with input
O(n²) → much slower
```

---

# 2. Fastest operation: access

Example:

```python id="q2v70w"
arr[3]
```

Visual:

```text id="7hxnz7"
index 3
  ↓
[10][20][30][40][50]
            ↑
```

CPU jumps directly.

Complexity:

```text id="kckr8g"
O(1)
```

🟩 very fast

---

# 3. Searching

Find a value:

```python id="4vwgmv"
for x in arr:
```

Visual:

```text id="ht98ww"
[10][20][30][40][50]
 ↑   ↑   ↑
check each
```

Complexity:

```text id="g65gtq"
O(n)
```

Because each item may be checked.

---

# 4. Append at end

Dynamic array:

```python id="x8u4m5"
arr.append(60)
```

Usually:

🟩 O(1)

Sometimes resize:

🟥 O(n)

Average:

```text id="9qumgs"
O(1) amortized
```

---

# 5. Insert at front

Insert:

```text id="mgsq6u"
[10][20][30]
```

Insert `5`

Need shift:

```text id="8d0h9v"
[5][10][20][30]
```

Visual:

```text id="prj5z5"
20 moves right
30 moves right
```

Complexity:

```text id="smn82d"
O(n)
```

---

# 6. Delete from middle

Delete:

```text id="8c5nca"
[10][20][30][40]
```

Remove 20:

```text id="3fx44u"
[10][30][40]
```

Everything shifts left.

Complexity:

```text id="k8e8ma"
O(n)
```

---

# 7. Summary table

| Operation     | Time  | Why         |
| ------------- | ----- | ----------- |
| Access        | O(1)  | direct math |
| Search        | O(n)  | scan        |
| Append        | O(1)* | usually     |
| Insert middle | O(n)  | shifting    |
| Delete middle | O(n)  | shifting    |

* amortized

---

# 8. Space complexity

Extra memory used.

Example:

## In-place reverse

```text id="qccg2r"
O(1)
```

## Copy array

```python id="r7p9vo"
new_arr = arr.copy()
```

Complexity:

```text id="y05nku"
O(n)
```

---

# 9. Visual understanding

Small array:

```text id="hq8p4j"
[1][2][3][4][5]
```

Access index 4:

```text id="5i7bnm"
jump directly → 🟩
```

Insert at front:

```text id="yd0vbd"
shift all → 🟥
```

---

# 10. Why shifting is slow

Example:

Before:

```text id="ldvwwz"
[10][20][30][40]
```

Insert at front:

```text id="b5drgw"
[5][10][20][30][40]
```

Moves required:

```text id="1l4v5v"
40 moves
30 moves
20 moves
10 moves
```

Many changes = slower.

---

# 11. Beginner shortcut

Think:

🟩 direct = fast
🟥 moving = slow

Visual rule:

```text id="nkn3p2"
Read  → O(1)
Move  → O(n)
```

---

# 12. Common beginner confusion

People ask:

Why isn't insert O(1)?

Because arrays must remain contiguous.

Visual:

```text id="sx6wof"
Memory:
[10][20][30]
```

To insert in middle:

```text id="kmlz0p"
Need free slot
```

which means shifting.

---

# 13. Real-world meaning

Understanding complexity helps with:

* large datasets
* interview problems
* optimization
* performance tuning

Used heavily in:
Google scale systems.

---

# 14. Key takeaway

Remember this beginner rule:

```text id="uxtn67"
Access = fast
Modify middle = slower
```

Best mental model:

```text id="fowx1x"
arrays are fast because memory is ordered
```
