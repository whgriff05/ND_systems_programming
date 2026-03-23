/* point.c */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// TODO: struct, union
/*
typedef struct {
    int x;
    int y;
} Point;
*/

typedef union {
    int x;
    int y;
} Point;

void point_format(Point *p, FILE *stream) {
    // TODO: Print point to stream
    fprintf(stream, "Point{x: %d, y: %d}\n", p->x, p->y);
}

int main(int argc, char *argv[]) {
    // TODO: Define some points
    printf("Sizeof(Point) = %lu\n", sizeof(Point));

    Point p0 = {0};
    Point p1 = {1, 2};

    // TODO: Print size and locations of point structure
    printf("Address p0: %lu\n", (intptr_t)&p0);
    printf("Address p0.x: %lu\n", (intptr_t)&p0.x);
    printf("Address p0.y: %lu\n", (intptr_t)&p0.y);

    // TODO: Use print_format to print point structure
    point_format(&p0, stdout);
    point_format(&p1, stdout);

    // TODO: Define array of points
    Point pa[] = {
        {3, 4},
        {5, 6},
        {0},
    };

    // TODO: Loop through array with pointers and print each point
    for (Point* p = pa; p->x && p->y; p++) {
        point_format(p, stdout);
    }

    return EXIT_SUCCESS;
}
