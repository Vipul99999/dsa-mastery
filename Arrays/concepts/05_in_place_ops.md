# 05 — In-Place Operations

An **in-place operation** changes an array **without creating another array**.

That means:

🟩 less memory used
🟩 often faster
🟩 more efficient

---

# 1. What “in-place” means

Imagine this array:

```text id="9m4h7a"
[ 1, 2, 3, 4, 5 ]
```

If we reverse it **in place**, we directly transform it into:

```text id="2zgrfd"
[ 5, 4, 3, 2, 1 ]
```

without creating:

```text id="k2r6jm"
new_array = [5,4,3,2,1]
```

---

# 2. Memory difference

## Extra memory version

```text id="44tq9r"
Original: [1][2][3][4][5]
New:      [5][4][3][2][1]
```

🟥 uses more memory

---

## In-place version

```text id="w6g19c"
Same array:
[1][2][3][4][5]
 ↓           ↓
swap values
```

🟩 same memory block reused

---

# 3. Two-pointer idea

Most in-place operations use:

* one pointer at the beginning
* one pointer at the end

Visual:

```text id="49hnq7"
left                right
 ↓                    ↓
[ 1 ][ 2 ][ 3 ][ 4 ][ 5 ]
```

Swap them.

---

# 4. Reverse example step-by-step

Start:

```text id="wtt7c4"
[ 1, 2, 3, 4, 5 ]
```

Swap first and last:

```text id="u7q4pq"
[ 5, 2, 3, 4, 1 ]
```

Move inward:

```text id="8m4v3v"
   ↓        ↓
[ 5, 2, 3, 4, 1 ]
```

Swap again:

```text id="x8t4uq"
[ 5, 4, 3, 2, 1 ]
```

Done.

---

# 5. Reverse code example

```python id="m7a8zu"
def reverse(arr):
    left = 0
    right = len(arr) - 1

    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
```

---

# 6. Why it works

Every step fixes two positions.

Visual:

```text id="93wd8l"
Before:
[ 1 ][ 2 ][ 3 ][ 4 ][ 5 ]

After first swap:
[ 5 ][ 2 ][ 3 ][ 4 ][ 1 ]
```

Middle stays same if odd length.

---

# 7. Space complexity

Extra memory approach:

```text id="ekf4z9"
O(n)
```

In-place approach:

```text id="xf6o0f"
O(1)
```

Meaning:

🟩 constant extra memory

---

# 8. Common in-place operations

## Reverse

```text id="3mjlwm"
[1,2,3] → [3,2,1]
```

## Rotate

```text id="mwmvxq"
[1,2,3,4] → [4,1,2,3]
```

## Partition

Move values based on a rule.

Example:

```text id="xjzbgh"
[4,1,7,2,9]
```

becomes:

```text id="o1jlwm"
[1,2,4,7,9]
```

or split around pivot.

---

# 9. Rotate example

Move last to front.

Before:

```text id="7zsl3v"
[1,2,3,4]
```

After:

```text id="4yav2l"
[4,1,2,3]
```

Visual:

```text id="cgr9g9"
last element
      ↓
[1][2][3][4]
```

---

# 10. Beginners' common mistakes

## Mistake 1 — forgetting boundaries

Wrong:

```python id="7w9h4r"
while left <= right:
```

Better:

```python id="mqnt6w"
while left < right:
```

---

## Mistake 2 — overwriting data

Bad order can lose values.

Need temporary swap.

Python handles safely:

```python id="q4x9t5"
a, b = b, a
```

---

# 11. Real-world use

In-place operations appear in:

* image editing
* sorting
* game boards
* memory-constrained devices

Example:
Apple and mobile devices often benefit from memory-efficient operations.

---

# 12. Key takeaway

In-place means:

```text id="3oecj4"
same array
less memory
same result
```

Best mental model:

```text id="xq2vh0"
modify what already exists
```
