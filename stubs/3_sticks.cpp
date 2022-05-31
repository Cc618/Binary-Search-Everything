#include <bits/stdc++.h>

using namespace std;

// $BEGIN$
int max_sticks_score(const vector<int> &columns, int k) {
    // FIXME
}
// $END$

#include <gtest/gtest.h>

TEST(Sticks, Simple1) {
    vector<int> cols{3, 5, 6};
    int k = 5;

    ASSERT_EQ(max_sticks_score(cols, k), 6);
}

TEST(Sticks, Simple2) {
    vector<int> cols{3, 5, 6};
    int k = 12;

    // 5*3 = 15, 4*5 = 20, 3*6 = 18 -> score = 15
    ASSERT_EQ(max_sticks_score(cols, k), 15);
}

TEST(Sticks, Simple3) {
    vector<int> cols{3, 5, 6};
    int k = 618;

    ASSERT_EQ(max_sticks_score(cols, k), 882);
}

TEST(Sticks, Simple4) {
    vector<int> cols{3, 5, 6};
    int k = 10'000'000;

    ASSERT_EQ(max_sticks_score(cols, k), 14285712);
}

TEST(Sticks, Hard1) {
    vector<int> cols{3, 5, 6, 61, 28, 42, 31, 2, 42, 68, 7, 42, 99, 3, 3, 3};
    int k = 42;

    ASSERT_EQ(max_sticks_score(cols, k), 12);
}

TEST(Sticks, Hard2) {
    vector<int> cols{3, 5, 6, 61, 28, 42, 31, 2, 42, 68, 7, 42, 99, 3, 3, 3};
    int k = 1;

    ASSERT_EQ(max_sticks_score(cols, k), 0);
}

TEST(Sticks, Hard3) {
    vector<int> cols{3, 5, 6, 61, 28, 42, 31, 2, 42, 68, 7, 42, 99, 3, 3, 3};
    int k = 2;

    ASSERT_EQ(max_sticks_score(cols, k), 0);
}

// 30s in O(N * max(A) * K) vs < 1 ms in O(N * log(max(A) * K))
TEST(Sticks, Hard4) {
    vector<int> cols{3, 5, 6, 61, 28, 42, 31, 2, 42, 68, 7, 42, 99, 3, 3, 3};
    int k = 9'999'991;

    ASSERT_EQ(max_sticks_score(cols, k), 3962808);
}

TEST(Sticks, Hard5) {
    vector<int> cols{3, 5, 6, 61, 28, 42, 31, 2, 42, 68, 7, 42, 99, 3, 3, 3};
    int k = 0;

    ASSERT_EQ(max_sticks_score(cols, k), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
