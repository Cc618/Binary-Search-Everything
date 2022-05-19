Let's suppose that the provided array contains both linear and leaky parts,
that is, the array is neither full linear nor full leaky.

The initial search interval is $[0, N - 1]$ (indices start from 0).

At each iteration, *mid* is the pivot point.
To find whether the target point is at the left or right hand side to this point, we can deduce a criterion :

*leaky_part(i)* is a function returning a boolean, it returns *true* when the part containing the index i is the leaky part (the left part of the function) and *false* otherwise.

This function can be easily implemented : *leaky_part(i)* = *true* $\Leftrightarrow A_{i + 1} - A_i < 1$.

Thus, when *mid* is before the target point (at its left), *leaky_part(mid)* is *true* and the new interval is $[mid + 1, r]$.


The last $l$ value is the target point.
