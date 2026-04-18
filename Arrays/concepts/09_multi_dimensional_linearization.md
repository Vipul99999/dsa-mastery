# 09 — Multi-Dimensional Linearization

At first, a 2D array looks like a grid.

Example:

```text id="k9d3wa"
[ [1, 2, 3],
  [4, 5, 6] ]
```

It feels like rows and columns.

But inside memory, the computer usually stores it as:

```text id="f2m8zp"
[1][2][3][4][5][6]
```

That process is called:

```text id="p8x4mr"
linearization
```

Meaning:

🟦 multi-dimensional data
becomes
🟩 one-dimensional memory

---

# 1. Why this happens

Memory itself is linear.

It looks like a long line:

```text id="t4n9qu"
1000 → 1004 → 1008 → 1012 → ...
```

The CPU only understands:

```text id="n7y2kg"
one address after another
```

So even a matrix must be flattened.

---

# 2. Visual example

2 rows × 3 columns:

```text id="h3q8mf"
Row 0: [1][2][3]
Row 1: [4][5][6]
```

Visual grid:

```text id="z0m7vw"
      col
       0  1  2
row 0 [1][2][3]
row 1 [4][5][6]
```

Stored in memory as:

```text id="u6k1px"
[1][2][3][4][5][6]
```

---

# 3. Row-major order

Most languages store rows first.

Languages:

* C
* C++
* Python

Storage order:

```text id="m5w8zt"
row 0 → row 1 → row 2
```

Visual:

```text id="w2f6qa"
Grid:
[1][2][3]
[4][5][6]

Memory:
[1][2][3][4][5][6]
```

---

# 4. Index formula for 2D arrays

To find:

```text id="r9x7cd"
arr[row][col]
```

Use:

$$
offset = row \times cols + col
$$

offset=row\times cols+col

Where:

* `row` = row number
* `col` = column number
* `cols` = total columns

---

# 5. Example step-by-step

Matrix:

```text id="j8s2vn"
[1][2][3]
[4][5][6]
```

Find:

```text id="v5n4lr"
arr[1][2]
```

Meaning:

* row = 1
* col = 2
* cols = 3

Compute:

$$
offset = 1 \times 3 + 2 = 5
$$

offset=1\times3+2=5

Memory:

```text id="g1z9mb"
Index:
0 1 2 3 4 5
[1][2][3][4][5][6]
               ↑
```

Result:

```text id="w7m2hq"
6
```

---

# 6. Address calculation

After offset:

$$
address = base + offset \times element_size
$$

address=base+offset\times element_size

Example:

```text id="p4w8zc"
base = 1000
offset = 5
size = 4
```

Compute:

```text id="m3k6qy"
1000 + (5 × 4) = 1020
```

---

# 7. Column-major order

Some systems store columns first.

Languages/tools:

* MATLAB
* Fortran

Visual:

Grid:

```text id="c6j5xt"
[1][2][3]
[4][5][6]
```

Memory becomes:

```text id="s8u2kw"
[1][4][2][5][3][6]
```

Because columns are stored first.

---

# 8. Column-major formula

Formula:

$$
offset = col \times rows + row
$$

offset=col\times rows+row

Different formula because storage order differs.

---

# 9. Why this matters

Wrong assumption can cause:

🟥 slow code
🟥 wrong indexing
🟥 bugs

Example:
reading by wrong order hurts cache performance.

---

# 10. 3D arrays

A 3D array can be imagined like layers.

Visual:

```text id="a0n3rp"
Layer 0
[1][2]
[3][4]

Layer 1
[5][6]
[7][8]
```

Stored as:

```text id="k7v2md"
[1][2][3][4][5][6][7][8]
```

Still one long block.

---

# 11. 3D formula

For:

```text id="u4j6cy"
arr[x][y][z]
```

Formula:

$$
index=((x\times Y)+y)\times Z+z
$$

index=((x\times Y)+y)\times Z+z

Where:

* X = depth
* Y = rows
* Z = columns

---

# 12. Beginner intuition

Think of shelves.

Visual:

```text id="e8x4mv"
Bookshelf:
shelf → row → book
```

Computer converts that to:

```text id="r7k1dp"
single counting number
```

Example:

```text id="q1w5zv"
book #17
```

That number becomes memory offset.

---

# 13. Flattening manually

Sometimes we intentionally flatten arrays.

Example:

```python id="b6j4yn"
matrix = [
 [1,2,3],
 [4,5,6]
]
```

Flatten:

```python id="v8r3qo"
flat = [1,2,3,4,5,6]
```

Useful for:

* graphics
* machine learning
* game maps

---

# 14. Why GPUs use this

Graphics hardware:
NVIDIA

often stores image pixels in linear memory.

Example image:

```text id="h5n8xy"
R G B R G B R G B
```

Linear storage is faster for hardware.

---

# 15. Common beginner mistakes

Mistake:

Wrong formula

```text id="y2p4wr"
row + col
```

Correct:

```text id="x6t8mn"
row × cols + col
```

Without multiplying, index becomes wrong.

---

# 16. Visual summary

2D grid:

```text id="o4q9zl"
[1][2][3]
[4][5][6]
```

Linear memory:

```text id="m1f7ks"
0 1 2 3 4 5
[1][2][3][4][5][6]
```

Mapping:

```text id="l8z2cw"
arr[1][1] → 4
```

because:

```text id="n3w7qv"
1×3+1 = 4th element
```

---

# 17. Key takeaway

The computer sees:

```text id="d9x5bf"
all arrays as one line of memory
```

Multi-dimensional arrays are just:

```text id="f7k4qm"
smart index math
```

That is the secret behind matrix storage.
