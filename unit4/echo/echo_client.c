/* echo_client_refactored.c: simple TCP echo client (refactored) */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

const char *HOST = "localhost";
const char *PORT = "9420";

FILE *socket_dial(const char *host, const char *port) {
    /* Lookup server address information */
    struct addrinfo hints = {
        .ai_family = AF_UNSPEC,    // Use IPv4 or IPv6
        .ai_socktype = SOCK_STREAM // Uses TCP
    };
    struct addrinfo *results;

    int status;
    if ((status = getaddrinfo(host, port, &hints, &results)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return NULL;
    }

    /* For each server entry, allocate socket and try to connect */
    int client_fd = -1;
    for (struct addrinfo *p = results; p && client_fd < 0; p = p->ai_next) {
	/* Allocate socket */
        client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (client_fd < 0) {
            perror("socket");
            continue;
        }

	/* Connect to host */
        if (connect(client_fd, p->ai_addr, p->ai_addrlen) < 0) {
            close(client_fd);
            client_fd = -1;
            continue;
        }

    }

    /* Release allocate address information */
    freeaddrinfo(results);

    if (client_fd < 0) {
        return NULL;
    }

    /* Open file stream from socket file descriptor */
    return fdopen(client_fd, "r+");
}

int main(int argc, char *argv[]) {
    /* Connect to remote machine */
    FILE* client_file = socket_dial(HOST, PORT);
    if (!client_file) return EXIT_FAILURE;

    /* Read from stdin and send to server */
    char buf[BUFSIZ] = {0};
    while (fgets(buf, BUFSIZ, stdin)) {  // Read from terminal
        fputs(buf, client_file);         // Write it to server
        fgets(buf, BUFSIZ, client_file); // Read server's response
        fputs(buf, stdout);              // Write server's response to terminal
    }

    fclose(client_file);
    return EXIT_SUCCESS;
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */
