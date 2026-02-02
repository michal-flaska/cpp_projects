#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

int main() {
        const int w = 80;
        const int h = 30;

        const char fireChars[] = " .:-=+*#%@";
        std::vector<int> fire(w * h, 0);

        for (int x = 0; x < w; x++)
                fire[(h - 1) * w + x] = 9;

        std::cout << "\033[2J\033[?25l";

        while (true) {
                std::cout << "\033[H";

                for (int y = 0; y < h - 1; y++) {
                        for (int x = 0; x < w; x++) {
                                int below = fire[(y + 1) * w + x];
                                int decay = std::rand() % 3;
                                int val = below - decay;
                                if (val < 0)
                                        val = 0;
                                fire[y * w + ((x - decay + w) % w)] = val;
                                std::cout << fireChars[val];
                        }
                        std::cout << "\n";
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(35));
        }
}
