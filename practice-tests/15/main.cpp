// Write a function that finds all pairs of numbers in a vector that add up to a target sum.

// Examples:
// - {2, 7, 11, 15} target 9 → {{2, 7}}
// - {1, 2, 3, 4, 5} target 6 → {{1, 5}, {2, 4}}
// - {1, 1, 1, 1} target 2 → {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}} (all pairs)
// - {1, 2, 3} target 10 → {} (no pairs)

// Function: std::vector<std::vector<int>> findPairs(std::vector<int> nums, int target)

// Hints:
// - Check every possible pair (nested loops)
// - For each pair (i, j), check if nums[i] + nums[j] == target
// - Make sure i < j so you don't count the same pair twice
// - Each pair is a vector of 2 numbers

// Return format:
// Result is a vector of vectors. Each inner vector has 2 numbers.

// This one's about nested loops and understanding 2D vectors.

#include <iostream>
#include <vector>
// #include <string>
// #include <algorithm>

