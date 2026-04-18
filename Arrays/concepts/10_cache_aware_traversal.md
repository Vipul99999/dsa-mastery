# 10 — Cache-Aware Traversal

Arrays can become much faster or slower depending on **how you walk through memory**.

Many beginners think:

```text id="r7m2qx"
all loops cost the same
```

But modern CPUs care about:

🟦 memory layout
🟦 cache lines
🟦 locality
🟦 prefetching

Understanding this can dramatically improve performance.

---

# 1. Why memory speed matters

CPU is extremely fast.

RAM is much slower.

Visual:

```text id="j3x9bv"
CPU speed      ⚡⚡⚡⚡⚡
RAM speed      ⚡
```

Because of this, processors use small fast memory called:

```text id="p4n8tz"
cache
```

---

# 2. What cache is

Cache is tiny memory close to CPU.

Visual:

```text id="m5q7dw"
CPU ⇄ Cache ⇄ RAM
```

Sizes usually:

| Level | Typical size | Speed   |
| ----- | ------------ | ------- |
| L1    | very small   | fastest |
| L2    | medium       | fast    |
| L3    | larger       | slower  |

Deep concept:
Modern CPUs often have:

* private L1
* private L2
* shared L3

---

# 3. Why arrays benefit

Arrays are stored contiguously.

Visual:

```text id="k8w4cy"
Memory:
[1][2][3][4][5][6][7][8]
```

Cache loads a block called a:

```text id="g6v2sx"
cache line
```

Usually around:

```text id="s9q4pm"
64 bytes
```

Meaning several elements arrive together.

---

# 4. Cache line visualization

Example with integers (4 bytes each)

One cache line can hold:

```text id="v7f3bn"
16 integers
```

Visual:

```text id="y1k8qo"
Cache line:
[1][2][3][4][5][6][7][8]...[16]
```

So reading:

```text id="f2z9wr"
arr[0]
```

often loads:

```text id="4n6jpt"
arr[1], arr[2], arr[3] ...
```

for free.

---

# 5. Spatial locality

Spatial locality means:

```text id="e8m4kd"
nearby memory is likely used soon
```

Good loop:

```python id="a3t8mx"
for i in range(len(arr)):
    total += arr[i]
```

Visual:

```text id="u7p3lw"
[1][2][3][4][5]
 ↑  ↑  ↑  ↑
 nearby access
```

🟩 very cache friendly

---

# 6. Temporal locality

Temporal locality means:

```text id="w5c7zr"
recently used data may be used again
```

Example:

```python id="d2n9fy"
x = arr[5]
y = arr[5]
```

The second access may already be in cache.

🟩 faster

---

# 7. Bad traversal pattern

Example:

```python id="g4x1pc"
for i in range(0, len(arr), 100):
    total += arr[i]
```

Visual:

```text id="n6m8jq"
[1][2][3][4][5][6][7][8]
 ↑           ↑
 big jumps
```

Problems:

🟥 poor locality
🟥 wasted cache
🟥 slower performance

---

# 8. 2D array example

Matrix:

```text id="b5v9oa"
[1][2][3]
[4][5][6]
[7][8][9]
```

Stored row-major:

```text id="z4q7tw"
[1][2][3][4][5][6][7][8][9]
```

---

# 9. Good traversal order

Good:

```python id="m9w2kp"
for row in matrix:
    for value in row:
        process(value)
```

Visual:

```text id="h8x5fv"
→ → →
→ → →
→ → →
```

🟩 follows memory order

---

# 10. Bad traversal order

Bad:

```python id="f3k8rz"
for col in range(cols):
    for row in range(rows):
        process(matrix[row][col])
```

Visual:

```text id="q2c9yu"
↓ ↓ ↓
↓ ↓ ↓
↓ ↓ ↓
```

Memory jumps around.

🟥 slower

---

# 11. Why row-major matters

Formula:

$$
offset = row \times cols + col
$$

offset=row\times cols+col

Adjacent columns in same row are adjacent in memory.

That helps cache.

---

# 12. Cache miss

A cache miss means:

```text id="x8w4nj"
needed data is not in cache
```

CPU must fetch from RAM.

Visual:

```text id="r1m5qp"
CPU → cache ❌ → RAM → slow
```

Cache misses are expensive.

---

# 13. Cache hit

A cache hit means:

```text id="c6p9wd"
data already in cache
```

Visual:

```text id="o3t7yl"
CPU → cache ✓
```

Much faster.

---

# 14. Why beginners should care

Even simple code can improve.

Same logic:

```text id="v2n4qc"
same algorithm
same Big-O
different speed
```

Example:
Two O(n) loops can have very different runtime.

That surprises many beginners.

---

# 15. Deep concept: hardware prefetching

Modern CPUs predict access patterns.

If access looks sequential:

```text id="w9j6fr"
0 → 1 → 2 → 3
```

CPU may load future data early.

This is called:

```text id="u4k7mb"
prefetching
```

Result:

🟩 faster loops

---

# 16. Deep concept: false sharing

In multi-threaded programs, nearby memory can hurt performance.

Threads:

```text id="l3v8xp"
Thread A → arr[0]
Thread B → arr[1]
```

Same cache line.

Visual:

```text id="n8p5ya"
Cache line:
[A][B][ ][ ]
```

CPU cores fight over ownership.

This is called:

```text id="d7w2kz"
false sharing
```

Advanced but important.

---

# 17. Deep concept: loop tiling

Large matrices can exceed cache.

Instead of:

```text id="r6q4ws"
scan entire rows
```

Use smaller blocks.

Visual:

```text id="k5t9mj"
Large matrix
┌──┬──┐
│■■│■■│
├──┼──┤
│■■│■■│
└──┴──┘
```

This keeps data inside cache longer.

Called:

```text id="f8n3qy"
blocking / tiling
```

Used in:

* scientific computing
* graphics
* machine learning

Examples:
Intel
NVIDIA

---

# 18. Simple benchmark idea

Try these two loops:

```python id="m4v7qn"
for row:
    for col:
```

vs

```python id="p2x8df"
for col:
    for row:
```

Same work.

Different speed.

Because cache changes everything.

---

# 19. Beginner mental model

Think of a bookshelf.

Good:

```text id="x1w9pc"
read left to right
```

Bad:

```text id="q7m5vy"
jump shelf to shelf
```

CPU prefers predictable movement.

---

# 20. Practical rules

Best practices:

✅ access nearby elements together
✅ follow storage order
✅ avoid random jumps
✅ process in blocks for large data

---

# 21. Key takeaway

Arrays are fast not only because of:

```text id="w3n7lk"
O(1) indexing
```

but also because of:

```text id="e6k2pq"
cache-friendly memory access
```

Best beginner summary:

```text id="u8m4zr"
The order you read memory matters.
```

Best deeper summary:

```text id="b5q9xt"
Performance is often a hardware problem, not just an algorithm problem.
```
