# Leaky ReLU
## Statement
The LeakyReLU function can be split into two parts :
- The identity function (left hand side), e.g. $y = x$
- The leaky part (left hand side), that is, the identity function multiplied by a small factor such as 0.2, e.g. $y = 0.2 \times x$

<img width="200px" height="200px" src="https://production-media.paperswithcode.com/methods/Screen_Shot_2020-05-25_at_3.09.45_PM.png" />

> Credit: paperswithcode.com

Given a sample of this function in an array $A$ of length $N$.
Find the index of the value belonging in the two parts of this function.

## Example
Given this array of length 7 :

| 0   | 1   | 2   | 3       | 4   | 5   | 6   |
| --- | --- | --- | ------- | --- | --- | --- |
| 1   | 1.2 | 1.4 | **1.6** | 2.6 | 3.6 | 4.6 |

- Values from 0 to 3 included are the leaky part
- Values from 3 to 4 included are the identity part

Thus, the value 1.6 at index 3 belongs to both parts.

> Answer : 3

## Constraints
- 0 <= N <= 10^5

## Complexity
- Time : O(log N)
