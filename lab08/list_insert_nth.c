#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int data;
};

struct node *insert_nth(int n, int value, struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int value;
    scanf("%d", &value);
    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    struct node *new_head = insert_nth(n, value, head);
    print_list(new_head);

    return 0;
}


// Insert a new node containing value at position n of the linked list.
// if n == 0, node is inserted at start of list
// if n >= length of list, node is appended at end of list
// The head of the new list is returned.
struct node *insert_nth(int n, int value, struct node *head) {
    struct node *current = head;

    // New node
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    
    // If add to the beginning.
    if (n == 0 || head == NULL) {
        newNode->next = head;
        head = newNode;
    }
    // If add to the middle or rear.
    else
    {
        // Loop through "current" until desired insert position is reached. 
        int counter = 1;
        while (counter < n && current->next != NULL) {
            current = current->next;
            counter++;
        }
        // Now, the desired position is reached.
        // Assign newNode's next address to the next address of current.
        newNode->next = current->next;   
        // Change the next address of current to newNode's address.
        current->next = newNode;     
    }
    // Remember to return the head of pointer, not current.  
    return head;
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
