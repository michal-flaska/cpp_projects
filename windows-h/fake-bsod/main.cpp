#include <windows.h>
#include <cstdlib>
#include <cstdio>

int main() {
        HWND console = GetConsoleWindow();

        // Focus the console
        SetForegroundWindow(console);
        Sleep(100);

        // Press F11 for fullscreen
        keybd_event(VK_F11, 0, 0, 0);
        keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);

        Sleep(200);

        system("color 1F");
        system("cls");

        printf("\n\n");
        printf("   :(\n\n");
        printf("   Your PC ran into a problem and needs to restart.\n");
        printf("   We're just collecting some error info, and then we'll restart for you.\n\n");
        printf("   0%% complete\n\n\n");
        printf("   For more information about this issue:\n");
        printf("   CRITICAL_PROCESS_DIED\n\n\n");

        system("pause");

        // Exit fullscreen
        keybd_event(VK_F11, 0, 0, 0);
        keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);

        Sleep(200);

        MessageBox(NULL, "lol get trolled noob", "PRANKED", MB_ICONINFORMATION);

        return 0;
}
