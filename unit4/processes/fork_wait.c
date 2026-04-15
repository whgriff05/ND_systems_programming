/* fork_wait.c: An example of forking and waiting */

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
    int status = EXIT_SUCCESS;

    pid_t pid = fork();

    switch(pid) {
        case 0: // Child Process
            sleep(1);
            printf("[C] Child PID: %d, Parent PID: %d\n", getpid(), getppid());
            exit(5);
            // Or since you're in the main function,
            // return 7;
            break;

        case -1: // (Parent Process) Error: fork failed
            fprintf(stderr, "fork() failed: %s\n", strerror(errno));
            break;

        default: // Parent Process
            printf("[P] Child PID: %d, Parent PID: %d\n", pid, getpid());
            pid = wait(&status);
            printf("[P] Child PID: %d, Child Raw Status: %d, Child Status: %d\n", pid, status, WEXITSTATUS(status));
            break;
    }

    return status;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
