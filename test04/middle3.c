// Zheng Luo (z5206267@cse.unsw.edu.au)
// Written 27/June/2020
// Reads 3 integers and prints the middle integer.

#include<stdio.h>

int main (void) {
    int first, second, third;
    printf("Enter integer: ");
    scanf("%d", &first);
    printf("Enter integer: ");
    scanf("%d", &second);
    printf("Enter integer: ");
    scanf("%d", &third);
    if ((first <= second && second <= third) || 
    (third <= second && second <= first)) {
        printf("Middle: %d\n", second);
    } else if ((second <= first && first <= third) || 
    (third <= first && first <= second)) {
        printf("Middle: %d\n", first);
    } else {
        printf("Middle: %d\n", third);

    }
    return 0;
}