#include <chrono>
#include <iostream>
#include <thread>

int main() {
        const char frames[] = {'|', '/', '-', '\\'};
        int i = 0;

        while (true) {
                std::cout << "\r" << frames[i % 4] << std::flush;
                i++;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
}
