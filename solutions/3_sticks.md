### Intuition
To maximize the score, we can try every possible value.

Using the provided example, we obtain this array after $K = 5$ stick generation :

| Score                        | 0   | 1   | 2   | 3   | 4   | 5   | 6     | 7   | 8   | 9   | ... |
| ---------------------------- | --- | --- | --- | --- | --- | --- | ----- | --- | --- | --- | --- |
| Can be obtained / exceeded ? | 1   | 1   | 1   | 1   | 1   | 1   | **1** | 0   | 0   | 0   | 0   |

As the maximum score is 6, every score <= 6 is possible to obtain / exceed and scores > 6 are impossible to obtain.

In a binary search point of view, we can find the last **1** in logarithm time complexity.

### Editorial
Let's divide this problem into two problems.

First of all, we will make the binary search and then we will create a function to query whether or not it is possible to obtain or exceed a score given $K$ generations.

#### Binary search
We have to find search boundaries in first place.
We can see that it is always possible to have a score of 0.
Moreover, the maximum possible score is obtained by generating $K$ sticks of maximal size.

The initial interval is then $[0, max_i(A_i) \times K]$.

It is a simple lower bound algorithm, the condition to minimize the interval is whether or not it is possible to obtain / exceed the score (which is the the middle of the interval).

1. mid = $\frac {l + r} 2$
2. If `possible(mid, k)` then interval = $[mid + 1, r]$
3. Otherwise, interval = $[l, mid - 1]$

Note that when we reach step 2., we can set the maximum possible score to `mid` since it is possible to obtain this score.

#### Query
