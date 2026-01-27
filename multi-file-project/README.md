## The Basics

**Header files (.h)** contain declarations - they tell the compiler "this function/class exists somewhere"
**Source files (.cpp)** contain implementations - the actual code

## Simple Example Structure

```
project/
├── main.cpp
├── utils.h
└── utils.cpp
```

## Compiling

```bash
g++ main.cpp utils.cpp -o main
```

That's it. The compiler links everything together.

## Key Rules

1. **Header guards** (`#ifndef`, `#define`, `#endif`) - prevents including the same file twice
2. **Declarations in .h, implementations in .cpp** - keeps things organized
3. **Use `" "` for headers**, `< >` for system headers
4. **Dont put `using namespace std;` in headers** - pollutes everyone who includes it

## Common Mistakes to Avoid

- Don't implement functions in headers (unless they're inline/template)
- Don't include .cpp files
- Don't forget header guards
- Don't define variables in headers (only declare them with `extern`)

## For Bigger Projects

When we have 10+ files, compile individually then link:

```bash
g++ -c main.cpp -o main.o
g++ -c utils.cpp -o utils.o
g++ main.o utils.o -o main
```

Or use a Makefile/CMake
