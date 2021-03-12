#include <stdio.h>
#include <stdlib.h>


struct location {
    int station;
    int train;
    struct location *next;
};

struct location *createLocation(int station, int train);

int main(void) {
    struct location *head = NULL;
    int station;
    int train;
    while (scanf("%d %d", &station, &train) != EOF) {
        struct location *current = head;
        // Create node.
        struct location *newNode = createLocation(station, train);
        // Insert node.
        if (head == NULL) {
            head = newNode;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    // Focus on the same train in different stations, 
    // if there is any other train who shouldn't appear between them,
    // return error.
    struct location *current = head;
    struct location *lastLocation = head;
    while (current != NULL) {
        // If the same train is found at next station.
        if (current->train == lastLocation->train &&
        current->station == lastLocation->station + 1) {
            
        }
        current = current->next;
    }

    /* PRINTING TEST
    struct location *current = head;
    while (current != NULL) {
        printf("%d %d\n", current->station, current->train);
        current = current->next;
    }
    */
}

struct location *createLocation(int station, int train) {
    struct location *newNode = malloc(sizeof(struct location));
    newNode->train = train;
    newNode->station = station;
    newNode->next = NULL;
    return newNode;
}

