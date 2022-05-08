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

#if 0
    for (auto e : avgs) {
        cout << e * .5f << " ";
    }
    cout << endl;
#endif

    // 1 based
    return avgs[k - 1] * .5f;
}

// Count how many values are strictly lower than x
int count_lower(const vector<int> &a, const vector<int> &b, int x) {
    int n_lower = 0;
    for (int i = 0; i < a.size(); ++i) {
        // TODO : Binary search
        for (int j = 0; j < b.size(); ++j) {
            int current_avg = (a[i] + b[j]) / 2;
            if (current_avg >= x)
                break;

            ++n_lower;
        }
    }

    return n_lower;
}

float average_index(vector<int> a, vector<int> b, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Use integers, not floating points
    for (auto &e : a)
        e *= 2;
    for (auto &e : b)
        e *= 2;

    // We have to find the last mid where count_lower(a, b, mid) < k is true
    int l = 0;
    int r = (a.back() + b.back()) / 2 + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        // Query whether the K-th value is lower or higher than the mid value
        if (count_lower(a, b, mid) < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    // r points to the first count_lower(a, b, r) >= k
    int result = max(0, r - 1);

#if 0
    // --- Brute force ---
    int last_true = 0;
    for (int i = l; i < r; i++) {
        auto count = count_lower(a, b, i);
        bool ok = count < k;
        cout << setw(2) << i << " " << count << " (" << boolalpha << ok <<
        ")"
             << endl;

        if (ok) {
            last_true = i;
        }
    }
    result = last_true;
#endif

    return result * .5f;
}

#include <gtest/gtest.h>

static const vector<int> basic_a{1, 3, 4};
static const vector<int> basic_b{2, 4, 5};

TEST(AvgIndex, Basic) {
    int k = 5;
    auto current = average_index(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Basic2) {
    int k = 3;
    auto current = average_index(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Basic3) {
    int k = 9;
    auto current = average_index(basic_a, basic_b, k);
    auto target = bruteforce(basic_a, basic_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Basic4) {
    vector<int> a = {1, 3, 4};
    vector<int> b = {2, 4, 5};
    int k = 0;
    auto current = average_index(a, b, k);
    auto target = bruteforce(a, b, k);

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
    int k = 0;
    auto current = average_index(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Hard2) {
    int k = 200 * 200;
    auto current = average_index(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Hard3) {
    int k = 42;
    auto current = average_index(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

TEST(AvgIndex, Hard4) {
    int k = 314;
    auto current = average_index(hard_a, hard_b, k);
    auto target = bruteforce(hard_a, hard_b, k);

    ASSERT_EQ(current, target);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
