//z5206267@cse.unsw.edu.au
/*
This program should ask for two integers using the message 
Please enter two integers: 
and then display the sum of the integers as n + n = sum.

Any numbers that are between zero and ten should appear as words. 
This also applies to negative numbers between negative ten and zero. 
All other numbers should appear as decimal integers.
*/

#include <stdio.h>

int main(void){
    int num1;
    int num2;
    printf("Please enter two integers: ");
    scanf("%d %d", &num1, &num2);
    int result = num1 + num2;
    // Convert first number into words
    if (num1 < 0 && num1 >= -10)
    {
        printf("negative ");
    }
    if (num1 == 0)
    {
        printf("zero");
    } 
    else if (num1 == 1 || num1 == -1) 
    {
        printf("one");
    }
    else if (num1 == 2 || num1 == -2) 
    {
        printf("two");
    }
    else if (num1 == 3 || num1 == -3) 
    {
        printf("three");
    }
    else if (num1 == 4 || num1 == -4) 
    {
        printf("four");
    }
    else if (num1 == 5 || num1 == -5) 
    {
        printf("five");
    }
    else if (num1 == 6 || num1 == -6) 
    {
        printf("six");
    }else if (num1 == 7 || num1 == -7) 
    {
        printf("seven");
    }
    else if (num1 == 8 || num1 == -8) 
    {
        printf("eight");
    }
    else if (num1 == 9 || num1 == -9) 
    {
        printf("nine");
    }
    else if (num1 == 10 || num1 == -10) 
    {
        printf("ten");
    }
    else
    {
        printf("%d", num1);
    }
    //print plus
    printf(" + ");
    //convert second number into words
    if (num2 < 0 && num2 >= -10)
    {
        printf("negative ");
    }
    if (num2 == 0)
    {
        printf("zero");
    } 
    else if (num2 == 1 || num2 == -1) 
    {
        printf("one");
    }
    else if (num2 == 2 || num2 == -2) 
    {
        printf("two");
    }
    else if (num2 == 3 || num2 == -3) 
    {
        printf("three");
    }
    else if (num2 == 4 || num2 == -4) 
    {
        printf("four");
    }
    else if (num2 == 5 || num2 == -5) 
    {
        printf("five");
    }
    else if (num2 == 6 || num2 == -6) 
    {
        printf("six");
    }else if (num2 == 7 || num2 == -7) 
    {
        printf("seven");
    }
    else if (num2 == 8 || num2 == -8) 
    {
        printf("eight");
    }
    else if (num2 == 9 || num2 == -9) 
    {
        printf("nine");
    }
    else if (num2 == 10 || num2 == -10) 
    {
        printf("ten");
    }
    else
    {
        printf("%d", num2);
    }
    //print equal sign
    printf(" = ");
    //convert result into words
    if (result < 0 && result >= -10)
    {
        printf("negative ");
    }
    if (result == 0)
    {
        printf("zero");
    } 
    else if (result == 1 || result == -1) 
    {
        printf("one");
    }
    else if (result == 2 || result == -2) 
    {
        printf("two");
    }
    else if (result == 3 || result == -3) 
    {
        printf("three");
    }
    else if (result == 4 || result == -4) 
    {
        printf("four");
    }
    else if (result == 5 || result == -5) 
    {
        printf("five");
    }
    else if (result == 6 || result == -6) 
    {
        printf("six");
    }else if (result == 7 || result == -7) 
    {
        printf("seven");
    }
    else if (result == 8 || result == -8) 
    {
        printf("eight");
    }
    else if (result == 9 || result == -9) 
    {
        printf("nine");
    }
    else if (result == 10 || result == -10) 
    {
        printf("ten");
    }
    else
    {
        printf("%d", result);
    }
    printf("\n");    
    return 0;
}

