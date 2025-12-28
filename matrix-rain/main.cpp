#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    std::srand(std::time(0));

#ifdef _WIN32
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
#else
    std::cout << "\033[2J\033[?25l";
#endif

    const int width = 80;
    const int height = 24;
    std::vector<int> drops(width, 0);

    while (true) {
        for (int i = 0; i < width; i++) {
            if (drops[i] == 0 && std::rand() % 20 == 0)
                drops[i] = 1;

            if (drops[i] > 0) {
                int y = drops[i];
                if (y < height) {
                    std::cout << "\033[" << y << ";" << i + 1 << "H"
                              << char(33 + std::rand() % 94);
                    drops[i]++;
                } else {
                    drops[i] = 0;
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
