// DP -> Dynamic Problem

// Write a function that finds the longest increasing subsequence length in a vector.

// A subsequence doesn't have to be consecutive, just in order.

// Examples:
// - {10, 9, 2, 5, 3, 7, 101, 18} → 4 (the sequence {2, 3, 7, 101})
// - {0, 1, 0, 3, 2, 3} → 4 (the sequence {0, 1, 2, 3})
// - {7, 7, 7, 7} → 1

// Function: int longestIncreasing(std::vector<int> nums)

// Hints:
// - This one's harder - it's a dynamic programming problem
// - For each position, track the longest increasing sequence ending at that position
// - For each element, look at all previous elements that are smaller, and extend their sequences
