#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <new>

// This thing is pure memory porn -- My friend

struct Player {
    int hp;
    float speed;
    char tag;
};

struct alignas(16) AlignedPlayer {
    int hp;
    float speed;
    char tag;
};

struct Base {
    virtual void speak() {}
};

struct Derived : Base {
    void speak() override {}
};

void section(const char* t) {
    std::cout << "\n=== " << t << " ===\n";
}

void kv(const char* k, const void* v) {
    std::cout << std::left << std::setw(28) << k << ": " << v << '\n';
}

void kvi(const char* k, int v) {
    std::cout << std::left << std::setw(28) << k << ": " << v << '\n';
}

void kvu(const char* k, std::uintptr_t v) {
    std::cout << std::left << std::setw(28) << k << ": " << v << '\n';
}

void bytes(const void* ptr, std::size_t sz) {
    const unsigned char* b = static_cast<const unsigned char*>(ptr);
    for (std::size_t i = 0; i < sz; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0')
                  << (int)b[i] << ' ';
    }
    std::cout << std::dec << '\n';
}

void stackDive(int d) {
    int local = d;
    std::cout << "depth=" << d << "  &local=" << &local << '\n';
    if (d > 0) stackDive(d - 1);
}

int add(int a, int b) {
    return a + b;
}

int main() {
    std::cout << "ptr_sandbox_final\n";

    section("stack basics");
    int a = 5;
    int* p = &a;
    kvi("a", a);
    kv("&a", &a);
    kv("p", p);
    kvi("*p", *p);

    section("pointer to pointer");
    int** pp = &p;
    kv("pp", pp);
    kv("*pp", *pp);
    kvi("**pp", **pp);

    section("heap new vs malloc");
    int* n = new int(42);
    int* m = static_cast<int*>(std::malloc(sizeof(int)));
    *m = 77;
    kv("new ptr", n);
    kvi("*new", *n);
    kv("malloc ptr", m);
    kvi("*malloc", *m);
    delete n;
    std::free(m);

    section("array offsets");
    int arr[5] = {1,2,3,4,5};
    std::uintptr_t base = reinterpret_cast<std::uintptr_t>(&arr[0]);

    std::cout
        << std::setw(6) << "i"
        << std::setw(6) << "val"
        << std::setw(10) << "offset"
        << "addr\n";

    for (int i = 0; i < 5; i++) {
        std::uintptr_t addr =
            reinterpret_cast<std::uintptr_t>(&arr[i]);
        std::cout
            << std::setw(6) << i
            << std::setw(6) << arr[i]
            << std::setw(10) << (addr - base)
            << &arr[i] << '\n';
    }

    section("struct + padding");
    Player pl = {100, 3.5f, 'A'};
    kvi("sizeof Player", sizeof(Player));
    kv("&pl", &pl);
    kv("&hp", &pl.hp);
    kv("&speed", &pl.speed);
    kv("&tag", static_cast<void*>(&pl.tag));
    bytes(&pl, sizeof(Player));

    section("aligned struct");
    AlignedPlayer ap = {100, 3.5f, 'A'};
    kvi("sizeof AlignedPlayer", sizeof(AlignedPlayer));
    bytes(&ap, sizeof(AlignedPlayer));

    section("memcpy clone");
    Player clone;
    std::memcpy(&clone, &pl, sizeof(Player));
    kv("&clone", &clone);
    bytes(&clone, sizeof(Player));

    section("strict aliasing");
    float f = 3.14f;
    int* ip = reinterpret_cast<int*>(&f);
    kv("&float", &f);
    kvi("int view", *ip);
    bytes(&f, sizeof(float));

    section("function pointers");
    int (*fp)(int,int) = add;
    kv("fp addr", reinterpret_cast<void*>(fp));
    kvi("fp(2,3)", fp(2,3));

    section("vtable peek");
    Derived d;
    std::uintptr_t* vptr =
        *reinterpret_cast<std::uintptr_t**>(&d);
    kv("&object", &d);
    kvu("vtable ptr", *vptr);

    section("placement new");
    alignas(Player) unsigned char buffer[sizeof(Player)];
    Player* ppl = new (buffer) Player{1, 2.0f, 'Z'};
    kv("buffer", buffer);
    kv("placement ptr", ppl);
    bytes(ppl, sizeof(Player));
    ppl->~Player();

    section("fake allocator");
    unsigned char arena[64];
    void* a1 = arena;
    void* a2 = arena + 16;
    kv("arena base", arena);
    kv("alloc 1", a1);
    kv("alloc 2", a2);
    bytes(arena, 32);

    section("const pointer hell");
    int cx = 10;
    const int* pc = &cx;
    int* const cp = &cx;
    kv("const int*", pc);
    kv("int* const", cp);

    section("endianness");
    uint32_t e = 0x11223344;
    bytes(&e, sizeof(e));

    section("stack growth");
    stackDive(5);

#ifdef UB_PLAYGROUND
    section("UB playground");
    int y = 1;
    int* bad = reinterpret_cast<int*>(
        reinterpret_cast<char*>(&y) + 1);
    *bad = 999;
    kvi("y after UB", y);
#endif

    std::cout << "\nend\n";
    return 0;
}
