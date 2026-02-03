// Write a function that reverses the words in a string (but not the characters
// in each word).

// Examples:
// - "hello world" → "world hello"
// - "one two three" → "three two one"
// - "test" → "test" (single word)

// Function: std::string reverseWords(std::string s)

// Hints:
// - Extract all words into a vector
// - Reverse the vector
// - Join them back with spaces

// Steps:
// 1. Loop through string, build words character by character
// 2. When you hit a space (or end of string), add word to vector
// 3. Reverse the vector (loop backwards or use two pointers to swap)
// 4. Build result string from reversed vector

// Similar to problem 8 (longest word) for extracting words.

#include <iostream>
#include <string>
#include <vector>

std::string reverseWords(std::string s) {
        std::vector<std::string> words;
        std::string currentWord = "";

        // extract words (same as problem 8)
        for (int i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                        if (!currentWord.empty()) {
                                words.push_back(currentWord);
                                currentWord.clear();
                        }
                } else {
                        currentWord += s[i];
                }
        }
        if (!currentWord.empty()) words.push_back(currentWord);  // last word

        // create result string
        std::string result = "";

        // build result backwards
        for (int i = words.size() - 1; i >= 0; i--) {
                result += words[i];
                if (i > 0) result += " ";
        }

        return result;
}

int main() {
        std::string s = "one two three";

        std::cout << reverseWords(s);

        return 0;
}
