// Write a function that finds the second largest number in a vector.
// If there's no second largest (all numbers same, or only one number), return
// -1.

// Examples:
// {5, 2, 8, 1, 9} -> 8
// {3, 3, 3} -> -1
// {10} -> -1
// {7, 7, 5, 5} -> 5

// Function signature: int secondLargest(std::vector<int> nums)

// Hint: Find the largest first, then find the largest that's NOT the largest.

// Try it. Don't overthink.

#include <iostream>
#include <vector>

int secondLargest(std::vector<int> nums) {
        if (nums.size() < 2)
                return -1;  // Not enough numbers

        // Step 1: Find the largest
        int largest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > largest) {
                        largest = nums[i];
                }
        }

        // Step 2: Find second largest (largest number that's < largest)
        int second = -1;
        for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < largest) {  // Must be smaller than largest
                        if (second == -1 ||
                            nums[i] > second) {  // If it's bigger than current second
                                second = nums[i];
                        }
                }
        }

        return second;
}

int main() {
        std::vector<int> nums = {5, 2, 8, 1, 9};

        std::cout << "Second largest number is: " << secondLargest(nums) << '\n';

        return 0;
}
