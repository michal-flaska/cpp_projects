// Write a function that calculates the nth Fibonacci number.

// - fib(0) → 0
// - fib(1) → 1
// - fib(2) → 1
// - fib(3) → 2
// - fib(4) → 3
// - fib(5) → 5
// - fib(6) → 8

// Pattern: each number is the sum of the two before it.

// Function: int fibonacci(int n)

// Hints:
// - Don't use recursion (calling the function inside itself) - it's slow
// - Use a loop instead
// - Track two previous values, calculate next one
// - Like walking: prev2, prev1, current. Each step: current = prev1 + prev2, then shift

#include <iostream>

double calculateFibonacciNthNumber(int n){ // using double because fibonacci can get pretty long

        // check n
        if(n < 0) return -1;
        if(n == 0) return 0;
        if(n == 1) return 1;

        double prev1 = 0;
        double prev2 = 1;
        double current;

        for(int i = 0 + 2; i < n; i++){ // 2 because prev1 and prev2 are already defined, if not, it would be 0 every time
                current = prev1 + prev2;
                prev1 = prev2;
                prev2 = current;
        }

        return current;
}

int main(){

        int n = 13; // should be 144

        std::cout << calculateFibonacciNthNumber(n);

        // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,
        //                                          ^^^
        //                                          13th

        return 0;
}
