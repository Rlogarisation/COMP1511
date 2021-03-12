#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *reverse(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = reverse(head);
    print_list(new_head);

    return 0;
}

//
// Place the list pointed to by head into reverse order.
// The head of the list is returned.
//
struct node *reverse(struct node *head) {
    // Initialise 3 pointers. previous = NULL, current = head, next = NULL.
    // We don't have newNode here, so no need to initiate memory (malloc).
    struct node *previous = NULL;
    struct node *current = head;
    struct node *next = NULL;

    // Loop thro every node until NULL is reached.
    while (current != NULL) {
        // Move "next" to next node.
        next = current->next;
        // Reverse the link, point back to previous.
        current->next = previous;
        // Move "previous" to current position.
        previous = current;
        // Move "current" to next position.
        current = next;
    }
    // Move the head to the end of list.
    // Both current and next is pointing "NULL"
    // previous is pointing the last node in the list,
    // so head = previous.
    head = previous;
    // Return the head of list.
    return head;
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

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

