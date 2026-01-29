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

std::vector<std::vector<int>> rotateMatrix(std::vector<std::vector<int>> matrix){

        return {{0}, {1}, {2}}; // placeholder for now
}

int main(){

        return 0;
}

