#include <iostream>
#include <thread>
#include <chrono>

int main() {

        // Define vars
        bool isCheatActive = true;
        bool isInjectionSuccessful = true;
        std::string injectionState;

        if(isInjectionSuccessful == true){
                injectionState = "Successful";
        }
        else{
                injectionState = "Failed";
        }

        std::cout << "Cheat injection: " << injectionState << "!" << '\n';

        while (isCheatActive == true) {
                // Do nothing or minimal logic
                std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        return 0;
}
