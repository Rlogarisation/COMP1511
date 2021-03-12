// COMP1511 Week 4 Lab: cs calculator
//
// This program was written by Zheng Luo (z5206267@cse.unsw.edu.au)
// on 24/Jnue/2020
//
//  which will scan in instructions until EOF and prints the output
//

#include <stdio.h>
int power(int secondNumber, int thirdNumber);

int main (void) {
    int firstNumber, secondNumber, thirdNumber;
    printf("Enter instruction: ");
    while (scanf("%d", &firstNumber) != EOF) {
        if (firstNumber == 1) {
            scanf("%d", &secondNumber);
            printf("%d\n", secondNumber * secondNumber);
        } else if (firstNumber == 2) {
            scanf("%d %d", &secondNumber, &thirdNumber);
            printf("%d\n", power(secondNumber, thirdNumber));
        }
        printf("Enter instruction: ");
    }

    return 0;
}

int power(int secondNumber, int thirdNumber) {
    int result = 1;
    int counter = 0;
    while (counter < thirdNumber) {
        result = secondNumber * result;
        counter++;
    }
    return result;
}