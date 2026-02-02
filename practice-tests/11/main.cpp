// Write a function that compresses a string by counting repeated characters.

// "aaabbc" -> "a3b2c1"
// "hello" -> "h1e1l2o1"
// "aaa" -> "a3"

// Function: `std::string compressString(std::string s)`

// Hints:
// - Loop through the string
// - Count consecutive same characters
// - When character changes (or you reach the end), add the character + count to
// result
// - Example: "aaa" -> see 'a', count how many 'a's in a row (3), add "a3" to
// result

#include <iostream>
#include <string>

std::string compressString(std::string s) {
        std::string result = "";

        for (int i = 0; i < s.length(); i++) {
                char c = s[i];

                int count = 1;

                while (i + 1 < s.length() && s[i + 1] == c) {
                        count++;
                        i++;  // Move forward
                }

                result += c;

                result += std::to_string(count);
        }

        return result;  // should return a3b2c1
}

int main() {
        std::string s = "aaabbc";

        std::cout << compressString(s);

        return 0;
}
