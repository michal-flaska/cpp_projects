// Write a function that removes all spaces from a string and returns the new string.

// Examples:
// "hello world" -> "helloworld"
// "  test  " -> "test"
// "no spaces" -> "nospaces"

// Function signature: `std::string removeSpaces(std::string s)`

// Hints:
// - Loop through the string
// - Build a new string with only non-space characters
// - Space character is `' '` (single quotes)
// - To add a character to a string: `newString += c;` or `newString.push_back(c);`

#include <iostream>
#include <string>

std::string removeSpaces(std::string s){
        std::string result = "";

        for(int i = 0; i < s.length(); i++){
                if(s[i] != ' '){
                        result += s[i];
                }
        }

        return result;
}

int main(){
        std::string s = "hello world";
        std::string result = removeSpaces(s);
        std::cout << result << '\n';
        return 0;
}
