// Write a function that capitalizes the first letter of each word in a string.

// "hello world" -> "Hello World"
// "test code" -> "Test Code"

// Function: std::string capitalizeWords(std::string s)

// Hints:
// - Lowercase 'a' is 97, uppercase 'A' is 65 (difference of 32)
// - To capitalize: c = c - 32 (or use toupper(c) function)
// - First character is always capitalized
// - Any character after a space should be capitalized

#include <iostream>
#include <string>

std::string capitalizeWords(std::string s) {
        for (int i = 0; i < s.length(); i++) {
                if (i == 0) {
                        if (s[i] >= 97 && s[i] <= 122) {
                                s[i] -= 32;
                        }
                } else {
                        if (s[i - 1] == ' ') {
                                s[i] -= 32;
                        }
                }
        }

        return s;
}

int main() {
        std::string s = "hello world";

        std::cout << capitalizeWords(s) << '\n';

        return 0;
}
