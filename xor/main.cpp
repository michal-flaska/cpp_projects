#include <iostream>

int main(){
        int a = 5;      // 0101 in binary
        int b = 3;      // 0011 in binary
        int c = a ^ b;  // 0110 = 6

        // Bit by bit:
        // 0^0=0, 1^0=1, 0^1=1, 1^1=0

        // xor table, i guess
        //      0 ^ 0 = 0
        //      0 ^ 1 = 1
        //      1 ^ 0 = 1
        //      1 ^ 1 = 0

        std::cout       << "a: " << a << '\n'
                        << "b: " << b << '\n'
                        << "c: " << c << '\n'
        ;
}
