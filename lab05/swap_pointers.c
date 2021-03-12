// By ZHENG LUO (z5206267@cse.unsw.edu.au)
// Written 27/May/2020
/*
Your task is to add code to this function in swap_pointers.c:

*/



#include <stdio.h>

// swap the values in two integers, given as pointers
void swap_pointers(int *a, int *b) {
    int temporary;
    temporary = *a;
    *a = *b;
    *b = temporary;
}

// This is a simple main function which could be used
// to test your swap_pointers function.
// It will not be marked.
// Only your swap_pointers function will be marked.

int main(void) {
    int first = 1;
    int second = 2;
    
    swap_pointers(&first, &second);
    
    printf("%d, %d\n", first, second);
    return 0;
}

