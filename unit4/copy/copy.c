/* copy.c */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>

void usage(const char *program) {
    fprintf(stderr, "Usage: %s source target\n", program);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
    	usage(argv[0]);
    	return EXIT_FAILURE;
    }

    // Command line arguments
    const char* source_path = argv[1];
    const char* target_path = argv[2];

    // Open file for reading
    int source_fd = open(source_path, O_RDONLY);
    if (source_fd < 0) {
        fprintf(stderr, "open(%s): %s\n", source_path, strerror(errno));
        return EXIT_FAILURE;
    }
    FILE* source = fdopen(source_fd, "r");
    if (!source) {
        close(source_fd);
        return EXIT_FAILURE;
    }

    // Open file for writing
    FILE* target = fopen(target_path, "w");
    if (!target) {
        fclose(source);
        return EXIT_FAILURE;
    }

    // Copy from source file to target file
    char buffer[BUFSIZ];
    size_t nread;
    while ((nread = fread(buffer, 1, BUFSIZ, source)) > 0) {
        fwrite(buffer, 1, nread, target);
    }

    // Close files
    fclose(target);
    fclose(source);

    return EXIT_SUCCESS;
}
