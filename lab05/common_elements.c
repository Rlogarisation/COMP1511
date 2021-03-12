// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
// By ZHENG LUO (z5206267@cse.unsw.edu.au)
// Written 27/May/2020

#include<stdio.h>


int common_elements(int length, int source1[length], int source2[length],
int destination[length]) {
     
    int counterForSource1 = 0;
    
    int common = 0;
    
    while (counterForSource1 < length) {
        int counterForSource2 = 0;

        while (counterForSource2 < length) {

            if (source1[counterForSource1] == source2[counterForSource2]) {
                destination[common] = source1[counterForSource1];
                //printf("%d\n", destination[common]); For test purpose
                common++;
                break;
            }

            counterForSource2++;
        }
        counterForSource1++;
    }

    return common;
}

/*
Below is for test purpose


#define SIZE 6

int main (void) {
    int source1[SIZE] = {1, 4, 1, 5, 9, 2};
    int source2[SIZE] = {1, 1, 8, 2, 5, 3};
    int destination[SIZE] = {0};

    printf("There are %d numbers in common\n", common_elements(SIZE, source1,
    source2, destination));

    return 0;
}
*/






