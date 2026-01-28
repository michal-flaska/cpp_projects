// Write a function that checks if two strings are anagrams (contain the same letters, just rearranged).

// "listen" and "silent" -> true
// "hello" and "world" -> false
// "abc" and "cab" -> true
// "test" and "testing" -> false (different lengths)

// Function: `bool isAnagram(std::string s1, std::string s2)`

// Hints:
// - If lengths are different, they can't be anagrams
// - Count how many times each letter appears in both strings
// - If counts match for all letters, they're anagrams
// - OR: sort both strings and compare if they're equal (simpler but you'd need to learn sorting)

// Approach without sorting:
// - For each character in s1, count how many times it appears in s1 and s2
// - If counts don't match, return false

#include <iostream>
#include <string>
#include <algorithm>    // For std::sort

bool isAnagram(std::string s1, std::string s2){
        if(s1.length() != s2.length()){
                return false;
        }

        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        return s1 == s2;
}

int main(){
        std::string s1 = "listen";
        std::string s2 = "silent";

        std::cout << isAnagram(s1, s2) << '\n';

        return 0;
}

// i thought that when comparing strings, it compares the ascii values...
// thats why i was overcomplicating things
// now i know i was doing wrong
