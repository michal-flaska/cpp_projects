// Write a function that checks if a vector is a palindrome (reads the same forwards and backwards).

// Examples:
// - {1, 2, 3, 2, 1} → true
// - {1, 2, 3, 4, 5} → false
//       - {7, 7, 7} → true
//             - {1} → true

// Function: bool isPalindromeVector(std::vector<int> nums)

// Hints:
// - Similar to problem 2 (string palindrome)
// - Compare first element with last, second with second-to-last, etc.
// - Use two pointers or a single loop up to size/2

#include <iostream>
#include <vector>

bool isPalindrome(std::vector<int> v) {
        int n = v.size();

        for (int i = 0; i <= n / 2; i++) {
                if (v[i] != v[n - 1 - i]){
                        return false;
                }
        }

        return true;
}

int main() {
        std::vector<int> v = {1, 2, 3, 2, 1};

        if (isPalindrome(v)) {
                std::cout << "Vector is a palindrome" << '\n';
        } else {
                std::cout << "Vector is not a palindrome" << '\n';
        }

        return 0;
}

// notes for myself because im stupid:

// lets work with {1, 2, 3, 2, 1}:

// n = 5

// i = 0:
// - Check v[0] vs v[5-1-0] -> v[0] vs v[4] -> 1 vs 1

// i = 1:
// - Check v[1] vs v[5-1-1] -> v[1] vs v[3] -> 2 vs 2

// i = 2:
// - Check v[2] vs v[5-1-2] -> v[2] vs v[2] -> 3 vs 3

// loop stops at i = 2 because 2 <= 5/2 (which is 2).

// what n - 1 - i does:
// - n - 1 = last index
// - n - 1 - i = counting backwards from the end
