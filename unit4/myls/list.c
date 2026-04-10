/* list.c */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* Node Structure */

typedef struct Node Node;
struct Node {
    char   *path;
    size_t  size;
    Node   *next;
};

Node *  node_create(const char *path, size_t size) {
    Node* n = calloc(1, sizeof(Node));

    if (!n) return NULL;

    n->path = (char *)path;
    n->size = size;
    n->next = NULL;
    return n;
}

void    node_delete(Node *n) {
    if (!n) return;
    node_delete(n->next);
    free(n->path);
    free(n);
}

/* List Structure */

typedef struct {
    Node *head;
} List;

void    list_add(List *l, const char *path, size_t size) {
    if (!l->head) {
        // Case 1: Empty list
        l->head = node_create(path, size);
    } else {
        // Case 2: List with items
        Node* curr = l->head;

        while (curr->next) {
            curr = curr->next;
        }

        curr->next = node_create(path, size);
    }
}

/* Functions */

void    add_files(const char *root, List *files) {
    DIR *d = opendir(root);
    if (!d) {
        fprintf(stderr, "opendir(%s): %s\n", root, strerror(errno));
    }

    for (struct dirent *e = readdir(d); e; e = readdir(d)) {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) {
            continue;
        }

        char path[BUFSIZ];
        sprintf(path, "%s/%s", root, e->d_name);
        struct stat s;
        if (stat(path, &s)) {
            fprintf(stderr, "stat(%s): %s\n", e->d_name, strerror(errno));
            continue;
        }

        /*
        if ((s.st_mode & S_IFMT) != S_IFREG) continue;

        if (access(path, X_OK)) continue;
        */

        list_add(files, strdup(path), s.st_size);
    }

    closedir(d);
}

void    print_files(List *files) {
    for (Node* curr = files->head; curr; curr = curr->next) {
        printf("[%lu] %s\n", curr->size, curr->path);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    char root[BUFSIZ];

    if (argc >= 2) {
        strcpy(root, argv[1]);
    } else {
        getcwd(root, BUFSIZ);
    }

    List l = {NULL};
    add_files(root, &l);
    print_files(&l);

    // TODO: Release resources
    node_delete(l.head);

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
