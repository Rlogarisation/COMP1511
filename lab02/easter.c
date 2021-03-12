//z5206267@cse.unsw.edu.au
/*
Write a program easter.c which allows the user to enter a year, 
then calculates the date of Easter Sunday for that year.
e.g
Enter year: 2017
Easter is April 16 in 2017.
*/

#include<stdio.h>

int main(void)
{
    //int the variable
    int year;

    //Interaction
    printf("Enter year: ");
    scanf("%d", &year);

    //Calculations
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a +  11 * h + 22 * l) / 451;
    int EasterMonth = (h + l - 7 * m + 114) / 31;  //[3=March, 4=April]
    int p = (h + l - 7 * m + 114) % 31;
    int EasterDate = p + 1;     //(date in Easter Month)

    //convert month in number to words
    printf("Easter is ");

    if (EasterMonth == 1)
    {
        printf("January");
    }
    else if (EasterMonth == 2)
    {
        printf("February");
    }
    else if (EasterMonth == 3)
    {
        printf("March");
    }
    else if (EasterMonth == 4)
    {
        printf("April");
    }
    else if (EasterMonth == 5)
    {
        printf("May");
    }
    else if (EasterMonth == 6)
    {
        printf("June");
    }
    else if (EasterMonth == 7)
    {
        printf("July");
    }
    else if (EasterMonth == 8)
    {
        printf("August");
    }
    else if (EasterMonth == 9)
    {
        printf("September");
    }
    else if (EasterMonth == 10)
    {
        printf("October");
    }
    else if (EasterMonth == 11)
    {
        printf("November");
    }
    else if (EasterMonth == 12)
    {
        printf("December");
    }

    //result
    printf(" %d in %d.\n", EasterDate, year);
    return 0;
}