cmake_minimum_required(VERSION 3.20)
project(tdd)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(testbed
  testbed.cpp
)

include("deps.cmake")
target_link_libraries(testbed GTest::gtest)