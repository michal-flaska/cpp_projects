// Write a function that returns the longest word in a string. Words are separated by spaces.

// "hello world test" -> "hello" (first one if tied)
// "short longest mid" -> "longest"
// "a" -> "a"

// Function: std::string longestWord(std::string s)

// Hints:
// - Loop through string character by character
// - Build current word as you go
// - When you hit a space (or end of string), compare current word length to longest found so far
// - Track the longest word

// This one requires more thinking

#include <iostream>
#include <string>

std::string longestWord(std::string s){

        std::string currentWord = "";
        std::string longestWord = "";

        for(int i = 0; i < s.length(); i++){
                if(s[i] == ' '){
                        if(currentWord.length() > longestWord.length()){
                                longestWord = currentWord;
                        }
                        currentWord.clear();
                }
                else{
                        currentWord += s[i];
                }
        }

        if(currentWord.length() > longestWord.length()){
                longestWord = currentWord;
        }

        return longestWord;
}

int main(){

        std::string s = "howdy test string";

        std::cout << longestWord(s);

        return 0;
}
