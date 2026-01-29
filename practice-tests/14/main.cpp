// Write a function that merges two sorted vectors into one sorted vector.

// Examples:
// - {1, 3, 5} and {2, 4, 6} → {1, 2, 3, 4, 5, 6}
// - {1, 2, 3} and {4, 5} → {1, 2, 3, 4, 5}
// - {5, 10} and {1, 3, 7} → {1, 3, 5, 7, 10}

// Function: std::vector<int> mergeSorted(std::vector<int> v1, std::vector<int> v2)

// Hints:
// - Both input vectors are already sorted
// - Use two pointers (indices), one for each vector
// - Compare elements at both pointers, add the smaller one to result
// - Move the pointer of whichever element you added
// - When one vector runs out, add all remaining elements from the other

// Example walkthrough for {1, 3} and {2, 4}:
// - Compare 1 and 2 → add 1
// - Compare 3 and 2 → add 2
// - Compare 3 and 4 → add 3
// - Only 4 left → add 4
// - Result: {1, 2, 3, 4}

// Don't use std::sort() - that defeats the point. Use the fact that both are already sorted.

#include <iostream>
#include <vector>
// #include <algorithm>

std::vector<int> mergeSorted(std::vector<int> v1, std::vector<int> v2) {

        std::vector<int> result;

        result.reserve(v1.size() + v2.size());

        size_t i = 0, j = 0;

        while (i < v1.size() && j < v2.size()) {
                if (v1[i] <= v2[j]) {
                        result.push_back(v1[i]);
                        ++i;
                }
                else {
                        result.push_back(v2[j]);
                        ++j;
                }
        }

        while (i < v1.size()) {
                result.push_back(v1[i]);
                ++i;
        }

        while (j < v2.size()) {
                result.push_back(v2[j]);
                ++j;
        }

        return result;
}

void printVector(std::vector<int> v){ // copypasted this from problem 13
        std::cout << "{";
        for(int i = 0; i < v.size(); i++){
                std::cout << v[i];
                if(i < v.size() - 1) std::cout << ", ";
        }
        std::cout << "}";
}


int main(){

        std::vector<int> v1 = {1, 3, 5};
        std::vector<int> v2 = {2, 4, 6};

        std::vector<int> result = mergeSorted(v1, v2);

        printVector(result);

        return 0;
}
