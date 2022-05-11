#include <bits/stdc++.h>

using namespace std;

// Returns whether or not it is possible to make this score with at least k
// generations
// Complexity : O(N)
bool score_possible(const vector<int> &columns, int k, int score) {
    if (score == 0)
        return true;

    for (auto col : columns) {
        // We have to generate ceil(score / col) sticks of this size
        // such that the total size is greater or equal to the score
        int to_generate = (score - 1) / col + 1;
        k -= to_generate;

        if (k < 0) {
            return false;
        }
    }

    // We have used k or less than k generations
    return true;
}

int max_sticks_score(const vector<int> &columns, int k) {
    // It is not possible to have a score greater than this value using
    // k generations
    int max_score = *max_element(columns.begin(), columns.end()) * k;

#if 0
    // * O(N * max(A) * K)
    int last_possible = 0;
    for (int i = 0; i <= max_score; ++i) {
        bool is_possible = score_possible(columns, k, i);
        // cout << i << " -> " << is_possible << endl;

        if (is_possible) {
            last_possible = i;
        }
    }
#else
    // * O(N log(max(A) * K))
    // Always possible to do a score of 0
    int last_possible = 0;
    int l = 0;
    int r = max_score + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (score_possible(columns, k, mid)) {
            last_possible = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }
#endif

    return last_possible;
}

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
