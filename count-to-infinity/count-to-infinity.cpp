#include <chrono>
#include <iostream>
#include <thread>

void countdown(int i);
void countToInfinity(int startingNumber, bool willCountToInfinity);

int main() {
        bool willCountToInfinity = true;
        int startingNumber = 0;
        int i = 10;

        countdown(i);
        countToInfinity(startingNumber, willCountToInfinity);

        return 0;
}

void countdown(int i) {
        std::cout << "Starting counting to infinity in:" << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        for (i; i > 0; i--) {
                std::cout << i << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "Starting infinite loop..." << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
}

void countToInfinity(int startingNumber, bool willCountToInfinity) {
        do {
                std::cout << startingNumber++ << '\n';
        } while (willCountToInfinity == true);
}
