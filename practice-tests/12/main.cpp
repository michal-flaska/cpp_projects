// Write a function that removes duplicate characters from a string, keeping
// only the first occurrence of each.

// "hello" -> "helo" (removed second 'l')
// "aabbcc" -> "abc"
// "programming" -> "progamin"

// Function: `std::string removeDuplicates(std::string s)`

// Hints:
// - Loop through each character
// - For each character, check if it appeared earlier in the string
// - If it's the first time seeing it, add it to result
// - If you've seen it before, skip it

// Check if 'c' already appeared before index i. If not, add it to result

#include <iostream>
#include <string>

std::string removeDuplicates(std::string s) {
        std::string result = "";

        for (int i = 0; i < s.length(); i++) {
                char c = s[i];

                // check if char c appeared before index i
                bool seenBefore = false;
                for (int j = 0; j < i; j++) {  // only check BEFORE current position
                        if (s[j] == c) {
                                seenBefore = true;
                                break;
                        }
                }

                // if we havent seen it before then add it
                if (seenBefore != true) {
                        result += c;
                }
        }

        return result;
}

int main() {
        std::string s = "hello";

        std::cout << removeDuplicates(s);

        return 0;
}
