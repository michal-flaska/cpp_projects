#include <windows.h>
#include <iostream>

#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494
#define C5 523

int main(){

        //happy birthday

        Beep(G4, 200);
        Beep(G4, 200);
        Beep(A4, 400);
        Beep(G4, 400);
        Beep(C5, 400);
        Beep(B4, 800);

        return 0;
}
