XOR (exclusive OR) is a bitwise operation. Symbol: `^`

Basic rule:
- Returns 1 if bits are different
- Returns 0 if bits are same

```
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0
```

In C++:
```cpp
int a = 5;     // 0101 in binary
int b = 3;     // 0011 in binary
int c = a ^ b; // 0110 = 6

// Bit by bit:
// 0^0=0, 1^0=1, 0^1=1, 1^1=0
```

Cool properties:

1. Reversible (super useful):
```cpp
int x = 42;
int key = 123;

int encrypted = x ^ key;                // encrypt
int decrypted = encrypted ^ key;        // decrypt
                                        // decrypted == 42 again!
```

2. Toggle bits:
```cpp
int flags = 0b1010;
flags ^= 0b0100;  // flips 3rd bit -> 0b1110
flags ^= 0b0100;  // flips back -> 0b1010
```

3. Swap without temp variable (party trick, don't actually use):
```cpp
a ^= b;
b ^= a;
a ^= b;
// a and b swapped
```

Real uses:
- Simple encryption (XOR cipher)
- Checksums
- Finding unique elements
- Graphics (XOR drawing mode)
- Game cheats often XOR memory values for some reason

Example - find number that appears once:
```cpp
// All others appear twice
int nums[] = {4, 1, 2, 1, 2};
int result = 0;

for(int n : nums) {
        result ^= n;  // duplicates cancel out
}
// result = 4
```

Need notes?
