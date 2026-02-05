// Write a function that removes all duplicate numbers from a vector, keeping only the first occurrence of each.

// Examples:
// - {1, 2, 2, 3, 4, 4, 5} → {1, 2, 3, 4, 5}
// - {5, 5, 5} → {5}
// - {1, 2, 3} → {1, 2, 3} (no duplicates)

// Function: std::vector<int> removeDuplicates(std::vector<int> nums)

// Hints:
// - Similar to problem 12 (remove duplicate characters from string)
// - For each number, check if it appeared earlier in the vector
// - If not, add it to result

#include <vector>
#include <iostream>

std::vector<int> removeDuplicates(std::vector<int> v){  // basically almost same like in problem 12
                                                        // just with vectors
                                                        // very easy

        std::vector<int> result = {};

        for(int i = 0; i < v.size(); i++){
                int c = v[i];
                bool seenBefore = false;
                for(int j = 0; j < i; j++){
                        if(c == v[j]){
                                seenBefore = true;
                                break;
                        }
                }

                if (seenBefore != true) {
                        result.push_back(c);
                }
        }

        return result;

}

void printVector(std::vector<int> v) {  // copypasted this from problem 13, 14, 15, etc.
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

        std::vector<int> v = {1, 2, 2, 3, 4, 4, 5};

        std::vector<int> v1 = removeDuplicates(v);

        std::cout << "Original vector: ";

        printVector(v);

        std::cout << '\n' << "Modified vector: ";

        printVector(v1);

        return 0;
}
