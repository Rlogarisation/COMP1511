#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INCREASING 1
#define NON_INCREASING 0

struct node {
    struct node *next;
    int          data;
};

int increasing(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = increasing(head);
    printf("%d\n", result);

    return 0;
}


// return 1 if values in a linked list are in increasing order,
// return 0, otherwise

int increasing(struct node *head) {
    struct node *current = head;
    // Prelin check, to ensure head is not NULL.
    if (current == NULL) {
        return INCREASING;
    }
    while (current->next != NULL) {
        if (current->data < current->next->data) {
            current = current->next;
        } else {
            return NON_INCREASING;
        }
        
    }
    return INCREASING;

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
