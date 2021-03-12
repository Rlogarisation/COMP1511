// Lab05 boxes.c
// By Zheng Luo (z5206267@cse.unsw.edu.au)
// Written 2/June/2020 

/*
which reads in a number and
then draws that many square boxes inside each other using the integer 1.
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

/*
 V1.2's problem: squares will be printed separately
 If change while loop at line 57 into inner loop,
 e.g when box == 2;
 The inner loop will print 0 first for inner box (which should print 1) , 
 as counterForBoxes == 0.
 Then it will print 1 as counterForBoxes == 2, then become 01010101010101etc
*/



/*
Ideas for version 1.3:
Get rid of while loop of counterForBoxes,
add: if (EXPRESSION_ROW || EXPRESSION_COL || SOMETHING)
STH has to have same function as counterForBoxes.
*/

/*
V1.4, Use array[boxes][boxes]
*/


#include<stdio.h>
#include<string.h>


void PrintBoxes(int boxes);


int main(void) {
    int boxes;
    printf("How many boxes: ");
    scanf("%d", &boxes);
    PrintBoxes(boxes); 
    return 0;
}




void PrintBoxes(int boxes) {
    
    // Convert boxes (number of boxes) into the scale of n*n size
    int size = (boxes * 3) + (boxes - 1);

    // Core logic
    #define EXPRESSION_ROW \ 
    ((counterForRow == counterForBoxes || \
    counterForRow == size - counterForBoxes - 1) && \ 
    counterForCol >= counterForBoxes && counterForCol <= size - counterForBoxes - 1)
    #define EXPRESSION_COL \
    ((counterForCol == counterForBoxes || counterForCol == size - counterForBoxes - 1) && \
    counterForRow >= counterForBoxes && counterForRow <= size - counterForBoxes - 1)
    
    
    // Use 2D array to represent matrix
    int ArrayForBoxes[size][size];
    // Manually set up the size of array, and <string.h> has been included
    memset(ArrayForBoxes, 0, size*size*sizeof(int));

    // Letting program to deal with outter most square first
    // As counter being += 2, it is dealing with second outter most square
    int counterForBoxes = 0;
    // Assign the 1s into corresponding positions
    while (counterForBoxes < size * 2) {
        int counterForRow = 0;
        while (counterForRow < size) {
            int counterForCol = 0;
            while (counterForCol < size) {
                if (EXPRESSION_ROW || EXPRESSION_COL) {
                    ArrayForBoxes[counterForCol][counterForRow] = 1;
                }
                counterForCol++;
            }
            counterForRow++;
        }
        // because squares are separated by 1 line of 0s
        // hence += 2 in order to cope with next square
        counterForBoxes += 2;
    }

    
    // Frame for standard printing
    int counterForRow = 0;
    while (counterForRow < size) {
        int counterForCol = 0;
        while (counterForCol < size) {
            printf("%d", ArrayForBoxes[counterForCol][counterForRow]);
            counterForCol++;
        }
        printf("\n");
        counterForRow++;
    }
      
}




