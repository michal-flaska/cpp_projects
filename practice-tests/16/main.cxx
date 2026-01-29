// Write a function that finds the missing number in a sequence from 0 to n.

// Given a vector containing n distinct numbers from the range [0, n], find the one missing number.

// Examples:
// - {3, 0, 1} → 2 (range is 0-3, missing 2)
// - {0, 1} → 2 (range is 0-2, missing 2)
// - {9, 6, 4, 2, 3, 5, 7, 0, 1} → 8
// - {0} → 1

// Function: int findMissing(std::vector<int> nums)

// Hints:
// - The vector has n numbers from range 0 to n, so one is missing
// - Sum of 0 to n is: n * (n + 1) / 2
// - Calculate what the sum should be, calculate actual sum, find the difference

// Example:
// - {3, 0, 1} has 3 numbers, so range is 0-3 (that's 4 numbers total)
// - Expected sum: 0+1+2+3 = 6
// - Actual sum: 3+0+1 = 4
// - Missing: 6 - 4 = 2

// Try it. This one teaches you a math trick.

#include <iostream>
#include <vector>
// #include <string>
// #include <algorithm>

int findMissing(std::vector<int> nums){

        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
        }

        int expSum = n * (n + 1) / 2;

        return expSum - sum;
}

int main(){

        std::vector<int> v = {9, 6, 4, 2, 3, 5, 7, 0, 1}; // 8 is missing

        std::cout << findMissing(v);

        return 0;
}
