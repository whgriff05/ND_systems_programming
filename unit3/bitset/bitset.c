/* bitset.c */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Type Definitions */

typedef int64_t Bitset;

/* Functions */

void	bitset_add(Bitset *b, int value) {
    *b |= (1<<value);
}

bool	bitset_contains(Bitset *b, int value) {
    return *b & (1<<value);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int numbers[] = {4, 6, 6, 3, 7, -1};
    Bitset bitset = 0;

    printf("Bitset: %lx\n", bitset);
    
    for (int* p = numbers; *p >= 0; p++) {
        bitset_add(&bitset, *p);
    }

    printf("Bitset: %lx\n", bitset);

    for (int i = 0; i < 10; i++) {
        if (bitset_contains(&bitset, i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
