#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

int main() {
        const int w = 80;
        const int h = 24;
        float t = 0.0f;

        std::cout << "\033[2J\033[?25l";

        while (true) {
                std::cout << "\033[H";

                for (int y = 0; y < h; y++) {
                        for (int x = 0; x < w; x++) {
                                float v = std::sin(x * 0.15f + t) + std::sin(y * 0.15f + t) +
                                          std::sin((x + y) * 0.1f + t);

                                int c = (int)((v + 3) * 4);
                                const char chars[] = " .:-=+*#%@";
                                std::cout << chars[c % 10];
                        }
                        std::cout << "\n";
                }

                t += 0.1f;
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
}
