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
#include <vector>

std::vector<char> stringToCharArray(const std::string& str) {
    return std::vector<char>(str.begin(), str.end());
}

std::vector<char> sort(std::vector<char> array, int size){ // this is from my c++ tutorial notes

        int temp;
        for(int i = 0; i < size - 1; i++){
                for(int j = 0; j < size - i - 1; j++){
                        if(array[j] > array[j + 1]){ // if we'd like to change it to descending order, we can change the '>' operator to '<' at this line
                                temp = array [j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                        }
                }
        }
}

bool isAnagram(std::string s1, std::string s2){

        if(s1.length() == s2.length()){
                for(int i = 0; i < s1.length(), i++){
                        if(s1[i] == s2[i]){
                                continue;
                        }
                        else{
                                return false;
                        }
                }
        }

        return true;
}

int main(){

        // std::string s1 = "hello";
        // std::string s2 = "world";

        std::string s1 = "listen";
        std::string s2 = "silent";

        isAnagram(sort(stringToCharArray(s1, s1.length())), sort(stringToCharArray(s2, s2.length())));

        return 0;
}
