#include <iostream>
#include <thread>
#include <chrono>

int main()
{
        const int w = 80;
        const int h = 24;

        int x = 1, y = 1;
        int dx = 1, dy = 1;

        std::cout << "\033[2J\033[?25l";

        while (true)
        {
                std::cout << "\033[H";

                for (int j = 0; j < h; j++)
                {
                        for (int i = 0; i < w; i++)
                        {
                                if (i == x && j == y)
                                        std::cout << "DVD";
                                else
                                        std::cout << " ";
                        }
                        std::cout << "\n";
                }

                x += dx;
                y += dy;

                if (x <= 0 || x >= w - 3)
                        dx *= -1;
                if (y <= 0 || y >= h - 1)
                        dy *= -1;

                std::this_thread::sleep_for(std::chrono::milliseconds(60));
        }
}
