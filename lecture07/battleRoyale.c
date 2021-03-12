// Battle Royale
// A Linked List demo that simulates a list of
// players in a battle royale style game

// We want the ability to build a list
// print out all the players currently in the game
// and knock out individual players

// Later we're going to add players in alphabetical order

// Marc Chee (cs1511@cse.unsw.edu.au), July 2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

// Create node
struct player
{
    struct player *next;
    char name[MAX_NAME];
};

// Receive a struct player pointer as input,
// and return a struct player pointer to the current node.
// Basically, take in a pointer, return a pointer.
struct player *createPlayer(
    char inputName[MAX_NAME], 
    struct player *inputNext
);

void printPlayers(struct player *playerList);

struct player *insertPlayer(
    struct player *insertPos, 
    char inputName[MAX_NAME]
);
struct player *insertAlpha(
    struct player *head, 
    char inputName[MAX_NAME]
);


int main(void) {
    struct player *head = NULL;
    head = insertPlayer(head, "Chicken");
    insertPlayer(head, "Marc");
    insertPlayer(head, "Frankie");
    return 0;
}

// Creates a struct player variable in allocated memory
// uses the given inputName and inputNext to populate
// the fields of the struct
// Returns a pointer to the memory that was allocated
struct player *createPlayer(
    char inputName[MAX_NAME], 
    struct player *inputNext
) {
    // Create a struct player pointer to consist with *createPlayer.
    // Allocate memory for struct player type.
    struct player *p = malloc(sizeof(struct player));
    strcpy(p->name, inputName);
    p->next = inputNext;
    return p;
}

void printPlayers(struct player *playerList) {
    struct player *current = playerList;
    while (current != NULL) {
        fputs(current->name, stdout);
        printf("\n");
        current = current->next; 
    }

}
// Insert a player into a list as the next node after insertPos
// This will not remove any elements from the list
// Returns a pointer to the inserted node
struct player *insertPlayer(
    struct player *insertPos, 
    char inputName[MAX_NAME]
) {    
    struct player *newPlayer = createPlayer(inputName, NULL);
    if (insertPos != NULL) {
        // insert after a node that exists
        newPlayer->next = insertPos->next;
        insertPos->next = newPlayer;
    }
    return newPlayer;
}

// Insert a player into a list in the correct alphabetical order
// position
// This assumes that the list is already in alphabetical order
// Returns a pointer to the head of the list
struct player *insertAlpha(struct player *head, char inputName[MAX_NAME]) {
    struct player *current = head;
    struct player *prev = NULL;
    // Find the position that we want to insert into
    // Check for when we should be before something alphabetically
    while (current != NULL && strcmp(inputName, current->name) > 0) {
        prev = current;
        current = current->next;
    }
    
    // Then insert at that position, using our insertPlayer function
    insertPlayer(prev, inputName);
    
    return head;
}