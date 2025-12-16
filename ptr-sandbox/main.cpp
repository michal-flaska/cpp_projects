#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Player {
    int hp;
    float speed;
    char tag;
};

void line() {
    cout << "-----------------------------\n";
}

void printBytes(void* ptr, size_t size) {
    unsigned char* b = (unsigned char*)ptr;
    for (size_t i = 0; i < size; i++) {
        cout << hex << setw(2) << setfill('0') << (int)b[i] << " ";
    }
    cout << dec << "\n";
}

int main() {
    cout << "ptr_sandbox\n";
    line();

    // stack var
    int a = 5;
    int* p = &a;

    cout << "stack int a\n";
    cout << "value: " << a << "\n";
    cout << "&a: " << &a << "\n";
    cout << "p: " << p << "\n";
    cout << "*p: " << *p << "\n";
    line();

    // pointer to pointer
    int** pp = &p;
    cout << "pointer to pointer\n";
    cout << "pp: " << pp << "\n";
    cout << "*pp: " << *pp << "\n";
    cout << "**pp: " << **pp << "\n";
    line();

    // heap alloc
    int* h = new int(42);
    cout << "heap int\n";
    cout << "h: " << h << "\n";
    cout << "*h: " << *h << "\n";
    delete h;
    cout << "after delete h still points to: " << h << "\n";
    line();

    // array decay
    int arr[5] = {1,2,3,4,5};
    cout << "array memory\n";
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i]
             << " | &arr[" << i << "] = " << &arr[i]
             << " | arr+i = " << (arr + i)
             << " | *(arr+i) = " << *(arr + i) << "\n";
    }
    line();

    // struct layout
    Player pl = {100, 3.5f, 'A'};
    cout << "struct Player\n";
    cout << "sizeof Player: " << sizeof(Player) << "\n";
    cout << "&pl: " << &pl << "\n";
    cout << "&pl.hp: " << &pl.hp << "\n";
    cout << "&pl.speed: " << &pl.speed << "\n";
    cout << "&pl.tag: " << (void*)&pl.tag << "\n";
    line();

    // raw bytes
    cout << "raw memory of Player\n";
    printBytes(&pl, sizeof(Player));
    line();

    // mutate via pointer
    int x = 10;
    int* xp = &x;
    cout << "before: x = " << x << "\n";
    *xp = 99;
    cout << "after via pointer: x = " << x << "\n";
    line();

    cout << "done\n";
    return 0;
}
