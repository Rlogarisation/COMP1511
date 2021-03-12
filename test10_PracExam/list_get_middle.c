#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int get_middle(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = get_middle(head);
    printf("%d\n", result);

    return 0;
}


// Return middle element of a linked list
// if list contains [6,7,8,9,10]  8 is returned
// if a list has even number of elements, first of middle two elements returned
// if list contains [1,2,3,4] 2 is returned
// list can not be empty
int get_middle(struct node *head) {
    int counterForNumbers = 0;
    struct node *current = head;
    while (current != NULL) {
        counterForNumbers++;
        current = current->next;
    }
    // Reset current.
    current = head;
    // Even
    if (counterForNumbers % 2 == 0) {
        int counterForEven = 0;
        while (counterForEven < (counterForNumbers - 1) / 2) {
            counterForEven++;
            current = current->next;
        }
    }
    // Odd
    else
    {
        int counterForOdd = 0;
        while (counterForOdd < counterForNumbers / 2) {
            counterForOdd++;
            current = current->next;
        }
    }
    return current->data;

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
