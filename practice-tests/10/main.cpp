// Write a function that finds the first non-repeating character in a string.
// Return the character. If all characters repeat, return ' ' (space).

// "leetcode" -> 'l' (appears once)
// "aabbcc" -> ' ' (all repeat)
// "hello" -> 'h' (first one that appears once)

// Function: char firstUnique(std::string s)

// Hint:
// - For each character, count how many times it appears in the string
// - Return the first one that appears exactly once

#include <iostream>

#include "first_unique.h"

int main() {
        std::string s = "leetcode";

        std::cout << firstUnique(s);

        return 0;
}
