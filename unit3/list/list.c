/* list.c */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/* Node Structure */

typedef struct Node Node;

struct Node {
    int	  data;	// 4
    Node *next;	// 8
};

Node *	node_create(int data, Node *next) {
    Node *n = calloc(1, sizeof(Node));
    if (n) {
    	n->data = data;
    	n->next = next;
    }
    return n;
}

void	node_delete(Node *n, bool recursive) {
    // Base case: invalid node
    if (!n) return;
    
    // Free next
    if (recursive) node_delete(n->next, recursive);

    // Free node
    free(n);
}

/* List Structure */

typedef struct {
    Node *head;
} List;

bool	list_contains(List *l, int value) {
    for (Node *curr = l->head; curr; curr = curr->next) {
    	if (curr->data == value) {
    	    return true;
	}
    }
    return false;
}

void	list_add(List *l, int value) {
    if (list_contains(l, value)) return;

    l->head = node_create(value, l->head);
}

void	list_dump(List *l) {
    for (Node *curr = l->head; curr; curr = curr->next) {
    	printf("%d\n", curr->data);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int numbers[] = {4, 6, 6, 3, 7, -1};
    List l = {NULL};

    for (int *p = numbers; *p >= 0; p++) {
    	list_add(&l, *p);
    }

    list_dump(&l);

    for (int i = 0; i < 10; i++) {
    	if (list_contains(&l, i)) {
    	    printf("%d\n", i);
	}
    }

    return 0;
}
