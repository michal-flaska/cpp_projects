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

std::string longestWord(std::string s){

        // taking a break, but ill write how can i do this
        // we will have two temp variables for storing current longest word and how many characters it have
        // we will move next to each word,
        //      if the next word is longer than the current longest, replace the longest word temp variable and its character count temp var
        //      if not, move to next word

        return s;
}

int main(){

        std::string s = "hello world test";

        std::cout << longestWord(s);

        return 0;
}
