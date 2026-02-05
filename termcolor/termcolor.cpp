#include "termcolor.hpp"

#include <iostream>

int main() {
        std::cout << termcolor::red << "Hello " << termcolor::green << "World"
                  << termcolor::reset << '\n';
}

// https://github.com/ikalnytskyi/termcolor
