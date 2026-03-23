/* value.c */

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef union {
    uint64_t number;	
    char     string[10];
} Value;

void value_format(Value *v, FILE *stream) {
    // TODO: Print out attributes in Value
    fprintf(stream, "Value{number = %016lx, string = %s}\n", v->number, v->string);
}

void value_bytes(Value *v, FILE *stream) {
    // TODO: Print out each byte in Value
}

int main(int argc, char *argv[]) {

    printf("Sizeof(Value) = %lu\n", sizeof(Value));
    puts("");

    Value v0 = {0};
    value_format(&v0, stdout);
    puts("");

    Value v1 = {-1};
    value_format(&v1, stdout);
    puts("");

    Value v2 = {ULONG_MAX};
    printf("ULONG_MAX = %lu\n", ULONG_MAX);
    value_format(&v2, stdout);
    puts("");

    Value v3 = {0x4150524546};
    value_format(&v3, stdout);
    puts("");

    return EXIT_SUCCESS;
}
