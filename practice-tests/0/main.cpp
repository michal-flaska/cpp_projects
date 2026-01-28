/*
// Print numbers 1 to 100

#include <iostream>

int main(){

        for(int i = 0; i < 100; i++){
                std::cout << i + 1 << '\n';
        }

        return 0;
}
*/

/*
// Print even numbers from 1 to 50

#include <iostream>

int main(){

        for(int i = 1; i < 50; i++){
                if(i % 2 == 0){
                        std::cout << i << '\n';
                }
        }

        return 0;
}
*/

/*
// Ask user for a number, print countdown from that number to 0

#include <iostream>
#include <string>

int main(){

        int myNum;

        std::cout << "Enter number: ";
        std::cin >> myNum;

        for(int i = myNum; i > -1; i--){
                std::cout << i << '\n';
        }

        return 0;
}
*/

/*
// Ask user for a number, print a square of stars that size (5 -> 5x5 grid of stars)

#include <iostream>

int main(){
        char myChar = '*';
        int size;

        std::cout << "Enter a number: ";
        std::cin >> size;

        for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                        std::cout << myChar << " ";
                }

                std::cout << '\n';
        }
}
*/

/*
// Print multiplication table for number 7 (7x1=7, 7x2=14, etc up to 7x10)

#include <iostream>

int main(){

        int num = 7;

        for(int i = 1; i < 11; i++){ // 11, so it will multiply by 10 too
                std::cout << num * i << '\n';
        }

        return 0;
}
*/

// LEVEL 2 - DONE

// LEVEL 3 - DONE
