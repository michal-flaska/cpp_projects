#include <iostream>

void setNumber(int num);
void showNumber(int num);

int main(){

        int num = 0; // Start as 0
        int actionToPerform;
        
        while (0 != 1){
                std::cout << "Type '1' to show the current value of number" << '\n';
                std::cout << "Type '2' to set the value of number" << '\n';
                std::cout << "Please select what action would you like to perform: ";
                std::cin >> actionToPerform;
                std::cout << '\n';

                switch(actionToPerform){
                        case 1: showNumber(num);
                                break;
                        case 2: setNumber(num);
                                break;
                        default: std::cout << '\n' << "Incorrect option, try again." << '\n' << '\n';
                }
        }

        return 0;
}

void setNumber(int num){
        std::cout << "Please type your desired number: ";
        std::cin >> num;
        std::cout << "Number is now: " << num << '\n';
}

void showNumber(int num){
        std::cout << "Current number is: " << num << '\n';
}