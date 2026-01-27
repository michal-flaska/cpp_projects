#include <iostream>
#include "termcolor.hpp"

int main() {
    std::cout << termcolor::red << "Hello "
              << termcolor::green << "World"
              << termcolor::reset << std::endl;
}
