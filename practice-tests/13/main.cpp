// Write a function that rotates an array to the right by k positions.

// Examples:
// - {1, 2, 3, 4, 5} rotated by 2 → {4, 5, 1, 2, 3}
// - {1, 2, 3} rotated by 1 → {3, 1, 2}
// - {1, 2, 3, 4} rotated by 4 → {1, 2, 3, 4} (full rotation)

// Function: std::vector<int> rotateArray(std::vector<int> arr, int k)

// Hints:
// - If k is larger than array size, use k % arr.size() (rotating by size brings
// you back to start)
// - Think about which elements move where
// - You could create a new vector and place elements in their new positions
// - Element at index i moves to index (i + k) % arr.size()

#include <iostream>
// #include <string>
#include <vector>

std::vector<int> rotateArray(std::vector<int> v, int k) {
        std::vector<int> result = {};

        k = k % v.size();

        for (int i = v.size() - k; i < v.size(); i++) {
                result.push_back(v[i]);
        }

        for (int i = 0; i < v.size() - k; i++) {
                result.push_back(v[i]);
        }

        return result;
}

void printVector(std::vector<int> v) {
        std::cout << "{";
        for (int i = 0; i < v.size(); i++) {
                std::cout << v[i];
                if (i < v.size() - 1)
                        std::cout << ", ";
        }
        std::cout << "}";
}

int main() {
        std::vector<int> v = {1, 2, 3, 4, 5};
        int k = 2;

        std::cout << "Original Array: ";
        printVector(v);
        std::cout << '\n';

        std::cout << "Modified Array: ";
        printVector(rotateArray(v, k));

        return 0;
}
