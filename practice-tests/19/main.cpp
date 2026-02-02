// Write a function that removes all occurrences of a specific value from a
// vector.

// Examples:
// - {1, 2, 3, 2, 4} remove 2 → {1, 3, 4}
// - {5, 5, 5, 5} remove 5 → {}
// - {1, 2, 3} remove 9 → {1, 2, 3}

// Function: std::vector<int> removeValue(std::vector<int> nums, int val)

// Hints:
// - Create a new result vector
// - Loop through original vector
// - Only add elements that aren't equal to val

#include <iostream>
#include <vector>

void printVector(
    std::vector<int> v) {  // copypasted this from problem 13, 14, 15
        std::cout << "{";
        for (int i = 0; i < v.size(); i++) {
                std::cout << v[i];
                if (i < v.size() - 1) {
                        std::cout << ", ";
                }
        }
        std::cout << "}";
}

std::vector<int> removeValue(std::vector<int> nums, int val) {
        std::vector<int> result = {};

        for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != val) {
                        result.push_back(nums[i]);
                }
        }

        return result;
}

int main() {
        std::vector<int> v = {1, 2, 3, 2, 4};
        int n = 2;

        printVector(removeValue(v, n));

        return 0;
}
