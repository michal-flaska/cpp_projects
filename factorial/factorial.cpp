#include <iostream>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n = 4;
    std::cout << "factorial " << n << " is " << factorial(n) << std::endl;
    return 0;
}

/*

// OVERCOMPLICATED

#include <iostream>
#include <stdexcept>
#include <optional>

int factorial(int n) {
        if (n < 1) {
                throw std::invalid_argument("Invalid number for calcullating factorial number.");
        }
        if (n == 1 || n == 2) {
                return n;
        }

        return n * factorial(n - 1);
}

std::optional<int> factorial2(int n) {
        if (n < 1) {
                return std::nullopt;
        }
        if (n == 1 || n == 2) {
                return n;
        }

        return n * factorial(n - 1);
}

int main(){
        try {
                int n = 4;
                auto result = factorial(n);
                std::cout << "factorial " << n << " is " << result << std::endl;
        }
        catch (const std::exception& e) {
                std::cerr << "An error occured: " << e.what() << std::endl;
        }

        ////////////

        auto result = factorial2(4);
        if (!result.has_value()) {
                std::cerr << "cannot calculate factorial" << std::endl;
        }
        return 0;
}
*/
