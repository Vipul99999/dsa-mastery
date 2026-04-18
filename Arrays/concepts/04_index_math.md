# 04 — Index Math

Index math explains how an array converts an index into a memory address.

This is why arrays support:

🟩 constant-time access

---

# 1. Basic address formula

For a 1D array:

$$
address = base + (index \times element_size)
$$

address=base+(index\times element_size)

Where:

* `base` = starting address
* `index` = position
* `element_size` = bytes per element

---

# 2. Example

Array:

```c id="dr9gq5"
int arr[5];
```

Assume:

```text id="8ylpjz"
base = 1000
element_size = 4
```

Then:

```text id="q8fxg6"
arr[0] → 1000
arr[1] → 1004
arr[2] → 1008
arr[3] → 1012
```

Visual:

```text id="y43qzv"
┌────┬────┬────┬────┬────┐
│0   │1   │2   │3   │4   │
└────┴────┴────┴────┴────┘
1000 1004 1008 1012 1016
```

---

# 3. Why O(1)

The CPU computes directly.

No searching.

Visual:

```text id="m5vpl7"
index 3
   ↓
1000 + (3×4)
   ↓
1012
```

One calculation only.

🟩 O(1)

---

# 4. 2D arrays in memory

Matrix:

```text id="grdcqn"
1 2 3
4 5 6
```

Stored in row-major:

```text id="e4xk6r"
[1][2][3][4][5][6]
```

---

# 5. 2D offset formula

For:

```text id="0rvr2m"
rows × cols
```

Formula:

$$
offset = row \times cols + col
$$

offset=row\times cols+col

Address:

$$
address = base + (offset \times element_size)
$$

---

# 6. Example 2D

Matrix:

```text id="bgb7w9"
3 columns
```

Find:

```text id="s8b32j"
arr[1][2]
```

Compute:

$$
offset = 1\times3+2=5
$$

offset=1\times3+2=5

So it's the 6th element.

Visual:

```text id="2zc7pi"
Matrix:
[1][2][3]
[4][5][6]
        ↑
```

---

# 7. Column-major systems

Some languages store by columns.

Example languages:

* MATLAB
* Fortran

Formula:

$$
offset = col \times rows + row
$$

offset=col\times rows+row

---

# 8. 3D arrays

For dimensions:

```text id="m4jwwf"
X × Y × Z
```

Formula:

$$
index=((x\times Y)+y)\times Z+z
$$

index=((x\times Y)+y)\times Z+z

Visual:

```text id="6zcdg6"
layer → row → column
```

---

# 9. Stride

Stride = bytes between adjacent elements.

Example:

```text id="ev6cmk"
int = 4 bytes
```

Stride:

```text id="r1xfz0"
4 bytes
```

Visual:

```text id="9lqprv"
1000 → 1004 → 1008 → 1012
```

For rows:

```text id="lfm8kx"
row_stride = cols × element_size
```

---

# 10. Common mistakes

🟥 Off-by-one:

```c id="8lr1u2"
arr[n]
```

Valid range:

```text id="7u5jye"
0 ... n-1
```

🟥 Overflow:

```c id="m7xqsa"
index * element_size
```

for huge arrays may overflow integer types.

---

# 11. Why index math matters

Used in:

* image processing
* matrices
* databases
* game grids
* tensors

Example:
NVIDIA GPUs rely heavily on index math.

---

# 12. Key takeaway

Arrays work because:

```text id="m6sz2t"
index → offset → address → value
```

That direct mapping makes array access extremely efficient.
