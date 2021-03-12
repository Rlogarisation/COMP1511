/*
Output:
z5206267@weber:~/COMP1511/lab06$ ./getchatPractice 
Please enter a character: a
The input a has the ASCII value 97.
*/


#include<stdio.h>

int main(void) {
    // using getchar() to read a single character from input
    int inputSingleChar;
    printf("Please enter a character: ");
    inputSingleChar = getchar();
    printf("The input %c has the ASCII value %d.\n", inputSingleChar, 
    inputChar);

    // using putchar() to write a single character to output
    putchar(inputSingleChar);
    return 0;
}