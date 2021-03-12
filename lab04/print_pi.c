//Zheng Luo (z5206267@cse.unsw.edu.au)
//Written 25/May/2020
//Prints the first n digits of pi, where n is specified 


#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int digit;
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &digit);
    int counter = 0;
    while (counter < digit && digit <= MAX_DIGITS) {
        if (counter == 1) {
            printf(".");
        }
        printf("%d", pi[counter]);
        counter++;
    }
    printf("\n");

    return 0;
}