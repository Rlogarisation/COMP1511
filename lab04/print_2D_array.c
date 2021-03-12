// Print a 2D array
// by ZHENG LUO (z5206267@cse.unsw.edu.au)
// on 25/May/2020
/*
./print_2D_array 
00 01 02 03
04 05 06 07
08 09 10 11
12 13 14 15
*/



#include <stdio.h>

#define SIZE 4

void print_2D_array(int array[SIZE][SIZE]);


int main(void) {
    int array[SIZE][SIZE] = {
        {0, 1, 2, 3}, 
        {4, 5, 6, 7}, 
        {8, 9, 10, 11}, 
        {12, 13, 14, 15}
    };
    print_2D_array(array);
    return 0;
}

void print_2D_array(int array[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int column = 0;
        
        while (column < SIZE) {
            //print 0 in front of the number smaller than 10
            if (array[row][column] < 10) {
                printf("0%d ", array[row][column]);
            } else { //otherwise just print normally
                printf("%d ", array[row][column]);
            }
            column++;
        }
        printf("\n");
        row++;
    }

}

