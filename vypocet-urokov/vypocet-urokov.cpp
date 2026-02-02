#include <iostream>

/*
Priklad:

Pán Novák vložil na sporiaci účet, ktorý je úročený ročnou úrokovou sadzbou 3 %,
sumu 2 000 €. Úroky sú pripisované vždy na konci roka. Vypočítajte, akú celkovú
sumu bude mať pán Novák na účte po 3 rokoch.
*/

int main() {
        float num = 2000;
        float percent = 3;
        int years = 3;

        for (int i = 0; i < years; i++) {
                num = num / 100 * (100 + percent);
                std::cout << "Year " << i + 1 << ": " << num << '\n';
        }

        return 0;
}
