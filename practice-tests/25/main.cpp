// Write a function that counts how many vowels are in a string.

// Examples:
// - "hello" → 2 (e, o)
// - "aeiou" → 5
// - "xyz" → 0
// - "Programming" → 3 (o, a, i)

// Function: int countVowels(std::string s)

// Hints:
// - Vowels are: a, e, i, o, u
// - Don't forget both lowercase and uppercase (A, E, I, O, U)
// - For each character, check if it's a vowel
// - If yes, increment counter

#include <iostream>
#include <vector>
#include <string>

std::string convertToLowercase(std::string s){

        for(int i = 0; i < s.size(); i++){
                if(s[i] >= 65 && s[i] <= 90) s[i] += 32;
                else continue;
        }

        return s;
}

int countVowels(std::string s, std::vector<char> v){
        int count = 0;

        for(int i = 0; i < s.size(); i++){
                for(int j = 0; j < v.size(); j++){
                        if(s[i] == v[j]){
                                count++;
                        }
                }
        }

        return count;
}

int main(){

        std::string string = "TesTing";
        std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};   // for some reason i like chars more in numbers
                                                                // but i'll use chars here to make it more readable
                                                                // for my future self

        std::cout << "converted string: " << convertToLowercase(string) << '\n';
        std::cout << countVowels(string, vowels);

        return 0;
}
