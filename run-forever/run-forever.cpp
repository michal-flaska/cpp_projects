#include <iostream>
#include <thread>       // For using std::this_thread::sleep_for
#include <chrono>       // For time-related utilities (e.g., std::chrono::seconds)

int main() {

        bool isInfinite = true;

        std::cout << "Started doing nothing" << '\n';

        // Infinite loop that simulates "doing nothing"
        while (isInfinite == true) {
                // Sleep for 1 second per iteration to prevent maxing out CPU
                std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        return 0;
}
