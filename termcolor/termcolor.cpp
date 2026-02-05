#include "termcolor.hpp"

#include <iostream>

int main() {
        std::cout << termcolor::red << "Hello " << termcolor::green << "World"
                  << termcolor::reset << std::endl;
}

// https://github.com/ikalnytskyi/termcolor
