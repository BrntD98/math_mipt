cmake_minimum_required(VERSION 3.0)

add_executable(test main.cpp)
target_link_libraries(test gtest gmock pthread)
