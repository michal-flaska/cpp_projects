#include <iostream>

int main(){
        
        int number;

        std::cout << "Enter a number from 1 to 10: ";
        std::cin >> number;

        if(number >= 1 && number <= 10 && number != 6){

                std::cout << "You entered a valid number." << '\n';

        } else if (number == 6){

                std::cout << "You have a bad day." << '\n';

                while(number == 6){
                        std::cout << "Hello World" << '\n'; // Inf. Loop pre matka
                }

        } else {
                std::cout << "You entered an invalid number." << '\n';
        }

}