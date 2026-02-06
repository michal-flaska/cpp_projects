// Write a function that merges two vectors by alternating elements from each.

// Examples:
// - {1, 2, 3} and {4, 5, 6} → {1, 4, 2, 5, 3, 6}
// - {1, 2} and {3, 4, 5} → {1, 3, 2, 4, 5}
// - {1} and {2, 3, 4} → {1, 2, 3, 4}

// Function: std::vector<int> mergeAlternate(std::vector<int> v1, std::vector<int> v2)

// Hints:
// - Use two indices, one for each vector
// - Alternate between adding from v1 and v2
// - When one runs out, add all remaining elements from the other

#include <iostream>
#include <vector>

std::vector<int> mergeAlternate(std::vector<int> v1, std::vector<int> v2) {
        std::vector<int> result = {};
        int i = 0, j = 0;

        while (i < v1.size() || j < v2.size()) {
                if (i < v1.size()) {
                        result.push_back(v1[i]);
                        i++;
                }
                if (j < v2.size()) {
                        result.push_back(v2[j]);
                        j++;
                }
        }

        return result;
}

void printVector(std::vector<int> v) {  // copypasted this from problem 13, 14, 15 ... 30, 31, 32, 33, 35 ...
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

        std::vector<int> v1 = {1};
        std::vector<int> v2 = {2, 3, 4};

        printVector(mergeAlternate(v1, v2)); // should print out {1, 2, 3, 4}

        return 0;
}
