#include <iostream>

int main(){
        
        int number;

        const int MIN_NUMBER = 1;
        const int MAX_NUMBER = 10;
        const int NUMBER_OF_DEATH = 6;

        std::cout << "Enter a number from " << MIN_NUMBER << " to " << MAX_NUMBER << ": ";
        std::cin >> number;

        if(number >= MIN_NUMBER && number <= MAX_NUMBER && number != NUMBER_OF_DEATH){

                std::cout << "You are safe" << '\n';

        } else if (number == 6){

                std::cout << "You died" << '\n';

        } else {
                std::cout << "Invalid number, only numbers from " << MIN_NUMBER << " to " << MAX_NUMBER << " are allowed" << '\n';
        }

}