// Write a function that checks if a vector is sorted in ascending order.

// Examples:
// - {1, 2, 3, 4, 5} → true
// -    {1, 3, 2, 4} → false
// -       {5, 5, 5} → true (equal values are fine)
// -             {1} → true
// -              {} → true (empty is considered sorted)

// Function: bool isSorted(std::vector<int> nums)

// Hints:
// - Loop through the vector
// - Compare each element with the next one
// - If any element is greater than the next, return false
// - If you get through the whole loop, return true

#include <iostream>
#include <vector>

bool isSorted(std::vector<int> nums) {
        for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] > nums[i]) {
                        return false;
                }
        }

        return true;
}

int main() {
        std::vector<int> nums = {1, 2, 3, 4, 5};

        if (isSorted(nums)) {
                std::cout << "Numbers are sorted";
        } else {
                std::cout << "Numbers are not sorted";
        }

        return 0;
}
