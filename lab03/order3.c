//z5206267@cse.unsw.edu.au  
//written by 24/May/2020
/*
using if statements (no loops) that
reads 3 integers and prints them from smallest to largest.
e.g
Enter integer: 23
Enter integer: 5
Enter integer: 27
The integers in order are: 5 23 27
*/

#include <stdio.h>

int main (void) 
{
    int num1, num2, num3;
    printf("Enter integer: ");
    scanf("%d", &num1);
    printf("Enter integer: ");
    scanf("%d", &num2);
    printf("Enter integer: ");
    scanf("%d", &num3);
    printf("The integers in order are: ");
    //when num1 is smallest
    if (num1 <= num2 && num1 <= num3)
    {
        printf("%d ", num1);
        if (num2 <= num3)
        {
            printf("%d %d\n", num2, num3);
        }
        else
        {
            printf("%d %d\n", num3, num2);
        } 
    }
    //when num2 is smallest
    else if (num2 <= num1 && num2 <= num3)
    {
        printf("%d ", num2);
        if (num1 <= num3)
        {
            printf("%d %d\n", num1, num3);
        }
        else
        {
            printf("%d %d\n", num3, num1);
        }
    }
    //when num3 is smallest
    else if (num3 <= num1 && num3 <= num2)
    {
        printf("%d ", num3);
        if (num1 <= num2)
        {
            printf("%d %d\n", num1, num2);
        }
        else
        {
            printf("%d %d\n", num2, num1);
        }
    }
    return 0;
}