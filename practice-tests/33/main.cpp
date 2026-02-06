// Write a function that counts how many times a target number appears in a vector.

// Examples:
// - {1, 2, 3, 2, 2, 4} target 2 → 3
// - {5, 5, 5, 5} target 5 → 4
// - {1, 2, 3} target 9 → 0

// Function: int countOccurrences(std::vector<int> nums, int target)

// Hints:
// - Loop through vector
// - If element equals target, increment counter

#include <iostream>
#include <vector>

void printVector(std::vector<int> v) {  // copypasted this from problem 13, 14, 15 ... 30, 31, 32 ...
        std::cout << "{";
        for (int i = 0; i < v.size(); i++) {
                std::cout << v[i];
                if (i < v.size() - 1) {
                        std::cout << ", ";
                }
        }
        std::cout << "}";
}

int countOccurences(std::vector<int> nums, int n){

        int counter = 0;

        for(int i = 0; i < nums.size(); i++){
                if(nums[i] == n){
                        counter++;
                }
                else{
                        continue;
                }
        }

        return counter;
}

int main(){

        std::vector<int> v = {1, 2, 3, 2, 2, 4};
        int n = 2;

        std::cout << "Vector: ";
        printVector(v);
        std::cout << '\n' << "Occurences of the number " << n << " in vector: " << countOccurences(v, n);

        return 0;
}
