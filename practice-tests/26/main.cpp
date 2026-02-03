// Write a function that converts a decimal number to binary and returns it as a string.

// Examples:
// - 5 → "101"
// - 10 → "1010"
// - 0 → "0"
// - 255 → "11111111"

// Function: std::string toBinary(int n)

// Hints:
// - Repeatedly divide by 2
// - The remainders (n % 2) give you the binary digits, but in reverse order
// - Keep dividing until n becomes 0
// - Reverse the result at the end (or build it from the front)

// Example with 10:
// - 10 / 2 = 5, remainder 0
// - 5 / 2 = 2, remainder 1
// - 2 / 2 = 1, remainder 0
// - 1 / 2 = 0, remainder 1
// - Read remainders backwards: 1010

#include <iostream>
#include <vector>

std::string toBinary(int n) {
        if (n == 0) return "0";

        std::string result = "";

        while (n != 0) {
                result = std::to_string(n % 2) + result;
                n = n / 2;
        }

        return result;
}

int main() {
        int n = 10;  // 1010

        std::cout << toBinary(n);

        return 0;
}
