/* popen.c: An example of using os.popen instead of manually creating a pipe,
 * forking, and execing. */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *pstream = popen("ls -l", "r");
    if (!pstream) {
        perror("popen");
        return EXIT_FAILURE;
    }

    // Copy from source file to target file
    char buffer[BUFSIZ];
    size_t nread;
    while ((nread = fread(buffer, 1, BUFSIZ, pstream)) > 0) {
    	fwrite(buffer, 1, nread, stdout);
    }

    pclose(pstream);
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
