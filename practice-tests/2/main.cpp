// Write a function that takes a string and returns `true` if it's a palindrome (reads same forwards and backwards), `false` otherwise.

// Examples:
// "racecar" -> true
// "hello" -> false
// "mom" -> true
// "a" -> true


// Requirements:
// - Function signature: `bool isPalindrome(std::string str)`
// - Case-sensitive (don't worry about uppercase/lowercase)
// - Use `<string>` library

// **Hints:**
// - `str.length()` or `str.size()` gets string length
// - `str[i]` accesses character at index i
// - Compare first char with last, second with second-to-last, etc.

// Write it from scratch. Include a main() to test it.

#include <iostream>
#include <string>

bool isPalindrome(std::string s){

        int n = s.length();


        for (int i = 0; i <= n/2; i++) {
                if (s[i] != s[n-1-i])
                return false;
        }

        return true;
}

int main(){

        std::string s;

        std::cout << "Enter a string: ";
        std::cin >> s;

        if(isPalindrome(s)){
                std::cout << '\n' << "Word " << s << " is a palindrome" << '\n';
        }
        else{
                std::cout << '\n' << "Word " << s << " is not a palindrome" << '\n';
        }

        return 0;
}
