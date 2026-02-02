// Write a function that counts how many times each character appears in a
// string and prints it.

// Example:
// Input: "hello"
// Output:
// h: 1
// e: 1
// l: 2
// o: 1

// Function signature: `void countChars(std::string s)`

// Hints:
// - You'll need to track counts somehow (maybe another vector or array?)
// - Characters have ASCII values: 'a' = 97, 'b' = 98, etc.
// - You could use an array of size 256 (covers all ASCII chars) where index =
// character's ASCII value
// - Or loop through string and for each unique char, count how many times it
// appears

// Think about:
// - How do you store the count for each character?
// - How do you print them?

#include <iostream>
#include <string>
#include <vector>

void countChars(std::string s) {
        for (int i = 0; i < s.length(); i++) {
                char c = s[i];

                bool alreadyCounted = false;
                for (int k = 0; k < i; k++) {
                        if (s[k] == c) {
                                alreadyCounted = true;
                                break;
                        }
                }

                if (alreadyCounted)
                        continue;

                int count = 0;
                for (int j = 0; j < s.length(); j++) {
                        if (s[j] == c) {
                                count++;
                        }
                }

                std::cout << c << ": " << count << '\n';
        }
}

int main() {
        countChars("hello");

        return 0;
}
