// Write a function that finds all pairs of numbers in a vector that add up to a
// target sum.

// Examples:
// - {2, 7, 11, 15} target 9 → {{2, 7}}
// - {1, 2, 3, 4, 5} target 6 → {{1, 5}, {2, 4}}
// - {1, 1, 1, 1} target 2 → {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}}
// (all pairs)
// - {1, 2, 3} target 10 → {} (no pairs)

// Function: std::vector<std::vector<int>> findPairs(std::vector<int> nums, int
// target)

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

std::vector<std::vector<int>> findPairs(std::vector<int> nums, int target) {
        std::vector<std::vector<int>> result;  // { {0, 0}, {0, 0} };

        for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                        if (nums[i] + nums[j] == target &&
                            i < j /* so we dont count the same pair twice */) {
                                result.push_back({nums[i], nums[j]});
                        }
                }
        }

        return result;
}

void printVector(std::vector<int> v) {  // copypasted this from problem 13, 14
        std::cout << "{";
        for (int i = 0; i < v.size(); i++) {
                std::cout << v[i];
                if (i < v.size() - 1) {
                        std::cout << ", ";
                }
        }
        std::cout << "}";
}

void print2DVector(
    const std::vector<std::vector<int>>& v) {  // copypasted this from problem 13, 14 - and told chatgpt to
                                               // modify it it to work with 2d vectors
                                               //                                                ^ ^ ^ ^ because
                                               //                                                im lazy :/
                                               // should print:
                                               // {
                                               //   {1, 2, 3},
                                               //   {4, 5, 6},
                                               //   {7, 8, 9}
                                               // }
        std::cout << "{" << '\n';
        for (int i = 0; i < v.size(); i++) {
                std::cout << "  {";
                for (int j = 0; j < v[i].size(); j++) {
                        std::cout << v[i][j];
                        if (j < v[i].size() - 1) {
                                std::cout << ", ";
                        }
                }
                std::cout << "}";
                if (i < v.size() - 1) {
                        std::cout << ",";
                }
                std::cout << '\n';
        }
        std::cout << "}";
}

int main() {
        std::vector<int> v = {2, 7, 11, 15};
        int t = 18;  // target

        std::cout << "Original Vector: ";
        printVector(v);
        std::cout << '\n';

        std::cout << "Modified Vector: ";
        print2DVector(findPairs(v, t));

        return 0;
}
