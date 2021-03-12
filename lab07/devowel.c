/*
Zheng Luo (z5206267@ad.unsw.edu.au)
Written by 14/July/2020

which reads characters from its input and 
writes the same characters to its output, 
except it does not write lower case vowels ('a', 'e','i', 'o', 'u').
Your program should stop only at the end of input.
Use getChar and putChar only.
*/

#include<stdio.h>

#define IS_VOWEL 1
#define NOT_VOWEL 0

// which returns 1 the character is a lower case vowel and 0 otherwise.
int is_vowel(int character);

int main(void) {
    
    // Read a character from input, and store it into inputChar.
    int inputChar = getchar();
    // Your program should stop only at the end of input.
    while (inputChar != EOF) {
        // Determine whethere it is lower case vowels.
        if (is_vowel(inputChar) == NOT_VOWEL) {
            putchar(inputChar);
        } 
        // get next number, otherwise it will keep looping first char.
        inputChar = getchar();
    }
    
    return 0;
}

int is_vowel(int character) {
    if (character == 'a' || character == 'e' || character == 'i' || 
    character == 'o' || character == 'u') {
        return IS_VOWEL;
    } else
    {
        return NOT_VOWEL;
    }
}