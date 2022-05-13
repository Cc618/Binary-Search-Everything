## Statement
There are an array $A$ of length $N$ sorted in non-descending order
(that is, $A_i \le A_{i + 1}$) and a value $X$.
Find the index of $X$ within $A$ (indices start from 0).
If $X$ is not in the array, return $-1$.

## Input
- $-10^9 \le A_i \le 10^9$
- $-10^9 \le X \le 10^9$
- $0 \le N \le 2 \times 10^5$

## Example

### Input
- The array $A$ :

| $A_i$ | 1 | 4 | 8 | 10 |
| ----- | - | - | - | -- |
|  $i$  | 0 | 1 | 2 | 3 |

- $X = 8$

### Output
The output should be **2** since we can make this new array :

| $A_i$ | 1 | 4 | **8** | 10 |
| ----- | - | - | - | -- |
|  $i$  | 0 | 1 | **2** | 3 |

## Follow-up
<details>
Return the index where $X$ must be within $A$.

### Example

#### Input
- The array $A$ :

| $A_i$ | 1 | 4 | 8 | 10 |
| ----- | - | - | - | -- |
|  $i$  | 0 | 1 | 3 | 4 |

- $X = 7$

#### Output
The output should be **2** since we can make this new array :

| $A_i$ | 1 | 4 | **7** | 8 | 10 |
| ----- | - | - | - | - | -- |
|  $i$  | 0 | 1 | **2** | 3 | 4 |
</details>
