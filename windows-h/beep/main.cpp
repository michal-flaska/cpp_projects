#include <windows.h>

#include <iostream>

#include "pitches.h"

// just a little note to myself:
// Beep() maxes out at around 32767 Hz,
// and has a lower limit around 37 Hz

// https://youtu.be/8y1lgH0xDdM

int main() {
        // Beep(15000, 1000); -> annoying as fuck

        // leave this running if you hate yourself (and everyone around you)
        while (true) {
                Beep(10000 + (rand() % 5000), 500);
        }

        return 0;
}

/*
// happy birthday

Beep(G4, 200);
Beep(G4, 200);
Beep(A4, 400);
Beep(G4, 400);
Beep(C5, 400);
Beep(B4, 800);
*/
