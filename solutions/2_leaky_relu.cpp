#include <bits/stdc++.h>

using namespace std;

// Returns whether it is the leaky part
bool leaky_part(const vector<float> &values, int i) {
    return abs(values[i] - values[i + 1]) < 1.f;
}

int leaky_relu(const vector<float> &values) {
    int l = 0;
    int r = values.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        cout << l << endl;
        if (leaky_part(values, mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return l - 1;
}

#include <gtest/gtest.h>

TEST(LeakyRelu, Simple) {
    ASSERT_EQ(leaky_relu(vector<float>{1, 1.2, 1.4, 1.6, 2.6, 3.6, 4.6}), 3);
}

TEST(LeakyRelu, Simple2) {
    ASSERT_EQ(leaky_relu(vector<float>{1, 1.2, 2.2}), 1);
}

TEST(LeakyRelu, Simple3) {
    ASSERT_EQ(leaky_relu(vector<float>{4, 4.2, 4.4, 4.6, 4.8, 5, 6}), 4);
}

// TEST(LeakyRelu, OnlyLeaky) {
//     ASSERT_EQ(leaky_relu(vector<float>{4, 4.2, 4.4}), 2);
// }

// TEST(LeakyRelu, OnlyLinear) {
//     ASSERT_EQ(leaky_relu(vector<float>{4, 5, 6}), 0);
// }

int main(int argc, char **argv) {
    // vector<float> a = {1, 1.2, 1.4, 1.6, 2.6, 3.6, 4.6};

    // // 4
    vector<float> a = {1, 1.2, 2.2};
    cout << leaky_relu(a) << endl;
    return 0;

    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
