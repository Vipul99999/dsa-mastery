# 08 — Edge Cases

An **edge case** is a situation that happens at the boundary of normal input.

Beginners often write array code that works for:

🟩 normal input

but fails for:

🟥 unusual input

Examples:

* empty arrays
* one element
* last index
* negative index
* very large arrays

Learning these makes your code safer.

---

# 1. What is an edge case?

Suppose we reverse an array.

Normal:

```text id="n8k0s2"
[1,2,3,4]
```

Works fine.

But what about:

```text id="0drh9l"
[]
```

or:

```text id="u3l1w8"
[5]
```

These are edge cases.

---

# 2. Empty array

Array with no elements:

```text id="wr9b2x"
[]
```

Length:

```python id="j1n9q4"
len(arr) == 0
```

Visual:

```text id="ax5j2m"
No memory slots
┌ ┐
└ ┘
```

---

## Common bug

Bad code:

```python id="z3u7ma"
first = arr[0]
```

If array is empty:

🟥 error

Python raises:

```text id="5v8rk7"
IndexError
```

---

## Safer approach

```python id="r4g0q9"
if len(arr) > 0:
    first = arr[0]
```

---

# 3. Single element array

Example:

```text id="lt6z4v"
[7]
```

Visual:

```text id="z3kqvw"
┌───┐
│ 7 │
└───┘
```

Index:

```text id="f0nw78"
arr[0]
```

Only one valid position.

---

## Common mistake

Loop:

```python id="u94h1x"
for i in range(len(arr)-1):
```

For one element:

```text id="gb3lxt"
range(0)
```

Loop never runs.

Sometimes that's correct.
Sometimes it's a bug.

---

# 4. Off-by-one errors

Most common beginner mistake.

Array:

```text id="m1s2q8"
[10,20,30]
```

Valid indexes:

```text id="o2l3r7"
0   1   2
```

Visual:

```text id="w1q8tm"
Index:
 0   1   2
[10][20][30]
```

---

## Wrong

```python id="e6m5zs"
arr[3]
```

🟥 invalid

Because length is 3, but last index is:

```text id="uqx9pc"
len(arr) - 1
```

---

# 5. Correct rule

Remember:

```text id="g2m9qk"
Last index = length - 1
```

Example:

```text id="um5b4x"
length = 5
last index = 4
```

---

# 6. Loop boundaries

Bad loop:

```python id="p0t6kz"
for i in range(len(arr)+1):
```

Visual:

```text id="vl0sxp"
0 1 2 3  ← too far
```

---

Correct:

```python id="l3j9a7"
for i in range(len(arr)):
```

Visual:

```text id="u7d9ew"
0 1 2
```

🟩 safe

---

# 7. Negative indexes

Some languages allow them.

Python:

```python id="u4r1yt"
arr[-1]
```

Visual:

```text id="w9o5np"
[10][20][30]
          ↑
        last item
```

Result:

```text id="1xk8rm"
30
```

Language:
Python

---

## But C does not

In:
C

```c id="p7w4zx"
arr[-1]
```

🟥 dangerous memory access

---

# 8. Null or missing arrays

Sometimes the array itself is missing.

Example:

```python id="l8m1pr"
arr = None
```

Then:

```python id="r2w9fk"
len(arr)
```

causes:

🟥 error

Safer:

```python id="o5c8vq"
if arr is not None:
```

---

# 9. Very large arrays

Large arrays can cause overflow.

Formula:

$$
address = base + index \times size
$$

If index too large:

🟥 integer overflow

Visual:

```text id="o1v9mq"
999999999 × 8
```

Can exceed memory limits.

---

# 10. Sorting edge cases

Sorting:

Normal:

```text id="4l2g0v"
[3,1,2]
```

But also test:

```text id="ay6w4p"
[]
[5]
[1,1,1]
```

Why?

Because duplicates can break weak code.

---

# 11. Duplicate values

Array:

```text id="q8c3mk"
[4,4,4,4]
```

Visual:

```text id="t0v9ex"
[4][4][4][4]
```

Some algorithms accidentally:

🟥 infinite loop
🟥 wrong swaps

if duplicates are ignored.

---

# 12. First and last element bugs

Array:

```text id="v6j8q2"
[9,8,7,6]
```

Visual:

```text id="qq0n4v"
first           last
 ↓               ↓
[9][8][7][6]
```

Special positions often need careful handling.

---

# 13. Two-pointer edge case

Reverse logic:

```python id="y7n5bz"
while left < right:
```

Correct.

Bad:

```python id="l1m4ht"
while left <= right:
```

May process middle twice.

---

# 14. Common beginner checklist

Before writing array code ask:

✅ Can array be empty?
✅ Can it have one element?
✅ Is index valid?
✅ Are duplicates possible?
✅ Is input huge?

This prevents many bugs.

---

# 15. Visual memory reminder

```text id="u3q5fd"
length = 4

Index:
 0   1   2   3
[1][2][3][4]
```

Never access:

```text id="e5v7zu"
arr[4]
```

Because:

🟥 outside array

---

# 16. Real-world impact

Edge cases matter in:

* banking systems
* medical software
* operating systems
* games

Examples:
Microsoft
Google

Small bugs can become large failures.

---

# 17. Key takeaway

Most array bugs happen at boundaries.

Remember:

```text id="v2y6pd"
The middle is easy.
The edges break code.
```

Best habit:

```text id="h9n4q7"
Always test weird inputs.
```
