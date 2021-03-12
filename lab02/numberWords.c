//z5206267@cse.unsw.edu.au
/*
Make a program called numberWords.c.

This program will ask for a number with the message Please enter an integer: .

For numbers between 1 and 5, display the number as a word in the message 
You entered number.

For numbers less than 1, display the message You entered a number less than one.

For numbers greater than 5, 
display the message You entered a number greater than five.
*/

#include<stdio.h>

int main(void){
    int num;
    printf("Please enter an integer: ");
    scanf("%d", &num);
    if (num >= 1 && num <= 5) {
        if (num == 1) {
            printf("You entered one.\n");
        } else if (num == 2) {
            printf("You entered two.\n");
        } else if (num == 3) {
            printf("You entered three.\n");
        } else if (num == 4) {
            printf("You entered four.\n");
        } else if (num == 5) {
            printf("You entered five.\n");
        }
    } else if (num < 1) {
        printf("You entered a number less than one. \n");
    } else if (num > 5) {
        printf("You entered a number greater than five. \n");
    }
    return 0;
}





