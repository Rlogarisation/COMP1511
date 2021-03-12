//By Zheng Luo z5206267@cse.unsw.edu.au
/*
Write a program that uses scanf to get a number from a user and 
prints "Don't be so negative!" if they entered a negative number.
If the number is positive, the program should print 
"You have entered a positive number."
If the user enters the number 0, 
the program should print "You have entered zero."
Note: you can assume that the number will always be a whole number 
(i.e. an integer)
*/
//Written 23/May/2020

#include<stdio.h>

int main(void){
    int result;
    scanf("%d", &result);
    if (result > 0 ) {
        printf("You have entered a positive number.\n");
    } else if (result == 0 ) {
        printf("You have entered zero.\n");
    } else {
        printf("Don't be so negative!\n");
    }
    return 0;
}
