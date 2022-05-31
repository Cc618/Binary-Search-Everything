#include <bits/stdc++.h>

using namespace std;

// $BEGIN$
int leaky_relu(const vector<float> &values) {
    // FIXME
}
// $END$

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
    ::testing::InitGoogleTest(&argc, argv);
    int ret{RUN_ALL_TESTS()};
    return ret;
}
