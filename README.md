# Push Swap

![C](https://img.shields.io/badge/language-C-blue.svg)

### Overview

Push Swap is an algorithmic challenge from the 42 curriculum. The goal is to sort a list of unique integers (positive and negative) using **two stacks** and a **restricted set of operations**, in **as few moves as possible**.

This implementation uses:
* **Hardcoded solutions** for 2-5 elements
* **Optimized quick sort** for 6-150 elements
* **Radix binary sort** for larger inputs

---
### Implementation Details

#### Validation & Parser
* **Error handling**: empty input, non-numeric characters, duplicates, and integer overflow.
* Stacks a and b are implemented as **doubly linked lists**.
* User input is **normalized** (mapped to values 0...N-1) before sorting.

#### Allowed Operations

| **Operation** |**Effect** |
| ------------|:-----------:|
|`sa` | Swap top two elements of stack a |
|`sb` | Swap top two elements of stack b |
|`ss` | Swap top two elements of both stacks |
|`pa` | Push top element of b to a |
|`pb` | Push top element of a to b |
|`ra` | Rotate stack a (shift up) |
|`rb` | Rotate stack b (shift up)  |
|`rr` | Rotate both stacks (shift up)  |
|`rra` | Reverse rotate stack a (shift down) |
|`rrb` | Reverse rotate stack b (shift down) |
|`rrr` | Reverse rotate both stacks (shift down) |

#### Sorting Algorithms

##### Quick Sort (6-150 elements)
* Based on the principle of **divide and conquer**.
* Pushes values below the median (the **pivot**) to stack b.
* **Recursively** sorts partitions with **greedy rotate** optimizations.

##### Radix Binary Sort (>150 elements)
* Treats integer as **binary**.
* Sorts **bit by bit**, from least significant to most significant.
* Post-processes list of instructions to remove redundant moves.

##### Algorithm analysis

|**Complexity** |**Quick Sort** | **Radix Sort** |
| ------------| ------------| :-----------:|
|Best time |`Ω(n log n)` |`O(d * (n + b))` |
|Average time |`θ(n log n)` |`O(d * (n + b))` |
|Worst time |`O(n²)` |`O(d * (n + b))` |
|Best space |`O(n)` |`O(n + b)` |
|Worst space |`O(log n)` |`O(n + b)` |

> Note: n = elements, d = digits, b = base

---
### Performance

A shell script is included to benchmark the programme on random inputs.

Results based on **100 tests** per each size:

|**Size** |**Minimum** |**Maximum** | **Average** |
| --------| -----------| -----------|:-----------:|
|**3** |0 |2 | 1 |
|**5** |0 |10 |7 |
|**100** |694 |891 |778 |
|**500** |6704 |6748 |6662 |

> Note: The tester uses 42's `checker_linux` to verify the correctness of the programme's output. You may swap it for another checker of your choice.

---
### Installation

**Requirements**: `gcc`, `make`

```
git clone https://github.com/biertisch/push_swap.git
cd push_swap
make
```

---
### Usage

Sort a list of integers:
```
./push_swap -9 0 13 452 -3 -9186
```
The programme outputs the sequence of operations needed to sort the list.

You can verify the result using 42's `checker_linux` (included):
```
ARG="-9 0 13 452 -3 -9186"; ./push_swap $ARG | ./checker_linux $ARG
```

#### Performance Tester
```
make test ARGS="<size> <number_of_tests>"
```
Example:
```
make test ARGS="500 10"
```
(By default, `ARGS="100 100"`.)

> Note: The tester uses 42's `checker_linux` to verify the correctness of the programme's output. You may swap it for another checker of your choice.

---
### About 42

42 is a computer science school founded in Paris in 2013. It follows a project-based, peer-to-peer pedagogy focused on low-level programming and algorithmic thinking.

---
### License & Contact

This repository is open for learning and reuse. Contributions, suggestions, and discussions are welcome — feel free to open an issue or reach out.