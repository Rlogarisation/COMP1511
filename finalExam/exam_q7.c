#include <stdio.h>
#include <stdlib.h>

#define MAX 2100000000
#define MAX_COLOR_TYPE 3

struct location *createLocation(int color);

struct location {
    int color;
    struct location *next;
};

int main(void) {
    int index, range, color;
    struct location *head = NULL;
    while (scanf("%d %d %d", &index, &range, &color) != EOF) {
        struct location *current = head;
        int counterForIndex = 1;
        while (counterForIndex < index) {
            current = current->next;
            counterForIndex++;
        }
        // For range.
        int counterForRange = 0;
        while (counterForRange < range) {
            // If the node is not initialised yet.
            if (current == NULL) {
                // Create node.
                struct location *newNode = createLocation(color);
                // Insert node.
                if (head == NULL) {
                    head = newNode;
                    current = head;
                } else {
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            } else {
                current->color = color;
            }
            current = current->next;
            
            counterForRange++;
        }
        
    }
    int counter = 0;
    struct location *current = head;
    while (current != NULL) {
        printf("%d %d\n", counter, color);
        counter++;
        current = current->next;
    }

    return 0;
}

struct location *createLocation(int color) {
    struct location *newNode = malloc(sizeof(struct location));
    newNode->color = color;
    newNode->next = NULL;
    return newNode;
}