#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Dense_matrix.cpp"


TEST(DenseMatrixTest, HouseholderTest) {
    DenseMatrix A(3, 3);
    A(0, 0) = 1.0;
    A(0, 1) = 2.0;
    A(0, 2) = 3.0;
    A(1, 0) = 4.0;
    A(1, 1) = 5.0;
    A(1, 2) = 6.0;
    A(2, 0) = 7.0;
    A(2, 1) = 8.0;
    A(2, 2) = 9.0;

    DenseMatrix B(3, 3);
    B(0, 0) = -6.4807407;
    B(0, 1) = -7.3105858;
    B(0, 2) = -8.140431;
    B(1, 1) = -0.47213595;
    B(1, 2) = -1.11803399;
    B(2, 2) = 0.0;

    A.householder();

    for (int i = 0; i < A.nrows(); i++) {
        for (int j = 0; j < A.ncols(); j++) {
            EXPECT_NEAR(A(i, j), B(i, j), 1e-6);
        }
    }
}

TEST(DenseMatrixTest, HouseholderIdentityTest) {
    DenseMatrix A(3, 3);

    A.householder();

    for (int i = 0; i < A.nrows(); i++) {
        for (int j = 0; j < A.ncols(); j++) {
            if (i == j) {
                EXPECT_NEAR(A(i, j), 1.0, 1e-6);
            } else {
                EXPECT_NEAR(A(i, j), 0.0, 1e-6);
            }
        }
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
