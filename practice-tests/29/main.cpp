// Write a function that checks if a string contains balanced parentheses.

// Balanced means every opening ( has a matching closing ) in the correct order.

// Examples:
// - "()" → true
// - "(())" → true
// - "()()" → true
// - "(()" → false (missing one closing)
// - "())" → false (extra closing)
// - ")("  → false (wrong order)

// Function: bool isBalanced(std::string s)

// Hints:
// - Use a counter
// - For each (, increment counter
// - For each ), decrement counter
// - If counter ever goes negative, it's not balanced (closing before opening)
// - At the end, counter should be 0

#include <iostream>

bool isBalanced(std::string s){

        int count = 0;

        for(int i = 0; i < s.size(); i++){
                if(s[i] == 40){
                        count++;
                }
                else if(s[i] == 41){
                        count--;
                        if(count < 0){
                                return false;
                        }
                }
                else{
                        continue;
                }
        }

        if(count != 0){
                return false;
        }
        else{
                return true;
        }
}

int main(){

        std::string s = "(hello world()())(meow)";

        if(isBalanced(s) == true){
                std::cout << "The string is balanced";
        }
        else{
                std::cout << "The string is not balanced";
        }

        return 0;
}
