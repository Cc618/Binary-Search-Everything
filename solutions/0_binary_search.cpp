#include <bits/stdc++.h>

using namespace std;

// $BEGIN$
int binary_search(const vector<int> &array, int val) {
    // val is within [l, r) (if val is in the array)
    int l = 0;
    int r = array.size();

    // While the range [l, r) is not empty
    while (l < r) {
        int mid = l + (r - l) / 2;

        if (array[mid] == val) {
            // Found
            return mid;
        } else if (array[mid] < val) {
            // val is not before l, so val is within [mid + 1, r)
            l = mid + 1;
        } else /* array[mid] > val */ {
            // val is not after r, so val is within [l, mid)
            r = mid;
        }
    }

    // Not found, val should be at index l
    return -1;
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
