#include <iostream>
#include <string>

int main() {
        std::string nameToSearch;
        std::string names[] = {"Mike", "Martin", "Oliver", "Miro", "Johnny",
                               "Dominik", "Vojto", "Janci", "Zuzka"};

        // calculate array size automatically
        int arraySize = sizeof(names) / sizeof(names[0]);

        std::cout << "Enter a name to search (case sensitive): ";
        std::cin >> nameToSearch;

        for (int i = 0; i < arraySize; i++) {
                if (names[i] == nameToSearch) {
                        std::cout << names[i] << " found at index " << i << std::endl;
                        break;
                } else {
                        std::cout << "name wasnt found" << '\n';
                        break;
                }
        }

        return 0;
}

/*
old version:

#include <iostream>
#include <string>

int main(){

        std::string nameToSearch;
        std::string names[] = {"Mike", "Martin", "Oliver", "Miro", "Johnny"};
        int index = 0;

        std::cout << "Enter a name to search: ";
        std::cin >> nameToSearch;

        for(std::string name : names){
                if(name == nameToSearch){
                        std::cout << name << " found at " << index;
                }
        }


        return 0;
}
*/
