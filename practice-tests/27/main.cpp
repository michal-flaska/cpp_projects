// Write a function that checks if a number is a prime number.

// Examples:
// - 2 → true
// - 7 → true
// - 10 → false
// - 1 → false
// - 17 → true

// Function: bool isPrime(int n)

// Hints:
// - 1 is not prime
// - A prime number is only divisible by 1 and itself
// - Check if any number from 2 to n-1 divides n evenly (n % i == 0)
// - If you find one that does, it's not prime

#include <iostream>

bool isPrime(int n){

        if(n == 1){
                return false;
        }

        for (int i = 2; i < n; i++){
                if (n % i == 0){
                        return false;
                }
        }
        return true;
}

int main(){

        int n = 10;

        std::cout << isPrime(n);

        return 0;
}
