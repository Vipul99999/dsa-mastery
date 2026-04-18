# 03 — Amortized Analysis

Amortized analysis explains why some operations that are **occasionally expensive** can still be **cheap on average**.

This matters most for:

* dynamic arrays
* vectors
* array lists
* resizable buffers

---

# 1. The confusing part

Appending usually feels constant:

```python id="7b7kaf"
arr.append(10)
```

Most of the time:

🟩 fast
🟩 constant time
🟩 O(1)

But occasionally:

🟥 allocate new memory
🟥 copy all elements
🟥 free old memory

That single operation becomes:

```text id="l4g0lb"
O(n)
```

---

# 2. Example growth

Suppose capacity doubles.

Initial:

```text id="8v4v5r"
capacity = 1
[5]
```

Append again:

```text id="xgx0qc"
capacity = 2
[5][7]
```

Append third element:

```text id="5xkj0q"
Old:
[5][7]

New:
[5][7][9][ ]
```

Visual growth:

```text id="04md0i"
1 → 2 → 4 → 8 → 16
```

Formula:

$$
new_capacity = old_capacity \times 2
$$

new_capacity=old_capacity\times 2

---

# 3. Cost of each append

| Append # | Action        | Cost |
| -------- | ------------- | ---- |
| 1        | insert        | 1    |
| 2        | resize + copy | 2    |
| 3        | insert        | 1    |
| 4        | resize + copy | 4    |
| 5        | insert        | 1    |

Visual:

```text id="4qlm49"
append:
🟩 1
🟥 2
🟩 1
🟥 4
🟩 1
```

Some operations expensive.
Most are cheap.

---

# 4. Total work after n appends

For doubling growth:

```text id="z4m3rk"
1 + 2 + 4 + 8 + ... + n
```

This geometric series sums to:

$$
< 2n
$$

1+2+4+\dots+n<2n

Average cost:

$$
\frac{2n}{n}=2
$$

Which simplifies to:

```text id="3gx90p"
O(1)
```

---

# 5. Why it works

Most appends:

🟩 cheap
Only rare appends:

🟥 expensive

Visual:

```text id="fl9pq9"
append sequence

🟩 🟩 🟩 🟥 🟩 🟩 🟩 🟥 🟩 🟩 🟩
```

Average remains constant.

---

# 6. Aggregate method

Total cost of n operations:

$$
T(n)
$$

Average cost:

$$
\frac{T(n)}{n}
$$

If total work is linear:

$$
T(n)=O(n)
$$

Then average is:

$$
O(1)
$$

---

# 7. Accounting method intuition

Pretend each cheap append pays extra.

Each append pays:

```text id="4mz2fq"
Actual cost = 1
Charged cost = 3
```

Visual:

```text id="ykld1r"
🟩 insert = 1
🟦 saved credit = 2
```

Saved credit later pays for expensive copies.

---

# 8. Potential method intuition

Think of unused capacity as stored energy.

Visual:

```text id="nqivgw"
Capacity 8
Used 5

🟩🟩🟩🟩🟩🟦🟦🟦
```

Unused slots store "future work budget."

---

# 9. Why doubling matters

Bad growth strategy:

```text id="8i47zi"
+1 each time
```

Visual:

```text id="fk36qn"
1 → 2 → 3 → 4 → 5 → 6
```

Total copying becomes:

$$
1+2+3+...+n=O(n^2)
$$

🟥 very slow

Doubling:

```text id="3y1dx7"
1 → 2 → 4 → 8 → 16
```

Total copying:

```text id="hlgt0l"
O(n)
```

🟩 efficient

---

# 10. Real-world examples

Amortized analysis appears in:

* dynamic arrays
* hash tables
* garbage collectors
* rope buffers
* string builders

Examples:

* Java `ArrayList`
* Python `list`
* Rust `Vec`

---

# 11. Key takeaway

A single operation may be:

🟥 expensive

But over many operations:

🟩 average stays constant

Core result:

```text id="1wo6cl"
Dynamic array append = O(1) amortized
```
