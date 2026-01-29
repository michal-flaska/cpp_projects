// Write a function that finds the first duplicate element in a vector. Return the first number that appears twice. If no duplicates, return -1.

// Examples:
// - {1, 2, 3, 2, 4} → 2 (first duplicate)
// - {1, 2, 3, 1, 2} → 1 (appears twice before 2 does)
// -    {1, 2, 3, 4} → -1 (no duplicates)
// -          {5, 5} → 5

// Function: int firstDuplicate(std::vector<int> nums)

// Hints:
// - Loop through the vector
// - For each element, check if it appeared earlier
// - Use a nested loop to check previous elements
// - Return as soon as you find a duplicate

// Similar to problem 12 (remove duplicates) but different logic. But still very easy ;)

#include <iostream>
#include <vector>

int firstDuplicate(std::vector<int> nums){

        int n;

        for(int i = 0; i < nums.size(); i++){

                n = nums[i];

                for(int j = 0; j < i; j++){
                        if(nums[j] == n){
                                return n;
                        }
                }
        }

        return -1;
}

int main(){

        std::vector<int> nums = {1, 2, 3, 2, 4};

        std::cout << firstDuplicate(nums);

        return 0;
}
