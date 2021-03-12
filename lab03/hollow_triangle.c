// Lab 3 hollow triangle
// By Zheng Luo (z5206267@cse.unsw.edu.au)
// Written 15/June/2020

/*
reads an integer n from standard input. 
and prints a pattern of asterisks forming a hollow triangle.
You can assume n is greater than 3.

e.g.
./hollow_triangle 
Enter size: 5
*
**
* *
*  *
*****
./hollow_triangle
Enter size: 8
*
**
* *
*  *
*   *
*    *
*     *
********

*/

#include <stdio.h>

// Define some expression for printing triangle
#define HYPOTENUSE (counterColumn == counterRow)
#define BOTTOM (counterRow == size - 1)
#define SIDE (counterColumn == 0)


int main(void) {

    // Scan input as the size of triangle
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    // Print out the triangle
    int counterRow = 0;
    while (counterRow < size) {
        int counterColumn = 0;
        while (counterColumn < size) {
            if (HYPOTENUSE || BOTTOM || SIDE) {
                printf("*");
            }else {
                printf(" ");
            }
            counterColumn ++;
        }
        printf("\n");
        counterRow ++;
    }

    return 0;
}