#include "first_unique.h"

#include <gtest/gtest.h>

TEST(FirstUnique, BasicTest) { EXPECT_EQ('h', firstUnique("hello")); }

class FirstUniqueTest
    : public ::testing::TestWithParam<std::pair<std::string, char>> {
        // Optional: Add common setup/teardown here (e.g., initializing variables)
};

// Test logic: Validate factorial(input) == expected_output
TEST_P(FirstUniqueTest, ReturnsCorrectValue) {
        auto param = GetParam();  // Get the current (input, expected) pair
        auto input = param.first;
        auto expected = param.second;

        EXPECT_EQ(firstUnique(input), expected);  // Assertion
}

INSTANTIATE_TEST_SUITE_P(
    FirstUniqueTestCases,  // Unique name for this instantiation
    FirstUniqueTest,       // Fixture class name
    testing::Values(       // List of parameters (input, expected)
        std::make_pair("hello", 'h'), std::make_pair("leetcode", 'l'),
        std::make_pair("aabbcc", ' ')));
