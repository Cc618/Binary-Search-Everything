### Statement
There are $N$ columns.
At the top of each column, there is a magic bag containing sticks.
The bag at the $i$-th column can generate a stick of size $A_i$.

You - *as a newbie wizard* - can generate at most $K$ sticks in total.
You can choose which bag to use, when a stick is generated, it is placed in its corresponding column.

The size of a column is the sum of every sticks in it.
For example, if $A_i = 3$ and you generate 2 sticks, then the size of the $i$-th column is $2 \times 3 = 6$.

The score is the minimum size of each column.
Your goal is to find the maximum possible score after at most $K$ stick generation.

### Example
- $A = [3, 5, 6]$
- $K = 5$

You can generate 2 sticks in the first column and the second one and then one stick in the last column.

| Bags       | 3   | 5   | 6   |
| ---------- | --- | --- | --- |
|            | X   | X   | X   |
|            | X   | X   |     |
| Total size | 6   | 10  | 6   |

Hence, the score is $min(6, 10, 6) = 6$.
It is possible to prove that this score is maximal.

### Constraints
- $1 \le N \le 10^5$
- $1 \le A_i \le 100$
- $1 \le K \le 10^7$

It can be shown that the maximum score won't exceed $2 \times 10^9$.

### Complexity
- Time : $O(N \log(\max_i(A_i) \times K))$
