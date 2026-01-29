// Write a function that finds the longest consecutive sequence of identical characters in a string.

// Examples:
// - "aabbbccbb" → 3 (three b's is longest)
//  - "aabbbbcc" → 4 (four b's)
//    - "abcdef" → 1 (all single chars)
//       - "aaa" → 3

// Function: int longestStreak(std::string s)

// Hints:
// - Loop through string
// - Count consecutive same characters
// - When character changes, compare current count to max count
// - Track the longest streak we've seen
// - Don't forget to check the last streak at the end

// Similar pattern to problem 11 (compress string) but we're just tracking the max count.

#include <iostream>
#include <string>

int longestStreak(std::string s){

        int maxCount = 0;
        int i = 0;

        while(i < s.length()){
                int count = 1;
                char c = s[i];

                // count consecutive same characters (logic from problem 11)
                while(i + 1 < s.length() && s[i + 1] == c){
                        count++;
                        i++;
                }

                if(count > maxCount){
                        maxCount = count;
                }

                i++;
        }

        return maxCount;
}

int main(){

        std::string s = "aabbbccbb";

        std::cout << longestStreak(s);

        return 0;
}
