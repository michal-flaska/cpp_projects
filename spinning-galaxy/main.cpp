#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <thread>

const int w = 80;
const int h = 30;

const char shades[] = " .,:;irsXA253hMHGS#9B&@";

int main() {
        float t = 0.0f;

        std::cout << "\033[2J\033[?25l";

        while (true) {
                std::cout << "\033[H";

                for (int y = 0; y < h; y++) {
                        for (int x = 0; x < w; x++) {
                                // center coords
                                float nx = (x - w / 2) / (float)(w / 2);
                                float ny = (y - h / 2) / (float)(h / 2);

                                float r = sqrt(nx * nx + ny * ny);
                                float a = atan2(ny, nx);

                                // spiral arms
                                float arms = sin(a * 4 + r * 10 - t * 2);

                                // core glow
                                float core = exp(-r * 6);

                                // star noise
                                float stars = (rand() % 1000 == 0) ? 1.5f : 0.0f;

                                float intensity = arms * 0.6f * exp(-r * 2) + core * 2.0f + stars;

                                if (intensity < 0)
                                        intensity = 0;
                                if (intensity > 1.9f)
                                        intensity = 1.9f;

                                int shade = (int)(intensity * 10);
                                if (shade > 19)
                                        shade = 19;

                                std::cout << shades[shade];
                        }
                        std::cout << "\n";
                }

                t += 0.03f;
                std::this_thread::sleep_for(std::chrono::milliseconds(33));
        }
}
