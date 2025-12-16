#include <iostream>
#include <iomanip>
#include <cstring>

struct Player {
    int hp;
    float speed;
    char tag;
};

void section(const char* title) {
    std::cout << "\n=== " << title << " ===\n";
}

void kv(const char* k, const void* v) {
    std::cout << std::left << std::setw(18) << k << ": " << v << '\n';
}

void kvi(const char* k, int v) {
    std::cout << std::left << std::setw(18) << k << ": " << v << '\n';
}

void kvf(const char* k, float v) {
    std::cout << std::left << std::setw(18) << k << ": " << v << '\n';
}

void bytes(const void* ptr, std::size_t size) {
    const unsigned char* b = static_cast<const unsigned char*>(ptr);
    for (std::size_t i = 0; i < size; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(b[i]) << ' ';
    }
    std::cout << std::dec << '\n';
}

int main() {
    std::cout << "ptr_sandbox\n";

    // stack
    section("stack variable");
    int a = 5;
    int* p = &a;

    kvi("a", a);
    kv("&a", &a);
    kv("p", p);
    kvi("*p", *p);

    // pointer to pointer
    section("pointer to pointer");
    int** pp = &p;

    kv("pp", pp);
    kv("*pp", *pp);
    kvi("**pp", **pp);

    // heap
    section("heap allocation");
    int* h = new int(42);

    kv("h", h);
    kvi("*h", *h);

    delete h;
    kv("h after delete", h);

    // array decay
    section("array memory");
    int arr[5] = {1,2,3,4,5};

    for (int i = 0; i < 5; i++) {
        std::cout
            << "arr[" << i << "]  "
            << "val=" << std::setw(2) << arr[i] << "  "
            << "addr=" << &arr[i] << "  "
            << "arr+i=" << (arr + i) << '\n';
    }

    // struct layout
    section("struct layout");
    Player pl = {100, 3.5f, 'A'};

    kvi("sizeof(Player)", sizeof(Player));
    kv("&pl", &pl);
    kv("&pl.hp", &pl.hp);
    kv("&pl.speed", &pl.speed);
    kv("&pl.tag", static_cast<void*>(&pl.tag));

    // raw bytes
    section("raw bytes of Player");
    bytes(&pl, sizeof(Player));

    // mutation
    section("mutation via pointer");
    int x = 10;
    int* xp = &x;

    kvi("x before", x);
    *xp = 99;
    kvi("x after", x);

    std::cout << "\nend\n";
    return 0;
}
