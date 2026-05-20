#include <stdio.h>

int main() {
        FILE* f = fopen("blob.inc", "w");

        for (int i = 0; i < 1024 * 1024; i++) {
                fprintf(f, "'%c',", 'A' + (i % 26));
        }

        fclose(f);
}
