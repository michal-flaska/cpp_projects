#include <iostream>

void setNumber(int& num); // pass by reference so changes persist
void showNumber(const int& num); // const reference to avoid unnecessary copying

int main() {
        int num = 0;
        int actionToPerform;

        while (true) {
                std::cout << "Type '1' to show the current value of number\n";
                std::cout << "Type '2' to set the value of number\n";
                std::cout << "Please select what action would you like to perform: ";
                std::cin >> actionToPerform;
                std::cout << '\n';

                switch (actionToPerform) {
                        case 1:
                                showNumber(num);
                                break;
                        case 2:
                                setNumber(num);
                                break;
                        default:
                                std::cout << "\nIncorrect option, try again.\n\n";
                }
        }

        return 0;
}

void setNumber(int& num) {
        std::cout << "Please type your desired number: ";
        std::cin >> num;
        std::cout << "Number is now: " << num << '\n';
}

void showNumber(const int& num) {
        std::cout << "Current number is: " << num << '\n';
}
