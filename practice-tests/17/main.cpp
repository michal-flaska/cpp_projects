// Write a function that rotates a 2D matrix 90 degrees clockwise.

// Examples:

// {1, 2, 3}     {7, 4, 1}
// {4, 5, 6}  →  {8, 5, 2}
// {7, 8, 9}     {9, 6, 3}

// {1, 2}     {3, 1}
// {3, 4}  →  {4, 2}

// Function: std::vector<std::vector<int>> rotateMatrix(std::vector<std::vector<int>> matrix)

// Hints:
// - Element at position [row][col] moves to position [col][n-1-row] where n is matrix size
// - Create a new result matrix of same size
// - Loop through original, place each element in its new position
// - Or think visually: first column becomes first row, second column becomes second row, etc.

// Pattern to notice:
// - matrix[0][0] (1) → result[0][2]
// - matrix[0][1] (2) → result[1][2]
// - matrix[0][2] (3) → result[2][2]

// First row of input becomes last column of output (but reversed).

#include <iostream>
#include <vector>
// #include <string>
// #include <algorithm>

void printMatrix(std::vector<std::vector<int>> matrix){
        for(auto &row : matrix){
                for(int x : row){
                        std::cout << x << ' ';
                }
                std::cout << '\n';
        } // got this from geeksforgeeks.org
}

void /* std::vector<std::vector<int>> */ rotateMatrix(std::vector<std::vector<int>> &matrix){

        int n = matrix.size();

        std::vector<std::vector<int>> result(n, std::vector<int>(n));

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                result[j][n - i - 1] = matrix[i][j];
                }
        }

        matrix = result;
} // geeksforgeeks.org/dsa/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

int main(){

        std::vector<std::vector<int>> matrix = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

        std::cout << "Original Matrix: " << '\n';
        printMatrix(matrix);

        std::cout << '\n';
        rotateMatrix(matrix);

        std::cout << "Rotated Matrix: " << '\n';
        printMatrix(matrix);

        return 0;
}

// MY PERSONAL NOTES  - i spent more than 1 hour on this shit,
//                      that's why i decided to look up the solution on geeksforgeeks.org
//                      im just dumb i guess

// A matrix is just a 2D vector - a vector of vectors. (Or a 2D Array if you dont want to use vectors)

// Think of it as a grid:

// matrix[0][0]  matrix[0][1]  matrix[0][2]
// matrix[1][0]  matrix[1][1]  matrix[1][2]
// matrix[2][0]  matrix[2][1]  matrix[2][2]

// With values:

//      1  2  3
//      4  5  6
//      7  8  9

// After rotating 90° clockwise:

//      7  4  1
//      8  5  2
//      9  6  3

// Notice what happened:
// - Left column (1, 4, 7) became top row (7, 4, 1) but reversed
// - Middle column (2, 5, 8) became middle row (8, 5, 2) but reversed
// - Right column (3, 6, 9) became bottom row (9, 6, 3) but reversed
