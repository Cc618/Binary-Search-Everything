#include <bits/stdc++.h>

using namespace std;

// $BEGIN$
int binary_search(const vector<int> &array, int val) {
    // FIXME
}
// $END$

#include <gtest/gtest.h>

TEST(BinSearch, Simple) {
    vector<int> array{1, 4, 5, 8, 42, 64, 618};
    int val = 42;

    ASSERT_EQ(binary_search(array, val), 4);
}

TEST(BinSearch, Simple2) {
    vector<int> array{1, 4, 5, 8, 42, 64, 618};
    int val = 1;

    ASSERT_EQ(binary_search(array, val), 0);
}

TEST(BinSearch, Simple3) {
    vector<int> array{1, 4, 5, 8, 42, 64, 618};
    int val = 618;

    ASSERT_EQ(binary_search(array, val), 6);
}

TEST(BinSearch, NotFound) {
    vector<int> array{1, 4, 5, 8, 42, 64, 618};
    int val = 0;

    ASSERT_EQ(binary_search(array, val), -1);
}

TEST(BinSearch, NotFound2) {
    vector<int> array{1, 4, 5, 8, 42, 64, 618};
    int val = 9000;

    ASSERT_EQ(binary_search(array, val), -1);
}

TEST(BinSearch, NotFound3) {
    vector<int> array{1, 4, 5, 8, 42, 64, 618};
    int val = 9;

    ASSERT_EQ(binary_search(array, val), -1);
}

TEST(BinSearch, NotFound4) {
    vector<int> array{1};
    int val = 2;

    ASSERT_EQ(binary_search(array, val), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
