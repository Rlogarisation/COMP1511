/*
Zheng Luo (z5206267@cse.unsw.edu.au)
Written 17/July/2020
which reads integers from standard input until it reaches end-of-input.

It should then print the missing integers.

The missing integers should be all positive integers 
which did not appear in the program's input and which are smaller than 
the largest integer which did appear in the program's input.

The missing integers should be printed in increasing order on a single line.
e.g
./fill_missing
1
4
1
5
9
2
6
9
control-d
3 7 8
*/

/*
Store inputs into an array without repeating each other, and increasing order.

*/

#include<stdio.h>
#include<stdlib.h>


#define MAX 10000

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main (void) {
    int inputArray[MAX];
    int counter = 0;
    while (counter < MAX && scanf("%d", &inputArray[counter]) != EOF) {
        counter++;
    } 
    // Rearrange to the ascending order for inputArray.
    qsort(inputArray, counter, sizeof(int), cmpfunc);

    int counterForSmall = 1;
    if (inputArray[0] > 1) {
        while (counterForSmall < inputArray[0]) {
            printf("%d ", counterForSmall);
            counterForSmall++;
        }

    }

    int counterForSorting = 0;
    while (counterForSorting < counter - 1) {
        if (inputArray[counterForSorting] == 
        inputArray[counterForSorting + 1]) {

        } else if (inputArray[counterForSorting + 1] - 
        inputArray[counterForSorting] > 0) { 
            int counterForBig = 1;
            int gap = inputArray[counterForSorting + 1] - 
            inputArray[counterForSorting];
            while (counterForBig < gap) {
                printf("%d ", inputArray[counterForSorting] + counterForBig);
                counterForBig++;
            }
        } 

        counterForSorting++;
    }
    printf("\n");
    
    

    return 0;
}