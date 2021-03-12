// Zheng Luo(z5206267@cse.unsw.edu.au)
// Written 27/June/2020

// reads an integer n from standard input, 
// and then scans in n integers from standard input,
// adds them together, then prints the sum.
// Note: you are not permitted to use an array in this exercise.

#include<stdio.h>

int main (void) {
    int numbers;
    printf("How many numbers: ");
    scanf("%d", &numbers);
    int counterForNumbers = 0;
    int sum = 0;
    while (counterForNumbers < numbers) {
        int input;
        scanf("%d", &input);
        sum = input + sum;
        counterForNumbers++;
    }
    printf("The sum is: %d\n", sum);
    return 0;
}
