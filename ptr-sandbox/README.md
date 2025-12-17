# ptr_sandbox

pure c++ memory playground. single main.cpp. no input. no deps. just prints everything and exits.

this project exists for one reason: to understand what the fuck pointers actually do

## what this shows

* stack variables and their addresses
* pointers and pointer to pointer
* heap allocation using new and malloc
* array decay and byte offsets
* struct layout and padding
* raw memory byte dumps
* memcpy cloning
* alignment effects with alignas
* strict aliasing break example
* function pointers
* vtable pointer peek
* placement new
* fake allocator arena
* const pointer variations
* endianness check
* stack growth via recursion
* optional UB playground

all in one run. clean sections. readable output.

## build

any modern compiler works

```bash
g++ main.cpp -std=c++17 -O0
```

-O0 recommended so compiler doesnt get clever and hide shit

## run

```bash
./a.out
```

no args. no input. just prints and ends.

## UB playground

theres a section guarded by a macro

```bash
g++ main.cpp -std=c++17 -DUB_PLAYGROUND
```

this intentionally triggers undefined behavior.. may crash. may not. thats the point.

## why this is useful

* makes pointer arithmetic obvious
* shows real memory layout
* helps debug weird bugs later
* builds intuition u cant get from theory

this is basically a debugger without a debugger

## rules

* dont cargo cult this into prod code
* UB section is for learning only
* addresses change every run. thats normal

## extend ideas

* add virtual inheritance
* inspect std::string small buffer
* custom allocator with free list
* print asm and map to memory

if u understand everything this prints then youre already ahead of most devs
