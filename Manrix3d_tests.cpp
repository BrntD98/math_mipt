#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NEW_matrix3d.hpp"
#include "progonka.hpp"

TEST(test1, _4x4_matrix){
    std::vector<elements<double>> v = {{0,2,1},{1,2,1},{1,2,1},{1,2,0}};
    std::vector<double> solution = {1.0, 1.0, 1.0, 1.0};
    std::vector<double> f = {3,4,4,3};
    matrix3d matrix(v);
    std::vector<double> x = progonka(matrix,f);
    for (int i = 0; i < x.size(); i++){
        ASSERT_NEAR(x[i], solution[i], 0.01);
    }

}
    
    


TEST(test2, _4x4_matrix){
    std::vector<elements<double>> v = {{0,1,2},{3,4,5},{6,7,8},{9,10,0}};
    std::vector<double> solution = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> f = {5, 26, 65, 67};
    matrix3d matrix(v);
    std::vector<double> z = progonka(matrix,f);
    for (int i = 0; i < z.size(); i++){
        ASSERT_NEAR(z[i], solution[i], 0.01);
    }
}
TEST(test3, _4x4_matrix){
    std::vector<elements<double>> v = {{0,2,3},{6,3,9},{2,5,2},{4,3,0}};
    std::vector<double> solution = {3.0, 5.0, 4.0, 2.0};
    std::vector<double> f = {21.0, 69.0, 34.0, 22.0};
    matrix3d matrix(v);
    std::vector<double> x = progonka(matrix,f);
    for (int i = 0; i < x.size(); i++){
        ASSERT_NEAR(x[i], solution[i], 0.01);
    }

}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}
