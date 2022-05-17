Suppose $X$ is in the array.
Maintain two values, $l$ and $r$ representing an interval where $X$ is (e.g. $X \in [l, r - 1]$ if $r$ is exclusive).

While this interval has at least two values, we have to minimize it.
Let *mid* be the middle value, *mid* = $\lfloor \frac {l + r} 2 \rfloor$.

To minimize the interval, we have to choose to keep either $[mid, r)$ or $[l, mid)$.

- If $\text{array}_{\text{mid}} < X$, thus $X$ is not after *mid* so the new interval is $[l, mid)$.
- Otherwise, the interval is [$mid, r)$.

<!-- TODO : Examples -->
