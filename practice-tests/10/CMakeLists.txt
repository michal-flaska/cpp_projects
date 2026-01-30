cmake_minimum_required(VERSION 3.14)
project(first_unique)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(first_unique STATIC first_unique.cpp)

# test

enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(
  first_unique-test
  first_unique-test.cpp
)
target_link_libraries(
  first_unique-test
  first_unique
  GTest::gtest_main
)

gtest_discover_tests(first_unique-test PROPERTIES DEPENDS first_unique-test)
