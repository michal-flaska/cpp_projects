// Write a function that flattens a 2D vector into a 1D vector.

// Examples:
// cpp
// {{1, 2}, {3, 4}, {5, 6}} → {1, 2, 3, 4, 5, 6}
// {{1}, {2, 3}, {4, 5, 6}} → {1, 2, 3, 4, 5, 6}
// {{}} → {}

// Function: std::vector<int> flatten(std::vector<std::vector<int>> matrix)

// Hints:
// - Nested loop: outer loop for rows, inner loop for elements in each row
// - Push each element into result vector

#include <iostream>
#include <vector>

std::vector<int> flatten(std::vector<std::vector<int>> matrix){

        std::vector<int> result = {};

        for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[i].size(); j++){
                        result.push_back(matrix[i][j]);
                }
        }

        return result;
}

void printVector(std::vector<int> v) {  // copypasted this from problem 13, 14, 15 ... 30
        std::cout << "{";
        for (int i = 0; i < v.size(); i++) {
                std::cout << v[i];
                if (i < v.size() - 1) {
                        std::cout << ", ";
                }
        }
        std::cout << "}";
}

void print2DVector(const std::vector<std::vector<int>>& v) {    // copypasted this from problem 15
        std::cout << "{" << '\n';
        for (int i = 0; i < v.size(); i++) {
                std::cout << "  {";
                for (int j = 0; j < v[i].size(); j++){
                        std::cout << v[i][j];
                        if (j < v[i].size() - 1) {
                                std::cout << ", ";
                        }
                }
                std::cout << "}";
                if (i < v.size() - 1) {
                        std::cout << ",";
                }
                std::cout << '\n';
        }
        std::cout << "}";
}

int main(){

        std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}, {5, 6}};
        std::vector<int> converted = flatten(matrix);

        std::cout << "2D Vector: " << '\n';
        print2DVector(matrix);

        std::cout << '\n' << "2D Vector converted to vector: " << '\n';
        printVector(converted);

        return 0;
}
