// Write a function that shifts all zeros in a vector to the end while maintaining the order of non-zero elements.

// Examples:
// - {0, 1, 0, 3, 12} → {1, 3, 12, 0, 0}
// - {1, 2, 3} → {1, 2, 3} (no zeros)
// - {0, 0, 0} → {0, 0, 0}

// Function: std::vector<int> moveZeros(std::vector<int> nums)

// Hints:
// - Loop through vector
// - Add all non-zero elements to result first
// - Then add all the zeros at the end
// - Count how many zeros you skipped

#include <iostream>
#include <vector>

std::vector<int> moveZeros(std::vector<int> nums){ // very easy

        std::vector<int> result = {};
        int counter = 0;

        for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                        counter++;
                }
                else{
                        result.push_back(nums[i]);
                }
        }

        if(counter != 0){
                for(int j = 0; j < counter; j++){
                        result.push_back(0);
                }
        }

        return result;
}

void printVector(std::vector<int> v) {  // copypasted this from problem 13, 14, 15 ... 30, 31, 32, 33 ...
        std::cout << "{";
        for (int i = 0; i < v.size(); i++) {
                std::cout << v[i];
                if (i < v.size() - 1) {
                        std::cout << ", ";
                }
        }
        std::cout << "}";
}

int main(){

        std::vector<int> v = {0, 1, 0, 3, 12};

        std::cout << "Original vector: ";
        printVector(v);

        std::cout << '\n' << "Modified vector: ";
        printVector(moveZeros(v));

        return 0;
}
