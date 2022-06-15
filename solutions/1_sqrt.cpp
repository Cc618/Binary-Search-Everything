#include <bits/stdc++.h>

using namespace std;

// $BEGIN$
int int_sqrt(int n) {
    int l = 0;
    int r = n + 1;
    while (l < r) {
        int x = l + (r - l) / 2;

        // Query whether the sqrt is lower or higher
        int y = x * x;
        if (y <= n) {
            l = x + 1;
        } else {
            r = x;
        }
    }

    // l is the integer after the sqrt (l = x + 1 when sqrt x <= sqrt n)
    return l - 1;
}
// $END$

#include <gtest/gtest.h>

TEST(Sqrt, Zero) { ASSERT_EQ(int_sqrt(0), 0); }

TEST(Sqrt, One) { ASSERT_EQ(int_sqrt(1), 1); }

TEST(Sqrt, Four) { ASSERT_EQ(int_sqrt(4), 2); }

TEST(Sqrt, Sixteen) { ASSERT_EQ(int_sqrt(16), 4); }

TEST(Sqrt, TwentyFive) { ASSERT_EQ(int_sqrt(25), 5); }

TEST(Sqrt, FortyTwo) { ASSERT_EQ(int_sqrt(42), 6); }

TEST(Sqrt, NinetyNine) { ASSERT_EQ(int_sqrt(99), 9); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
