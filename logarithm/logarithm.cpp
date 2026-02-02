#include <iostream>
#include <cmath>

int main() {
        // Natural log (base e)
        double ln = log(10);
        std::cout << "ln(10) = " << ln << std::endl;

        // Log base 10
        double log10_val = log10(100);
        std::cout << "log_10(100) = " << log10_val << std::endl;

        // Log base 2
        double log2_val = log2(8);
        std::cout << "log_2(8) = " << log2_val << std::endl;

        // Custom base (like my homework)
        // log_base(value) = ln(value) / ln(base)
        double base = 64;
        double value = 0.25; // 1/4
        double result = log(value) / log(base);
        std::cout << "log_64(1/4) = " << result << std::endl;

        return 0;
}
