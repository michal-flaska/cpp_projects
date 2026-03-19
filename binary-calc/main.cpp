#include <iostream>
#include <algorithm>

std::string decToBinary(int n) {
        std::string bin = "";
        while (n > 0) {
                // mod
                int bit = n % 2;
                bin.push_back('0' + bit);
                n = n / 2;
        }

        // reverse str
        reverse(bin.begin(), bin.end());
        return bin;
}

int main() {

        int n = 1200;

        std::cout << decToBinary(n);

        return 0;
}
