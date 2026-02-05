// Write a function that finds the greatest common divisor (GCD) of two numbers.

// The GCD is the largest number that divides both numbers evenly.

// Examples:
// - gcd(12, 8) → 4
// - gcd(15, 25) → 5
// - gcd(7, 3) → 1
// - gcd(100, 50) → 50

// Function: int gcd(int a, int b)

// Hints:
// - Use the Euclidean algorithm: keep replacing the larger number with the remainder of dividing it by the smaller
// - When one number becomes 0, the other is the GCD

// Example with 12 and 8:
// - 12 % 8 = 4
// - 8 % 4 = 0
// - Answer: 4

#include <iostream>

int gcd(int a, int b){

        int temp;

        while(b != 0){
                temp = b;
                b = a % b;
                a = temp;
        }

        return a;
}

int main(){

        int n1 = 12;
        int n2 = 8;

        std::cout << "GCD of " << n1 << " and " << n2 << " is " << gcd(n1, n2);

        return 0;
}
