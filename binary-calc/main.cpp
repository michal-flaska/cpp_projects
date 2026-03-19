#include <iostream>
#include <string>

std::string toBinary(int n) {
        if (n == 0) return "0";

        std::string result = "";

        bool negative = n < 0;
        if (negative) n = -n;

        while (n > 0) {
                result = (char)('0' + n % 2) + result;  // conv. int to 0/1 char
                                                        // newchar + result
                n = n / 2;
        }

        return negative ? "-" + result : result;
}

int main() {
        int n = 13;

        std::cout << toBinary(n);

        return 0;
}
