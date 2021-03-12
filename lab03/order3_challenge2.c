//z5206267@cse.unsw.edu.au 
//Written 24/May/2020
/*
reads 3 integers and prints them from smallest to largest.
You are only permitted to have 3 variables in your program and they must be of type int.
The restrictions of the previous challenge exercise also apply.
e.g.
Enter integer: 23
Enter integer: 5
Enter integer: 27
The integers in order are: 5 23 27
*/
//Tips: Draw a diagram of 6 different arrangements for x, y, z can be very helpful.
#include<stdio.h>

int main(void)
{
    int x, y, z;
    printf("Enter integer: ");
    scanf("%d", &x);
    printf("Enter integer: ");
    scanf("%d", &y);
    printf("Enter integer: ");
    scanf("%d", &z);
    printf("The integers in order are: %d %d %d\n", 
    //rearrange the first output as the smallest by utilising 0 and 1 system,
    //if any statement is false, which is 0, then the whole term will become 0.
    //the term of != prevents the over-counting with the equal scenario.
    (x < y) * (x < z) * (y != z) * x + (y < x) * (y < z) * (x != z) * y + (z < x) * (z < y) * (x != y) * z
    +
    //the equal scenario for first time, which including x=y, x=z, y=z, and x=y=z.
    (x == y) * (x < z) * x + (x == y) * (x > z) * z
    +
    (x == z) * (y < x) * y + (x == z) * (x < y) * y
    +
    (y == z) * (x < y) * x + (y == z) * (x > y) * y
    +
    (x == y) * (x == z) * x 
    ,
    //similarly for second output.
    ((x > y) * (x < z) * x + (x > z) * (x < y) * x) * (z != y) 
    +
    ((y > x) * (y < z) * y + (y > z) * (y < x) * y) * (z != x) 
    +
    ((z > x) * (z < y) * z + (z > y) * (z < x) * z) * (x != y)
    //equal for second term.
    +
    (x == y) * (x < z) * y + (x == y) * (x > z) * y
    +
    (x == z) * (y < x) * x + (x == z) * (x < y) * z
    +
    (y == z) * (x < y) * y + (y == z) * (x > y) * z
    +
    (x == y) * (x == z) * y 
    ,
    //As well as third term.
    (x > y) * (x > z) * (y != z) * x + (y > x) * (y > z) * (x != z) * y + (z > x) * (z > y) * (x != y) * z
    //equal for third term.
    +
    (x == y) * (x < z) * z + (x == y) * (x > z) * x
    +
    (x == z) * (y < x) * z + (x == z) * (x < y) * y
    +
    (y == z) * (x < y) * z + (y == z) * (x > y) * x
    +
    (x == y) * (x == z) * z 
    );
    return 0;
}