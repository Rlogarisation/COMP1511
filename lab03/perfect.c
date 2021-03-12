//z5206267@cse.unsw.edu.au
//Written 24/May/2020
/*
reads a positive integer n from standard input and prints all the factors of n, 
their sum and indicates whether n is a perfect number.
e.g.
Enter number: 6
The factors of 6 are:
1
2
3
6
Sum of factors = 12
6 is a perfect number
*/

#include<stdio.h>

int main(void)
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("The factors of %d are: \n", num);
    //For looping
    int counter = 1;
    //For counting the sum
    int sum = 0;

    while (counter <= num)
    {
        if (num % counter == 0)
        {
            printf("%d\n", counter);
            sum = sum + counter;
        }
        counter++;
    }
    printf("Sum of factors = %d\n", sum);
    //Perfect number is the sum of its divisors
    //but not itself
    int sum_exclu = sum - num;
    if (sum_exclu == num)
    {
        printf("%d is a perfect number\n", num);
    }
    else
    {
        printf("%d is not a perfect number\n", num);
    }
    return 0;
}