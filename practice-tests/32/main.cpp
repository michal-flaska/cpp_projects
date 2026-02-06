// Write a function that finds the intersection of two vectors (numbers that appear in both).

// Examples:
// - {1, 2, 3} and {2, 3, 4} → {2, 3}
// - {1, 2, 3} and {4, 5, 6} → {} (no common elements)
// - {1, 1, 2} and {1, 2, 2} → {1, 2} (no duplicates in result)

// Function: std::vector<int> intersection(std::vector<int> v1, std::vector<int> v2)

// Hints:
// - Loop through first vector
// - For each element, check if it exists in second vector
// - If yes, add to result (but make sure it's not already in result to avoid duplicates)

#include <iostream>
#include <vector>

void printVector(std::vector<int> v) {  // copypasted this from problem 13, 14, 15 ... 30, 31
        std::cout << "{";
        for (int i = 0; i < v.size(); i++) {
                std::cout << v[i];
                if (i < v.size() - 1) {
                        std::cout << ", ";
                }
        }
        std::cout << "}";
}

std::vector<int> intersection(std::vector<int> v1, std::vector<int> v2){

        std::vector<int> result = {};

        // I WAS OVERTHINKING THIS PART A LOT...
        // THATS WHY IT TOOK ME SO LONG TO SOLVE THIS PROBLEM
        for (int i = 0; i < v1.size(); i++) {
                int current = v1[i];

                // check if current exists in v2
                bool inV2 = false;
                for (int j = 0; j < v2.size(); j++) {
                        if (v2[j] == current) {
                                inV2 = true;
                                break;
                        }
                }

                // check if current is already in result (to avoid duplicates)
                bool alreadyInResult = false;
                for (int k = 0; k < result.size(); k++) {
                        if (result[k] == current) {
                                alreadyInResult = true;
                                break;
                        }
                }

                // ff in v2 AND not already in result then add it
                if (inV2 && !alreadyInResult) {
                        result.push_back(current);
                }
        }

        return result;
}

int main(){

        std::vector<int> v1 = {1, 1, 2};
        std::vector<int> v2 = {1, 2, 2};

        std::vector<int> v3 = intersection(v1, v2);

        std::cout << "Vector 1: ";
        printVector(v1);
        std::cout << '\n' << "Vector 2: ";
        printVector(v2);
        std::cout << '\n' << '\n' << "Intersection of vector 1 and 2: ";
        printVector(v3);

        return 0;
}
