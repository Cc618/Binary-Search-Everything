First of all, the integer square root function is monotonic.
Especially, it is either constant or increasing, $\sqrt N \le \sqrt {N + 1}$.

Secondly, $0 \le \sqrt N \le N$, we can initialize the interval with $[0, N]$ ($l = 0$ and $r = N$).

While this interval contains more than one number, at each iteration we will decide whether to keep the left or right most half of this interval.

Let *mid* $= \lfloor \frac {l + r} 2 \rfloor$.
*mid* is our guess, we have to find whether or not $mid < \sqrt N$.
Since $mid \ge 0$, $mid < \sqrt N \Leftrightarrow mid^2 < {(\sqrt N)}^2$.
In other words, $mid < \sqrt N \Leftrightarrow mid^2 < N$.

Thus, if $mid^2 < N$, then *mid* is less than $\sqrt N$, the new interval is $[mid + 1, r]$ (and $[l, mid - 1]$ otherwise).

The result is $l$ when the interval contains less than two values.
