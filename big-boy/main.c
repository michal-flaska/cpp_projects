#include <stdio.h>

char big[] = {
#include "blob.inc"
0
};

int main() {
        printf("hello world\n");

        // use blob.inc so compiler doesnt throw it away
        printf("%zu\n", sizeof(big));

        // %zu is format specifier for size_t
        // because sizeof() returns size_t,
        // not an int

        return 0;
}
