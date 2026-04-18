# 07 — Language Behaviors

Arrays look similar in many languages:

```text id="v6d9f3"
[1, 2, 3]
```

But underneath, different languages handle arrays very differently.

Some languages use:

🟩 fixed arrays
🟩 dynamic arrays
🟩 bounds checking
🟩 automatic resizing

Understanding these differences helps you write better code.

---

# 1. Why language behavior matters

Two pieces of code may look similar:

Python:

```python id="ecw7x9"
arr.append(10)
```

C++:

```cpp id="x2tw1x"
vec.push_back(10);
```

Both add an element.

But internally:

* memory handling differs
* safety differs
* speed differs

---

# 2. C arrays

Language:
C

Example:

```c id="1z6fvy"
int arr[5] = {1,2,3,4,5};
```

Visual:

```text id="bg2g7x"
Memory
┌───┬───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ 4 │ 5 │
└───┴───┴───┴───┴───┘
```

Properties:

| Feature     | C    |
| ----------- | ---- |
| Fixed size  | Yes  |
| Fast        | Very |
| Safe        | No   |
| Auto resize | No   |

---

## Important

Accessing invalid index:

```c id="0e38vf"
arr[10]
```

can cause:

🟥 undefined behavior

Possible results:

* crash
* wrong data
* silent bug

---

# 3. C++ vector

Language:
C++

Example:

```cpp id="cb8dnx"
std::vector<int> vec = {1,2,3};
vec.push_back(4);
```

Visual:

```text id="y0ij0w"
Before:
[1][2][3]

After:
[1][2][3][4]
```

Properties:

| Feature | vector    |
| ------- | --------- |
| Dynamic | Yes       |
| Fast    | Yes       |
| Safer   | Better    |
| Resize  | Automatic |

---

## Capacity concept

```cpp id="odxljq"
vec.capacity()
vec.size()
```

Visual:

```text id="a0qvnd"
size = 3
capacity = 5

[1][2][3][ ][ ]
```

---

# 4. Java arrays

Language:
Java

Example:

```java id="pqzj9m"
int[] arr = {1,2,3};
```

Fixed size.

Visual:

```text id="mv6mva"
[1][2][3]
```

To grow dynamically Java often uses:

```java id="zmyq7w"
ArrayList<Integer>
```

---

## Safety

Invalid access:

```java id="5bn8mq"
arr[10]
```

causes:

```text id="5u79n3"
ArrayIndexOutOfBoundsException
```

🟩 safer than C

---

# 5. Python lists

Language:
Python

Example:

```python id="jlwm55"
arr = [1,2,3]
arr.append(4)
```

Looks like array, but actually dynamic.

Visual:

```text id="9pw2eu"
[1][2][3][4]
```

---

## Python stores references

Instead of storing values directly:

```text id="jx5i1v"
list → pointers → objects
```

Visual:

```text id="fx9jlb"
List:
[ • ][ • ][ • ]

Pointers:
 ↓    ↓    ↓
 1    2    3
```

Meaning:

* flexible
* slower than C arrays
* supports mixed types

---

## Mixed types allowed

```python id="egjlwm"
arr = [1, "hello", 3.14]
```

🟩 flexible
🟨 less memory efficient

---

# 6. JavaScript arrays

Language:
JavaScript

Example:

```javascript id="31fr0z"
let arr = [1,2,3];
arr.push(4);
```

Visual:

```text id="rz12z6"
[1][2][3][4]
```

---

## JavaScript arrays are special objects

They can behave like:

* arrays
* dictionaries
* sparse arrays

Example:

```javascript id="3wdj1n"
arr[100] = 5;
```

Visual:

```text id="g3mdc5"
index 0 ... 99 empty ... 100 = 5
```

This creates holes.

🟨 flexible but less predictable

---

# 7. Rust Vec

Language:
Rust

Example:

```rust id="q94ckx"
let mut v = vec![1,2,3];
v.push(4);
```

Visual:

```text id="oq8o3x"
[1][2][3][4]
```

---

## Rust advantages

| Feature   | Rust |
| --------- | ---- |
| Dynamic   | Yes  |
| Safe      | Yes  |
| Fast      | Yes  |
| Ownership | Yes  |

Rust prevents:

🟥 dangling pointers
🟥 invalid memory access

while staying efficient.

---

# 8. Bounds checking comparison

Access invalid index:

```text id="a1s90g"
arr[10]
```

| Language   | Result    |
| ---------- | --------- |
| C          | undefined |
| C++ `[]`   | undefined |
| Java       | exception |
| Python     | exception |
| JavaScript | undefined |
| Rust       | panic     |

---

# 9. Negative indexing

Some languages support it.

Python:

```python id="hh6gr7"
arr[-1]
```

Visual:

```text id="wvb6je"
[10][20][30]
          ↑
        arr[-1]
```

Result:

```text id="cb3wkp"
30
```

Most languages do not support this.

---

# 10. Memory behavior comparison

| Language   | Fixed | Dynamic        | Safe    |
| ---------- | ----- | -------------- | ------- |
| C          | Yes   | No             | No      |
| C++        | Both  | Yes            | Partial |
| Java       | Yes   | With ArrayList | Yes     |
| Python     | No    | Yes            | Yes     |
| JavaScript | No    | Yes            | Yes     |
| Rust       | Both  | Yes            | Yes     |

---

# 11. Beginner mental model

Think of languages like this:

### C

🟩 fastest
🟥 dangerous

### Python

🟩 easiest
🟨 slower

### Rust

🟩 safe + fast
🟨 harder to learn

### JavaScript

🟩 flexible
🟨 unusual internals

---

# 12. Real-world choice

Different tools for different jobs.

Example uses:

* C → operating systems
* Python → data science
* JavaScript → web apps
* Rust → systems programming

Examples:

* Linux Foundation
* Mozilla

---

# 13. Key takeaway

Arrays may look similar:

```text id="y6h2n7"
[1,2,3]
```

But internally each language chooses different tradeoffs:

```text id="udjlwm"
speed vs safety vs flexibility
```

That is why language behavior matters.
