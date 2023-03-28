#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MatrixCSR.h"
#include "MatrixCSR.cpp"

TEST(MatrixCSRTest, TestConstructor) {
  MatrixCSR matrix(3, 3);
  
  EXPECT_EQ(matrix.getNumRows(), 3);
  EXPECT_EQ(matrix.getNumCols(), 3);
}

TEST(MatrixCSRTest, TestSetAndGetElement) {
  MatrixCSR matrix(3, 3);
  
  matrix.setElement(0, 0, 1);
  matrix.setElement(0, 1, 2);
  matrix.setElement(0, 2, 3);
  matrix.setElement(1, 0, 4);
  matrix.setElement(1, 1, 5);
  matrix.setElement(1, 2, 6);
  
  EXPECT_EQ(matrix.getElement(0, 0), 1);
  EXPECT_EQ(matrix.getElement(0, 1), 2);
  EXPECT_EQ(matrix.getElement(0, 2), 3);
  EXPECT_EQ(matrix.getElement(1, 0), 4);
  EXPECT_EQ(matrix.getElement(1, 1), 0);
  EXPECT_EQ(matrix.getElement(1, 2), 0);
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}
