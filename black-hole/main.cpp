/*

// i commented out the original code and made a new and better one

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

const int w = 80;
const int h = 30;

// shade based on brightness
char shade(float v) {
    const char chars[] = " .:-=+*#%@";
    int i = (int)(v * 9);
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return chars[i];
}

int main() {
    float t = 0;

    std::cout << "\033[2J\033[?25l";

    while (true) {
        std::cout << "\033[H";

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                // normalized coords
                float nx = (x - w / 2) / 15.0f;
                float ny = (y - h / 2) / 8.0f;

                float r = sqrt(nx * nx + ny * ny);
                float a = atan2(ny, nx);

                // event horizon
                if (r < 0.6f) {
                    std::cout << " ";
                    continue;
                }

                // lensing warp
                float warpedR = r + 0.3f / r;

                // accretion disk
                float disk =
                    exp(-fabs(warpedR - 1.2f) * 8.0f) *
                    fabs(sin(a * 6 + t));

                // background glow
                float glow = exp(-r * 1.5f);

                float brightness = disk + glow * 0.3f;

                std::cout << shade(brightness);
            }
            std::cout << "\n";
        }

        t += 0.05f;
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
}
*/

// it still looks like a spinning galaxy but im too lazy to fix it

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

const int w = 80;
const int h = 30;

// shade ramp
const char shades[] = " .,:;irsXA253hMHGS#9B&@";

int main()
{
        float t = 0.0f;

        std::cout << "\033[2J\033[?25l";

        while (true)
        {
                std::cout << "\033[H";

                for (int y = 0; y < h; y++)
                {
                        for (int x = 0; x < w; x++)
                        {
                                // normalized coords
                                float nx = (x - w / 2) / (float)(w / 2);
                                float ny = (y - h / 2) / (float)(h / 2);

                                float r = sqrt(nx * nx + ny * ny);
                                float a = atan2(ny, nx);

                                // spin accretion disk
                                float spin = a + t + r * 4.0f;

                                // gravity well
                                float gravity = 1.0f / (r * 6.0f + 0.2f);

                                // disk pattern
                                float disk =
                                    sin(spin * 6.0f) *
                                    exp(-r * 3.0f);

                                float intensity =
                                    disk * 1.5f +
                                    gravity * 2.0f;

                                // event horizon
                                if (r < 0.15f)
                                {
                                        std::cout << " ";
                                        continue;
                                }

                                int shade = (int)(intensity * 10);
                                if (shade < 0)
                                        shade = 0;
                                if (shade > 19)
                                        shade = 19;

                                std::cout << shades[shade];
                        }
                        std::cout << "\n";
                }

                t += 0.04f;
                std::this_thread::sleep_for(std::chrono::milliseconds(33));
        }
}
