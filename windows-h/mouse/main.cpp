#include <iostream>
#include <windows.h>

int main(){

        SetCursorPos(100, 100);                         // teleport mouse
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);  // click

        return 0;
}
