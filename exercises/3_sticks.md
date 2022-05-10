# Sticks
## Statement
You have multiple sticks of some sizes.

It is possible to merge two sticks together to produce a new stick.
This new stick has a size equal to the sum of the sizes of the two initial sticks.

After few merges, it remains two sticks.
The score is the minimum size of those two sticks.

Your goal is to maximize this score.

## Example
You have 5 sticks of size [2, 3, 1, 2, 1].

1. You can merge the first two sticks into a single stick of size 2 + 3 = 5.
2. Then, you merge the two sticks of size 1 resulting into a stick of size 1 + 1 = 2.
3. Finally, you merge the stick of size 2 with the stick produced at the last step (size 2 too), you now have a stick of size 2 + 2 = 4.

The resulting sticks have size 4 and 5.
Hence, the score is min(4, 5) = 4, which is maximal.

It can be prooved that it is not possible to make a better score.

## Follow-up
What if the size of the new stick is now the product instead of the sum of the two initial sticks ?
