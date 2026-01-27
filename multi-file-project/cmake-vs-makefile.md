**Makefile** - direct build instructions, you write the exact commands
**CMake** - generates Makefiles (or other build systems) for you

## Makefile

Simple, direct control. You write exactly what to compile.

```makefile
CXX = g++
CXXFLAGS = -Wall -std=c++17

main: main.o math_utils.o
	$(CXX) main.o utils.o -o main

main.o: main.cpp math_utils.h
	$(CXX) $(CXXFLAGS) -c main.cpp

math_utils.o: math_utils.cpp math_utils.h
	$(CXX) $(CXXFLAGS) -c utils.cpp

clean:
	rm -f *.o main
```

Run with `make`

**Pros:**
- Simple for small projects
- Direct control
- Fast to learn

**Cons:**
- Platform-specific (Linux/Mac syntax ≠ Windows)
- Gets messy with 50+ files
- Manual dependency tracking

## CMake

Describes your project at high level, generates platform-specific build files.

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp math_utils.cpp)
```

Build with:
```bash
mkdir build
cd build
cmake ..
make
```

**Pros:**
- Cross-platform (works on Windows/Linux/Mac)
- Handles complex dependencies automatically
- Industry standard for big projects
- Finds libraries for you

**Cons:**
- Overkill for 2-3 files
- More to learn upfront
- Extra build directory clutter

## When to Use What

**Makefile:** Small projects (under 10 files), Linux-only, learning
**CMake:** Anything you'll distribute, cross-platform, or has external libraries

It's recommended to start with Makefile. And then switch to CMake when you're using external libraries (like SFML, SDL, etc.) or when Windows builds matter.
