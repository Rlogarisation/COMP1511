/*
Zheng Luo (z5206267@cse.unsw.edu.au)
Written 17/July/2020
which reads a line from its input then reads an integer n from its input.
e.g
./line_char
abcdefghijklmnopqrstuvwxyz
0
The character in position 0 is 'a'
*/

#include<stdio.h>

#define MAX 256

int main (void) {
    char inputArray[MAX];
    int position;
    // Reads a line of input.
    fgets(inputArray, MAX, stdin);
    // Read position.
    scanf("%d", &position);
    printf("The character in position %d is '%c'\n", position, 
    inputArray[position]);

    return 0;
}