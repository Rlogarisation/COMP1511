//z5206267@cse.unsw.edu.au
//Written 24/May/2020
/*
reads 3 integers and prints them from smallest to largest

You are not permitted to use if statements.
You are not permitted to use loops (e.g. while).
You are not permitted to call functions other than printf and scanf.

e.g.
Enter integer: 23
Enter integer: 5
Enter integer: 27
The integers in order are: 5 23 27
*/

#include<stdio.h>


//#############################UNFINISHED##################################

int main(void)
{
    //scan inputs
    int a, b, c;
    
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);

    //rearrange order with 3 more variables
    int x, y, z;
    //initial ordering
    x = a;
    y = b;
    z = c;
    //Considering first and second inputs first
    //when a <= b:
    a <= b && (a = x, b = y);
    //when b <= a:
    a > b && (a = y, b = y);


    //Considering third input
    //when c >= b
    c >= y && c = z;




    //print result
    printf("The integers in order are: %d %d %d\n", x, y, z);
    return 0;
}