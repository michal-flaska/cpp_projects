// Write a function that checks if a string contains only digits (0-9).

// "12345" -> true
// "123a5" -> false
// "" -> false (empty string)

// Function: bool isAllDigits(std::string s)

// Hint: Characters '0' through '9' have specific ASCII values. Check if each character is between '0' and '9'.

#include <iostream>
#include <string>

bool isAllDigits(std::string s){

        int count = 0;

        for(int i = 0; i < s.length(); i++){
                if(s[i] >= 48 && s[i] <= 57) { // https://www.ascii-code.com/
                        count++;
                }
        }

        if(count == s.length()){
                return true;
        }
        else{
                return false;
        }
}

int main(){

        std::string s = "12a68";

        std::cout << isAllDigits(s);

        return 0;
}
