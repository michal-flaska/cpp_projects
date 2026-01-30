#include <iostream>
#include <string>

class Node{
public:
        std::string name;
        int value;
        Node *next; //next node
        Node *prev; //previous node

        Node(std::string name, int value)
        {
                this->name = name;
                this->value = value;
                this->next = nullptr;
                this->prev = nullptr;
        }
};

class DoublyLinkedList{ //https://www.geeksforgeeks.org/cpp/cpp-linked-list/
private:
        Node *head; //first node in the list
        Node *tail; //last node in the list
        int size;   //how many nodes we have

public:
        //constructor
        DoublyLinkedList(){
                this->head = nullptr;
                this->tail = nullptr;
                this->size = 0;
        }

        //destructor
        ~DoublyLinkedList(){
                Node *current = head;
                while (current != nullptr)
                {
                        Node *next = current->next;
                        delete current;
                        current = next;
                }
        }

        //add node to the end of list
        void pushBack(std::string name, int value){
                Node *newNode = new Node(name, value); //create new node in memory

                if (head == nullptr){ //list is empty
                        head = newNode;
                        tail = newNode;
                }
                else{
                        tail->next = newNode; //old tail points forward to new node
                        newNode->prev = tail; //new node points back to old tail
                        tail = newNode;       //new node becomes the tail
                }
                size++;
        }

        //add node to the start of list
        void pushFront(std::string name, int value){
                Node *newNode = new Node(name, value);

                if (head == nullptr){ //list is empty
                        head = newNode;
                        tail = newNode;
                }
                else{
                        newNode->next = head; //new node points forward to old head
                        head->prev = newNode; //old head points back to new node
                        head = newNode;       //new node becomes the head
                }
                size++;
        }

        // rint from start to end
        void print(){
                Node *current = head;
                while (current != nullptr){
                        std::cout << current->name << " (" << current->value << ")" << '\n';
                        current = current->next; //move to next node
                }
        }

        //print from end to start (only possible because we have prev pointers)
        void printReverse(){
                Node *current = tail;
                while (current != nullptr){
                        std::cout << current->name << " (" << current->value << ")" << '\n';
                        current = current->prev; //move to previous node
                }
        }
};

int main()
{
        DoublyLinkedList list;

        for (int i = 0; i < 5; i++){
                list.pushBack("element" + std::to_string(i + 1), 10);
        }

        std::cout << "Forward:" << '\n';
        list.print();

        std::cout << "\nReverse:" << '\n';
        list.printReverse();

        return 0;
}
