#include <bits/stdc++.h>

using namespace std;

static float bruteforce(vector<int> a, vector<int> b, long long k) {
    vector<int> avgs;
    for (auto a_item : a) {
        for (auto b_item : b) {
            avgs.push_back(a_item + b_item);
        }
    }

    sort(avgs.begin(), avgs.end());

    // TODO
    for (auto e : avgs) {
        cout << e * .5f << " ";
    }
    cout << endl;

    // 1 based
    return avgs[k - 1] * .5f;
}

// Count how many values are strictly lower than x
long long count_lower(const vector<int> &a, const vector<int> &b, int x) {
    long long n_lower = 0;
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

float average_index(vector<int> a, vector<int> b, long long k) {
    cout << "Solution: " << bruteforce(a, b, k) << endl;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Use integers, not floating points
    for (auto &e : a)
        e *= 2;
    for (auto &e : b)
        e *= 2;

    // 0 based indexing
    // --k;

    int l = 0;
    int r = (a.back() + b.back()) / 2 + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        cout << l << " " << mid << " " << r << endl;

        // Query whether the K-th value is lower or higher than the mid value
        if (count_lower(a, b, mid) < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return l * .5f;
}

#include <gtest/gtest.h>

// TEST(Sqrt, Zero) { ASSERT_EQ(int_sqrt(0), 0); }

// TEST(Sqrt, One) { ASSERT_EQ(int_sqrt(1), 1); }

// TEST(Sqrt, Four) { ASSERT_EQ(int_sqrt(4), 2); }

// TEST(Sqrt, Sixteen) { ASSERT_EQ(int_sqrt(16), 4); }

// TEST(Sqrt, TwentyFive) { ASSERT_EQ(int_sqrt(25), 5); }

int main(int argc, char **argv) {
    vector<int> a = {1, 3, 4};
    vector<int> b = {2, 4, 5};

    cout << average_index(a, b, 5) << endl;

    cout << average_index(vector<int>{1, 10}, vector<int>{4, 8}, 2) << endl;

    // ::testing::InitGoogleTest(&argc, argv);
    // int ret{RUN_ALL_TESTS()};
    // return ret;
}
