/* fork_exec.c: An example of forking and execing */

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

    if (pid < 0) { // Parent - Failure
        return EXIT_FAILURE;
    } else if (pid == 0) { // Child
        printf("[C] Child PID: %d, Parent PID: %d\n", getpid(), getppid());

        // execlp("date", "date", NULL);
        execlp("ls", "ls", "-l", NULL);
        /*
        char* arguments[] = {
            "date",
            "+%s",
            NULL
        };
        execvp(arguments[0], arguments);
        */
        // execlp("afjweoafhweio", "NOTHING", NULL);
        printf("Exec failed\n");
        exit(EXIT_FAILURE);
    } else { // Parent
        printf("[P] Child PID: %d, Parent PID: %d\n", pid, getpid());
        pid = wait(&status);
        printf("[P] Child PID: %d, Child Raw Status: %d, Child Status: %d\n", pid, status, WEXITSTATUS(status));
    }

    return status;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
