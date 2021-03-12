// Zheng Luo(z5206267@cse.unsw.edu.au)
// Written 27/June/2020

/*
Reads in a number and then draws that
many square boxes inside each other using the integer 1.
e.g.
How many boxes: 2
1111111
1000001
1011101
1010101
1011101
1000001
1111111
*/

#include<stdio.h>
#include<string.h>

// Core logic
#define EXPRESSION_ROW \
((counterForRow == counterForBoxes || \
counterForRow == size - counterForBoxes - 1) && \
counterForColumn >= counterForBoxes && counterForColumn <= size - counterForBoxes - 1)
#define EXPRESSION_COL \
((counterForColumn == counterForBoxes || counterForColumn == size - counterForBoxes - 1) && \
counterForRow >= counterForBoxes && counterForRow <= size - counterForBoxes - 1)

void printBoxes(int numberOfBoxes);

int main (void) {
    int numberOfBoxes;
    printf("How many boxes: ");
    scanf("%d", &numberOfBoxes);
    if (numberOfBoxes > 0) {
        printBoxes(numberOfBoxes);
    } 
    
    return 0;
}

void printBoxes(int numberOfBoxes) {
    int size = numberOfBoxes * 3 + (numberOfBoxes - 1);
    int arrayForBoxes[size][size];
    // Manually set up the size of array, and <string.h> has been included
    memset(arrayForBoxes, 0, size*size*sizeof(int));

    int counterForBoxes = 0;
    // Consider the outter most 1's first, then next outter etc.
    while (counterForBoxes < numberOfBoxes * 2) {
        int counterForRow = 0;
        while (counterForRow < size) {
            int counterForColumn = 0;
            while (counterForColumn < size) {
                if (EXPRESSION_COL || EXPRESSION_ROW) {
                    arrayForBoxes[counterForRow][counterForColumn] = 1;
                }
                counterForColumn++;
            }
            counterForRow++;
        }
        counterForBoxes += 2;
    }
    // Print out the boxes.
    int counterForRow = 0;
    while (counterForRow < size) {
        int counterForColumn = 0;
        while (counterForColumn < size) {
            printf("%d", arrayForBoxes[counterForRow][counterForColumn]);
            counterForColumn++;
        }
        printf("\n");
        counterForRow++;
    }


    

}