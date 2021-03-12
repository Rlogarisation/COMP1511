//z5206267@cse.unsw.edu.au 
//Written 24/May/2020
/*
reads a positive integer n and 
print all the positive integers < n divisible by 3 or 5. 
All of the numbers printed should be in ascending order.
e.g
Enter number: 10
3
5
6
9
*/

#include<stdio.h>

int main(void)
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int counter =  1;
    while (counter < num)
    {
        if (counter % 3 == 0)
        {
            printf("%d\n", counter);
        }
        else if (counter % 5 == 0)
        {
            printf("%d\n", counter);
        }
        counter++;
    }

    return 0;
}