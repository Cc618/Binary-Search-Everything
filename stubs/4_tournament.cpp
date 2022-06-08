#include <bits/stdc++.h>

using namespace std;

static float bruteforce(vector<int> a, vector<int> b, int k) {
    vector<int> avgs;
    for (auto a_item : a) {
        for (auto b_item : b) {
            avgs.push_back(a_item + b_item);
        }
    }

    sort(avgs.begin(), avgs.end());

    // 1 based
    return avgs[k - 1] * .5f;
}

// $BEGIN$
float tournament(vector<int> a, vector<int> b, int k) {
    // FIXME
}
// $END$

#include <gtest/gtest.h>

static const vector<int> basic_a{1, 3, 4};
static const vector<int> basic_b{2, 4, 5};

static const vector<int> spread_a{1, 10};
static const vector<int> spread_b{200, 400, 1000};

TEST(AvgIndex, Basic) {
    int k = 5;
    auto current = tournament(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Basic2) {
    int k = 3;
    auto current = tournament(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Basic3) {
    int k = 9;
    auto current = tournament(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Basic4) {
    vector<int> a = {1, 3, 4};
    vector<int> b = {2, 4, 5};
    int k = 1;
    auto current = tournament(a, b, k);
    auto target = bruteforce(a, b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Spread1) {
    int k = 5;
    auto current = tournament(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Spread2) {
    int k = 1;
    auto current = tournament(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Spread3) {
    int k = 3;
    auto current = tournament(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Spread4) {
    int k = 6;
    auto current = tournament(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

static const vector<int> hard_a{
    6, 1, 6, 4, 4, 3, 8, 3, 7, 2, 6, 1, 4, 2, 5, 6, 3, 2, 1, 1, 5, 1, 0, 6, 2,
    7, 0, 6, 8, 6, 4, 0, 8, 8, 8, 1, 3, 3, 2, 3, 5, 2, 7, 1, 0, 5, 6, 6, 6, 2,
    2, 3, 0, 6, 8, 1, 1, 2, 8, 0, 4, 5, 8, 7, 8, 0, 1, 1, 2, 8, 0, 2, 2, 5, 7,
    7, 3, 8, 7, 1, 7, 6, 7, 6, 7, 1, 1, 3, 3, 7, 5, 5, 4, 5, 5, 6, 7, 2, 8, 1,
    4, 5, 1, 3, 5, 2, 7, 5, 8, 2, 2, 6, 6, 6, 7, 4, 5, 6, 8, 6, 6, 6, 1, 6, 6,
    4, 0, 2, 8, 3, 7, 8, 1, 0, 5, 2, 7, 0, 5, 5, 6, 6, 8, 2, 0, 5, 3, 4, 0, 5,
    4, 2, 8, 6, 0, 2, 8, 3, 5, 7, 2, 7, 5, 6, 7, 2, 5, 0, 4, 0, 6, 5, 3, 1, 7,
    6, 5, 0, 1, 8, 3, 6, 5, 4, 7, 1, 5, 3, 6, 1, 4, 1, 6, 3, 2, 3, 0, 6, 0, 3};
static const vector<int> hard_b{
    0, 4, 0, 8, 2, 2, 5, 1, 0, 4, 4, 0, 8, 4, 3, 5, 2, 6, 6, 6, 2, 2, 4, 2, 8,
    6, 1, 8, 2, 6, 0, 2, 8, 1, 3, 1, 1, 6, 8, 7, 8, 4, 2, 7, 7, 3, 0, 1, 8, 6,
    2, 4, 6, 7, 3, 3, 5, 7, 3, 5, 3, 7, 0, 5, 8, 2, 4, 7, 2, 7, 4, 7, 5, 1, 4,
    5, 3, 3, 7, 7, 8, 8, 5, 6, 5, 4, 5, 7, 2, 0, 8, 7, 1, 3, 3, 6, 0, 5, 3, 6,
    5, 8, 7, 5, 3, 4, 6, 5, 2, 7, 7, 6, 1, 4, 1, 5, 3, 3, 1, 8, 5, 6, 1, 4, 1,
    4, 1, 7, 4, 5, 5, 4, 8, 0, 2, 7, 3, 5, 6, 5, 7, 3, 1, 6, 8, 3, 4, 7, 1, 2,
    1, 6, 5, 4, 1, 5, 4, 4, 5, 1, 4, 6, 6, 6, 7, 8, 0, 5, 2, 6, 7, 2, 2, 6, 1,
    3, 7, 3, 6, 1, 0, 1, 7, 6, 4, 2, 7, 5, 1, 0, 0, 0, 8, 1, 2, 4, 8, 6, 2, 5};

TEST(AvgIndex, Hard) {
    int k = 1;
    auto current = tournament(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Hard2) {
    int k = 200 * 200;
    auto current = tournament(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Hard3) {
    int k = 42;
    auto current = tournament(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Hard4) {
    int k = 314;
    auto current = tournament(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
