// A demo of a basic linked list

// Marc Chee (cs1511@cse.unsw.edu.au), edited March 2020

#include <stdlib.h>
#include <stdio.h>

struct node {
    int data; // Data contained in the node
    // Pointer in the node, pointing to the next node.
    struct node *next;  
};

struct node *createNode(int data, struct node *next);
void printData(struct node* n);

int main (void) {
    // head will always point to the first element of our list

    // a pointer "head" -> a node contained "int 5" -> NULL
    struct node *head = createNode(5, NULL);
    // RHS: a node contained "int 4" -> pointer "head" == node "5"
    // LHS: head originally pointing "5", now is pointing to new node "4".
    // Overall, pointer "head"->"4"->"5"->NULL
    head = createNode(4, head);
    // And so on.
    head = createNode(3, head);
    head = createNode(2, head);
    head = createNode(1, head);
    
    printData(head);
    
    return 0;
}

// Create a node using the data and next pointer provided
// Return a pointer to this node
struct node *createNode(int data, struct node *next) {
    // Create the next node pointer, called 'n'.
    struct node *n;
    // Reserve amount of memory for 'struct node'.
    n = malloc(sizeof(struct node));

    if (n == NULL) {
        // malloc returns NULL if there isn't enough memory
        // terminate the program
        printf("Cannot allocate node. Program will exit.\n");
        exit(1);
    }
    // Declear that next node has the data of 
    // 'int data' as given in the function.
    n->data = data;
    n->next = next;
    // Return node n as a pointer.
    return n;
}

// Loop through a list of nodes, printing out their data
void printData(struct node* n) {
    while (n != NULL) { // have printed from list's head up to just before n
        printf("%d\n", n->data);
        n = n->next;
    }
}
