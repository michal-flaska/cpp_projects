#include <iostream>
#include <string>
#include <vector>

int main() {
        using PlayerID = uint64_t;
        using Position = std::pair<float, float>;

        PlayerID id = 12345;
        Position pos = {10.5f, 20.3f};

        return 0;
}

/*
// Type aliases (use this):
using MyInt = int;
using StringVector = std::vector<std::string>;
using Callback = void(*)(int);

MyInt x = 5;  // same as int x = 5;

// typedef (old way):
typedef int MyInt;
typedef std::vector<std::string> StringVector;


// Use `using` - it's clearer, especially with templates:
template<typename T>
using Vec = std::vector<T>;

Vec<int> numbers;  // clean

// vs typedef - ugly:
template<typename T>
typedef std::vector<T> Vec;  // doesn't work!

// Why use them:
// - Shorter names: `Vec<int>` vs `std::vector<int>`
// - Readability: `Callback` vs `void(*)(int)`
// - Easy refactoring: change one alias instead of 50 spots
*/
