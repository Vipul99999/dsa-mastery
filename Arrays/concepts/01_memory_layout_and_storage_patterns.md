# 01 — Memory Layout and Storage Patterns

Arrays are powerful because their elements are stored in a **predictable memory layout**.

Understanding that layout explains:

* constant-time indexing
* traversal performance
* cache friendliness
* multidimensional storage
* language implementation differences

---

# 1. What memory looks like

Computer memory is a long sequence of bytes.

A simple integer array:

```c
int arr[5] = {10, 20, 30, 40, 50};
```

may look like:

```text
Address      Value
1000         10
1004         20
1008         30
1012         40
1016         50
```

Because an `int` is 4 bytes.

Visual:

```text
┌───────┬───────┬───────┬───────┬───────┐
│  10   │  20   │  30   │  40   │  50   │
└───────┴───────┴───────┴───────┴───────┘
1000    1004    1008    1012    1016
```

---

# 2. Why arrays are fast

The CPU can compute an element’s address directly.

Formula:

$$
address = base + (index \times element_size)
$$

Interactive formula:
address=base+(index\times element_size)

Example:

```text
base = 1000
index = 3
element_size = 4
```

```text
address = 1000 + (3 × 4) = 1012
```

That gives:

```text
arr[3] = 40
```

This is why array access is:

```text
O(1)
```

---

# 3. Contiguous memory

Array elements are stored one after another.

```text
Bad layout:
[10]      [20]         [30]

Good array layout:
[10][20][30]
```

Contiguous storage improves:

* CPU cache usage
* prefetching
* iteration speed

Visual:

```text
Memory
─────────────────────────────
|10|20|30|40|50|
─────────────────────────────
```

---

# 4. Alignment

Processors often prefer values aligned to certain boundaries.

For a 4-byte integer:

preferred addresses:

```text
1000 ✓
1004 ✓
1008 ✓
1012 ✓
```

Misaligned example:

```text
1001 ✗
1002 ✗
```

Misalignment can cause:

* slower reads
* extra instructions
* hardware faults on some systems

---

# 5. Element size matters

Different data types occupy different memory.

| Type   | Typical Size |
| ------ | ------------ |
| char   | 1 byte       |
| int    | 4 bytes      |
| double | 8 bytes      |

Example:

```c
double arr[3];
```

Visual:

```text
Base: 2000

arr[0] → 2000
arr[1] → 2008
arr[2] → 2016
```

Because each double uses 8 bytes.

---

# 6. Stack vs heap storage

Arrays can live in different memory regions.

## Stack

```c
int arr[5];
```

Visual:

```text
Stack
┌────────────┐
│ arr[4]     │
│ arr[3]     │
│ arr[2]     │
│ arr[1]     │
│ arr[0]     │
└────────────┘
```

Properties:

* automatic lifetime
* very fast allocation
* limited size

---

## Heap

```c
int* arr = malloc(5 * sizeof(int));
```

Visual:

```text
Stack                Heap
┌───────┐            ┌───────────────┐
│ ptr ─────────────► │10|20|30|40|50 │
└───────┘            └───────────────┘
```

Properties:

* flexible size
* manual/free or garbage collected
* slightly slower allocation

---

# 7. Row-major vs column-major storage

For a 2D array:

```text
1 2 3
4 5 6
```

---

## Row-major (C, C++, Python)

Stored as:

```text
1 2 3 4 5 6
```

Visual:

```text
Row 1 → [1][2][3]
Row 2 → [4][5][6]
```

---

## Column-major (Fortran, MATLAB)

Stored as:

```text
1 4 2 5 3 6
```

Visual:

```text
Col 1 → [1][4]
Col 2 → [2][5]
Col 3 → [3][6]
```

---

# 8. Spatial locality

Nearby memory tends to be loaded together.

Example:

```c
for (i = 0; i < n; i++)
    sum += arr[i];
```

Good locality because:

```text
arr[i], arr[i+1], arr[i+2]
```

are close together.

Visual:

```text
CPU cache line:
┌───────────────────────┐
│10│20│30│40│50│60│70│80│
└───────────────────────┘
```

---

# 9. Padding inside structures

Structures can include hidden bytes.

Example:

```c
struct Example {
    char a;
    int b;
};
```

Visual:

```text
Byte layout
┌───┬───┬───┬───┬────────────┐
│ a │pad│pad│pad│     b      │
└───┴───┴───┴───┴────────────┘
```

Padding ensures alignment.

---

# 10. Key takeaway

Arrays are efficient because:

✔ contiguous memory
✔ predictable offsets
✔ cache-friendly traversal
✔ simple address computation

Core idea:

```text
index → address → value
```

That simple relationship powers many high-performance systems.
