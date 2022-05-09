#include <bits/stdc++.h>

using namespace std;

// Returns whether it is the leaky part
bool leaky_part(const vector<float> &values, int i) {
    // Float precision...
    return abs(values[i] - values[i + 1]) >= .99f;
}

// Using STL's lower_bound (O(N) preprocessing)
int leaky_relu_stl(const vector<float> &values) {
    vector<bool> filter(values.size() - 1);
    for (int i = 0; i + 1 < values.size(); ++i) {
        filter[i] = leaky_part(values, i);
    }

    // Only leaky
    if (!filter.back()) {
        return values.size();
    }

    return distance(filter.begin(),
                    lower_bound(filter.begin(), filter.end(), true));
}

int leaky_relu(const vector<float> &values) {
#if 0
    // O(N) version
    for (int i = 0; i + 1 < values.size(); i++) {
        if (leaky_part(values, i)) {
            return i;
        }
    }

    return values.size();
#endif

    int l = 0;
    int r = values.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;

        // Find the first time this function returns true w.r.t. mid
        if (leaky_part(values, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (l == values.size() - 1 && !leaky_part(values, values.size() - 2)) {
        return values.size();
    }

    return l;
}

#include <gtest/gtest.h>

TEST(LeakyRelu, Simple) {
    //                            v
    vector<float> a{1, 1.2, 1.4, 1.6, 2.6, 3.6, 4.6};
    ASSERT_EQ(leaky_relu(a), 3);
}

TEST(LeakyRelu, Simple2) {
    //                  v
    vector<float> a{1, 1.2, 2.2};
    ASSERT_EQ(leaky_relu(a), 1);
}

TEST(LeakyRelu, Simple3) {
    //                                     v
    vector<float> a{4, 4.2, 4.4, 4.6, 4.8, 5, 6};
    ASSERT_EQ(leaky_relu(a), 5);
}

TEST(LeakyRelu, Simple4) {
    //                  v
    vector<float> a{3, 3.2, 4.2, 5.2};
    ASSERT_EQ(leaky_relu(a), 1);
}

TEST(LeakyRelu, OnlyLeaky) {
    ASSERT_EQ(leaky_relu(vector<float>{4, 4.2, 4.4}), 3);
}

TEST(LeakyRelu, OnlyLinear) {
    ASSERT_EQ(leaky_relu(vector<float>{4, 5, 6}), 0);
}

int main(int argc, char **argv) {
    // vector<float> a = {1, 1.2, 1.4, 1.6, 2.6, 3.6, 4.6};

    // // 4
    // vector<float> a = {1, 1.2, 2.2};
    // cout << leaky_relu(a) << endl;
    // return 0;

    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
