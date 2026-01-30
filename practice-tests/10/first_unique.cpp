// Write a function that finds the first non-repeating character in a string. Return the character. If all characters repeat, return ' ' (space).

// "leetcode" -> 'l' (appears once)
// "aabbcc" -> ' ' (all repeat)
// "hello" -> 'h' (first one that appears once)

// Function: char firstUnique(std::string s)

// Hint:
// - For each character, count how many times it appears in the string
// - Return the first one that appears exactly once

#include "first_unique.h"

char firstUnique(std::string s){

        for(int i = 0; i < s.length(); i++){
                char c = s[i];

                int count = 0;
                for(int j = 0; j < s.length(); j++){
                        if(s[j] == c){
                                count++;
                        }
                }

                if(count == 1){
                        return c;
                }
        }

        return ' ';
}

