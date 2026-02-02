#include <windows.h>
#include <cstdlib>

int main() {
        // Set CMD colors (blue bg, white text)
        system("color 1F");
        system("mode con cols=80 lines=25");
        system("cls");

        // Print fake BSOD
        system("echo.");
        system("echo    :( ");
        system("echo.");
        system("echo    Your PC ran into a problem and needs to restart.");
        system("echo    We're just collecting some error info, and then we'll restart for you.");
        system("echo.");
        system("echo    0%% complete");
        system("echo.");
        system("echo.");
        system("echo    For more information about this issue:");
        system("echo    CRITICAL_PROCESS_DIED");
        system("echo.");
        system("pause");

        // Troll reveal
        MessageBox(NULL, "lol get trolled noob", "PRANKED", MB_ICONINFORMATION);

        return 0;
}
