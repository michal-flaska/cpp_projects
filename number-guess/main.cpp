/*
program picks random number 1–10
u guess until correct
print too high / too low
count attempts
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
        srand(time(0));

        int minNum = 0;
        int maxNum = 10;

        int guess = 0;

        int attempts = 0;
        int maxAttempts = 2;

        int randomNum = rand() % (maxNum - minNum + 1) + minNum;

        while (guess != randomNum && attempts < maxAttempts) {
                std::cout << "Enter your guess (" << minNum << "-" << maxNum << "):\n";
                std::cin >> guess;

                attempts++;

                if (guess > randomNum) {
                        std::cout << "too high\n";
                } else if (guess < randomNum) {
                        std::cout << "too low\n";
                }
        }

        if (guess == randomNum) {
                std::cout << "you won in " << attempts << " tries\n";
        } else {
                std::cout << "you lose. number was " << randomNum << "\n";
        }

        return 0;
}
