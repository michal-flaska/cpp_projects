// Write a function that removes duplicate characters from a string, keeping only the first occurrence of each.

// "hello" -> "helo" (removed second 'l')
// "aabbcc" -> "abc"
// "programming" -> "progamin"

// Function: `std::string removeDuplicates(std::string s)`

// **Hints:**
// - Loop through each character
// - For each character, check if it appeared earlier in the string
// - If it's the first time seeing it, add it to result
// - If you've seen it before, skip it

// Check if 'c' already appeared before index i. If not, add it to result

#include <iostream>
#include <string>

std::string removeDuplicates(std::string s){

        std::string result = "";

        for(int i = 0; i < s.length(); i++){

                char c = s[i];

                // Check if 'c' already appeared before index i. If not, add it to result

                // taking a break
        }

        return result;
}

int main(){

        std::string s = "hello";

        return 0;
}
