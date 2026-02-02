#include <windows.h>

#include <map>
#include <string>

std::map<char, std::string> morse = {{'S', "..."}, {'O', "---"} /* i will add more later */};

void dot() {
        Beep(800, 100);
        Sleep(100);
}
void dash() {
        Beep(800, 300);
        Sleep(100);
}
void letterGap() { Sleep(200); }
void wordGap() { Sleep(400); }

void playMorse(std::string text) {
        for (char c : text) {
                if (c == ' ') {
                        wordGap();
                        continue;
                }

                for (char m : morse[toupper(c)]) {
                        if (m == '.')
                                dot();
                        else if (m == '-')
                                dash();
                }
                letterGap();
        }
}

int main() {
        playMorse("SOS");
        return 0;
}
