#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
        srand(time(0));

        int bulletPosition = (rand() % 6) + 1;
        int trigger = 1;

        std::cout << "Russian Roulette - 6 chambers, 1 bullet" << '\n';
        std::cout << "Press Enter to pull the trigger..." << '\n';

        while (trigger <= 6) {
                std::cin.get();

                if (trigger == bulletPosition) {
                        std::cout << "BANG! You're dead." << '\n';
                        return 0;
                }

                std::cout << "Click... you're safe. ";
                if (trigger < 6) {
                        std::cout << "Pull again? (Press Enter)" << '\n';
                }
                trigger++;
        }

        std::cout << "You survived all 6 chambers!" << '\n';
        return 0;
}

/*

// OLD HARCODED VERSION

#include <iostream>

int main(){

        int number;

        const int MIN_NUMBER = 1;
        const int MAX_NUMBER = 10;
        const int NUMBER_OF_DEATH = 6;

        std::cout << "Enter a number from " << MIN_NUMBER << " to " <<
MAX_NUMBER << ": "; std::cin >> number;

        if(number >= MIN_NUMBER && number <= MAX_NUMBER && number !=
NUMBER_OF_DEATH){

                std::cout << "You are safe" << '\n';

        } else if (number == 6){

                std::cout << "You died" << '\n';

        } else {
                std::cout << "Invalid number, only numbers from " << MIN_NUMBER
<< " to " << MAX_NUMBER << " are allowed" << '\n';
        }

}
*/
