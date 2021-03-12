/*
Zheng Luo (z5206267@ad.unsw.edu.au)
Written by 14/July/2020

which reads characters from its input and 
writes the same characters to its output with 
lower case letters converted to upper case and upper case letters 
converted to lower case.

Your program should stop only at the end of input.
*/

#include<stdio.h>

// Swap the letter cases, lower->upper, upper->lower.
int swapCases(int character);

int main(void) {
    // Read a character and store it into inputChar.
    int inputChar = getchar();
    // Stop until end of input.
    while (inputChar != EOF) {
        // Swap the letter cases, lower->upper, upper->lower, and print.
        putchar(swapCases(inputChar));
        // Read next character.
        inputChar = getchar();
    }
    return 0;
}

// Swap the letter cases, lower->upper, upper->lower.
int swapCases(int character) {
    int alphaPosition;
    // Lower->upper
    if (character >= 'a' && character <= 'z') {
        // Logic behind ASCII table.(Search it on Google)
        alphaPosition = character - 'a';
        return 'A' + alphaPosition;
    } else if (character >= 'A' && character <= 'Z') { // Upper->lower
        alphaPosition = character - 'A';
        return 'a' + alphaPosition;
    } else { // For special cases, remain the same.
        return character;
    }
}