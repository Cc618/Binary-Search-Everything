Suppose $X$ is in the array.
Maintain two values, $l$ and $r$ representing an interval where $X$ is (e.g. $X \in [l, r]$).

| $A_i$ | 1 | 4 | 8 | 10 |
| ----- | - | - | - | -- |
|  $i$  | 0 | 1 | 2 | 3 |
|  l/r  | l |   |   | r |

> Note that $r$ is excluded in the source code, that is, the interval is $[l, r - 1]$

While this interval has at least two values, we have to minimize it.
Let *mid* be the middle value, *mid* = $\lfloor \frac {l + r} 2 \rfloor$.

To minimize the interval, we have to choose to keep either $[mid + 1, r]$ or $[l, mid - 1]$.

- If $\text{array}_{\text{mid}} < X$, thus $X$ is not after *mid* so the new interval is $[l, mid - 1]$.
- Otherwise, the interval is $[mid + 1, r]$.

<!-- TODO : Examples -->
