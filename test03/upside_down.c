/*
Zheng Luo (z5206267@cse.unsw.edu.au)
Written 19/June/2020
read 3 numbers and indicate whether 
they are strictly increasing (called "up"),
strictly decreasing (called "down"),
or neither ("neither")
i.e.
./upside_down
Please enter three numbers: 5.6 6.5 11.9
up
*/

#include<stdio.h>

int main(void) {
    double a, b, c;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a < b && b < c){
        printf("up\n");
    } else if (a > b && b > c) {
        printf("down\n");
    } else {
        printf("neither\n");
    }
    return 0;
}