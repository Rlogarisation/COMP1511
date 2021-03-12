// Zheng Luo(z5206267@cse.unsw.edu.au)
// Written 3/July/2020
// Write a C function that removes duplicate elements from an array, 
// by copying the non-duplicate values to a second array, 
// i.e. only the first occurrence of any value should be copied.
#include<stdio.h>
#define LENGTH 6

int remove_duplicates(int length, int source[length], int destination[length]);


int main (void) {
    //int length = 6;
    int source[LENGTH] = {3, 1, 4, 1, 5, 9};
    int destination[LENGTH];
    
    printf("%d\n", remove_duplicates(LENGTH, source, destination));

    return 0;
}

int remove_duplicates(int length, int source[length], int destination[length]) {
    int counterForDestination = 0;
    int counter = 0;
    while (counter < length) {
        int counterForRepeat = 0;
        int repeatIndicator = 0;
        // Check whether same number has been cp before.
        while (counterForRepeat < counter) {
            if (source[counterForRepeat] != source[counter]) {
                repeatIndicator = 0;
            } else
            {
                repeatIndicator = 1;
                break;
            }
            counterForRepeat++;
        }
        if (repeatIndicator == 0) {
            destination[counterForDestination] = source[counter];
            counterForDestination++;
        }
        counter++;
    }
    return counterForDestination;
}
