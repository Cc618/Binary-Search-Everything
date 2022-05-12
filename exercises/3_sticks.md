<!-- TODO : Update statement -->

### Statement
There are $N$ columns.
You generate $K$ sticks, you can choose the column where the stick is generated.
The size of the generated stick is $A_i$ for the $i$-th column.

The score is the minimum size of each column.
Your goal is to print the maximum score.

### Constraints
- $1 \le N \le 10^5$
- $1 \le A_i \le 100$
- $1 \le K \le 10^7$

It can be shown that the maximum score won't exceed $2 \times 10^9$.

### Complexity
- Time : $O(N \log(\max_i(A_i) \times K))$
