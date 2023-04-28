#include <gtest/gtest.h>

#include "simple_iteration.h"

TEST(SimpleIterationTest, Test1) {
    vector<vector<double>> A = {{5, -1, 2},
                                {3, 8, -2},
                                {1, 1, 4}};
    vector<double> b = {12, -25, 6};
    double eps = 1e-6;
    int max_iter = 1000;
    vector<double> expected_x = {2, -3, 1};
    vector<double> actual_x = simple_iteration(A, b, eps, max_iter);
    ASSERT_EQ(expected_x.size(), actual_x.size());
    for (int i = 0; i < expected_x.size(); i++) {
        ASSERT_NEAR(expected_x[i], actual_x[i], eps);
    }
}

TEST(SimpleIterationTest, Test2) {
    vector<vector<double>> A = {{1, 2},
                                {3, 4}};
    vector<double> b = {5, 6};
    double eps = 1e-6;
    int max_iter = 1000;
    vector<double> expected_x = {-4, 4.5};
    vector<double> actual_x = simple_iteration(A, b, eps, max_iter);
    ASSERT_EQ(expected_x.size(), actual_x.size());
    for (int i = 0; i < expected_x.size(); i++) {
        ASSERT_NEAR(expected_x[i], actual_x[i], eps);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
