// Write a function that checks if one string is a rotation of another.

// A rotation means you can move characters from the beginning to the end.

// Examples:
// - "abcde" and "cdeab" → true (rotated by 2)
// - "abcde" and "abced" → false (not a rotation, just rearranged)
// - "hello" and "llohe" → true (rotated by 3)
// - "abc" and "abc" → true (rotated by 0)

// Function: bool isRotation(std::string s1, std::string s2)

// Hints:
// - If lengths are different, can't be rotation
// - Trick: if s2 is a rotation of s1, then s2 will appear as a substring in
// s1+s1
// - Example: s1 = "abcde", s1+s1 = "abcdeabcde", and "cdeab" is inside it
// - Use s1.find(s2) to check if s2 is a substring (returns std::string::npos if
// not found)

// This one teaches us a clever trick.

#include <iostream>
#include <string>

bool isRotation(std::string s1, std::string s2) {
        if (s1.length() != s2.length()) {
                return false;
        } else {
                if ((s1 + s1).find(s2) != std::string::npos) {
                        return true;
                } else {
                        return false;
                }
        }
}

// can also be simplified to:
/*
bool isRotation(std::string s1, std::string s2){
    if(s1.length() != s2.length()) return false;
    return (s1 + s1).find(s2) != std::string::npos;
}
*/
// but i like it as it is currently - it's readable for me

int main() {
        std::string s1 = "abcde", s2 = "cdeab";

        if (isRotation(s1, s2)) {
                std::cout << "String is a rotation";
        } else {
                std::cout << "String is not a rotation";
        }

        return 0;
}
