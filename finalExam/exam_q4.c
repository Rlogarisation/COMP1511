#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Do not change these #defines, or your program will fail the autotests!
#define EMPTY_LIST -42

struct node {
    struct node *next;
    int          data;
};

// delete_smallest should find the (first) node with the smallest value,
// and remove that node from the list.
//
// delete_smallest should return the head of the new list.
struct node *delete_smallest(struct node *head) {
    if (head == NULL) {
        return head;
    }
    int smallest = head->data;
    struct node *current = head;
    struct node *previous = head;
    // Go thro the list, to see which one is the smallest.
    while (current != NULL) {
        if (current->data < smallest) {
            smallest = current->data;
        }
        current = current->next;
    }
    // Reset current.
    current = head;
    while (current != NULL) {
        // If the smallest is head.
        if (smallest == head->data) {
            head = current->next;
            free(current);
            break;
        }
        else if (smallest == current->data) {
            previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    return head;
}


// If you want, you can write this function to use for debugging.
// It gets called in the main function below.
// If you don't want to write this function, you can just run the
// autotests (which have their own print_list function).
static void print_list(struct node *head) {
    printf("TODO: write code here to print the list "
           "(or just run the autotest)\n");
}

////////////////////////////////////////////////////////////////////////
//               DO NOT CHANGE THE CODE BELOW                         //
////////////////////////////////////////////////////////////////////////

struct node *delete_smallest(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
static void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    // If you're getting an error here,
    // you have returned an uninitialized value
    struct node *new_head = delete_smallest(head);
    printf("The new list is: ");
    print_list(new_head);

    return 0;
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
