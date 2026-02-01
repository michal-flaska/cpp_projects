#include <iostream>

int main(){
        int a = 5;      // 0101 in binary
        int b = 3;      // 0011 in binary
        int c = a ^ b;  // 0110 = 6

        std::cout       << "a: " << a << '\n'
                        << "b: " << b << '\n'
                        << "c: " << c << '\n'
        ;
}
