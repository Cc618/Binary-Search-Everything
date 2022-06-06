### Analysis
First of all, let's see the problem using a grid on the example ($A$ = [1, 4, 3], $B$ = [5, 2, 4], $K$ = 5).
$A$ is the vertical and $B$ the horizontal.
Since the initial order of $B$ and $A$ doesn't modify the problem, we can sort them (only $B$ has to be sorted in this solution though).

| $A$ / $B$ | 2   | 4   | 5   |
| --------- | --- | --- | --- |
| 1         | 1.5 | 2.5 | 3   |
| 3         | 2.5 | 3.5 | 4   |
| 4         | 3   | 4   | 4.5 |

In order, the average values are [1.5, 2.5, 2.5, 3, **3**, 3.5, 4, 4, 4.5] (**3** is the $K = 5$-th value).

Let $x$ be the $K$-th value (the result we want).

The $K$-th value means that it exists strictly less than $K$ values strictly less than $x$.
It also means that there are $K$ or more than $K$ values less or equal to $x$ (if all average values are distinct, then it exists exactly $K$ values less or equal to $x$).

If we count the number of values less or equal to any $x$, we can deduce our result.
This can be done using binary search.

### Binary search
The minimum and maximum average values are $0$ ($A$ and $B$ contains only positive integers) and $\frac {max_i(A_i) + max_j(B_j)} 2$ respectively, this is the initial interval.

At every iteration, we have to query whether the $K$-th value is lower or higher than the $mid$ value.

To do so, we can count the number of average values strictly less than $mid$.
If this number is strictly less than $K$, then it is guaranteed that $x$ is after $mid$ (so the new interval is [mid + 1, r]).

We call the query function $count\\_lower$.

> Time complexity $O(log(max(A) + max(B)) \times O(count\\_lower))$

### Query function
This function takes as parameter $x$ and returns how many average values are strictly less than $x$.

We can compute this in quadratic time complexity but it is necessary to have an efficient query function, let's use *again* binary search !

For each row $i$ of the grid, we combine $A_i$ with every $B_j$, $A_i$ doesn't change so we can binary search the last value of $B_j$ such that $\frac {A_i + B_j} 2 < x$.

The query function is then $\frac {A_i + B_{mid}} 2 < x$ (note that $mid$ is the pivot in this binary search, not the previous one).

> Time complexity $O(N \times log(M))$

### To sum up

#### Main function

- Binary search $result$ with interval $[0, \frac {max_i(A_i) + max_j(B_j)} 2]$, last value such that $count\\_lower(result) < K$
- Return $result$ (or $\frac {result} 2$ in the [Implementation tip](#implementation-tip) section)

#### Query function (count_lower(x))

- For every row $i$
  - Binary search the last index $j$ where $\frac {A_i + B_j} 2 < x$
  - Add $j$ to the total count
- Return the total count

> Total time complexity $O(log(max(A) + max(B)) \times N \times log(M))$

### Implementation tip
It is good to avoid floating points when possible.
In this exercise, we can notice that $\frac {a + b} 2 = \frac 1 2 \times (a + b)$, we can compute the sum $a + b$ instead of the average and then divide the result by $2$.
