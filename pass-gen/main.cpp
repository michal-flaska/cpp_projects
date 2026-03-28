#include <iostream>
#include <string>

bool validateSelection(char selection){
        if(selection != 'Y' && selection != 'y' && selection != 'N' && selection != 'n'){
                std::cout << "only options y/n are allowed";
                return false;
        }
        else return true;
}

bool processSelection(char selection){
        if(selection == 'y' || selection == 'Y') return true;
        else return false;
}

void ask(int &passlength, bool &capitals, bool &lowercase, bool &numbers, bool &specials)
{
        char selection = ' ';

        std::cout << "What size of password do you want?: ";
        std::cin >> passlength;

        std::cout << '\n';

        selection = ' ';
        std::cout << "Do you want to include capital letters?" << '\n';
        do{
                std::cin >> selection;
        } while(!validateSelection(selection));
        if(processSelection(selection)){
                capitals = true;
        }

        selection = ' ';
        std::cout << "Do you want to include lowercase letters?" << '\n';
        do{
                std::cin >> selection;
        } while(!validateSelection(selection));
        if(processSelection(selection)){
                lowercase = true;
        }

        selection = ' ';
        std::cout << "Do you want to include numbers?" << '\n';
        do{
                std::cin >> selection;
        } while(!validateSelection(selection));
        if(processSelection(selection)){
                numbers = true;
        }

        selection = ' ';
        std::cout << "Do you want to include special symbols?" << '\n';
        do{
                std::cin >> selection;
        } while(!validateSelection(selection));
        if(processSelection(selection)){
                specials = true;
        }

        std::cout << '\n';
}

std::string generatePassword(int length, bool capitals, bool lowercase, bool numbers, bool specials) {
        std::string CAPITAL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
        std::string NUMBERS = "0123456789";
        std::string SPECIAL = "!@#$%^&*()-+=/`~<>{}[]'\"";

        std::string pool = "";

        if (capitals) pool += CAPITAL;
        if (lowercase) pool += LOWERCASE;
        if (numbers) pool += NUMBERS;
        if (specials) pool += SPECIAL;

        if (pool.empty()) {
                return "error: no characters selected";
        }

        std::string password = "";

        for (int i = 0; i < length; i++) {
                int index = rand() % pool.size();
                password += pool[index];
        }

        return password;
}

int main()
{
        srand(time(0));

        std::string result = "";
        int passLength = 0;

        bool includeCapitals    = false;
        bool includeLowercase   = false;
        bool includeNumbers     = false;
        bool includeSpecials    = false;

        ask(passLength, includeCapitals, includeLowercase, includeNumbers, includeSpecials);

        std::cout << generatePassword(passLength, includeCapitals, includeLowercase, includeNumbers, includeSpecials);

        return 0;
}
