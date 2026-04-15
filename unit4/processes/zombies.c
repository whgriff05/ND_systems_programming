/* zombies.c:  A demonstration of what happens if parents don't wait for their children. */

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
    int nchildren = atoi(argv[1]);

    for (int i = 0; i < nchildren; i++) {
        pid_t pid = fork();


        if (pid < 0) {
            fprintf(stderr, "fork(): %s\n", strerror(errno));
        } else if (pid == 0) { // Child
            sleep(1);
            printf("Child: Hi from %d\n", i);
            exit(i);
        }
    }

    for (int i = 0; i < nchildren; i++){
        wait(NULL);
    }

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
