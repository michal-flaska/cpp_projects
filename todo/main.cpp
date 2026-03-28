#include <iostream>
#include <vector>
#include <string> // std::getline

// passing todolist as reference to avoid big memory when copying big vectors instead of taking their reference

void displayList(const std::vector<std::string> &todoList){
        if(todoList.empty()){
                std::cout << "list is empty" << '\n';
                return;
        }

        for(int i = 0; i < todoList.size(); i++){
                // printf("#%d. %s", (i + 1), todoList[i]);
                std::cout << "#" << (i + 1) << ". " << todoList[i] << "\n";
        }
}

void addToList(std::vector<std::string> &todoList){
        std::string whatToAdd = "";

        std::cout << "Type text: " << '\n';
        std::getline(std::cin >> std::ws, whatToAdd);

        todoList.push_back(whatToAdd);

        std::cout << "\"" << whatToAdd << "\n" << " is now in todo list at index " << todoList.size();
}

void removeFromList(std::vector<std::string> &todoList){
        int index = 0;

        displayList(todoList);
        std::cout << '\n';

        std::cout << "what do you want to remove?: " << '\n';
        do{
                std::cin >> index;
        } while(index < 1 || index > todoList.size());

        todoList.erase(todoList.begin() + (index - 1));
}

int main(){
        std::vector<std::string> todolist = {"item1", "item2"};

        while(true){
                int option = 0;

                std::cout << "Available options: " << '\n';
                std::cout << "1. Display Todo List" << '\n';
                std::cout << "2. Add to todo list" << '\n';
                std::cout << "3. Remove from todo list" << '\n';
                std::cout << "4. Exit" << '\n';
                std::cout << "Enter your choice (1-4): ";

                do{
                        std::cin >> option;
                } while(option < 1 || option > 4);

                switch(option){
                        case 1: displayList(todolist); break;
                        case 2: addToList(todolist); break;
                        case 3: removeFromList(todolist); break;
                        case 4: return 0;
                }
        }

        return 0;
}
