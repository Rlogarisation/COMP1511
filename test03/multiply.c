/*
Zheng Luo (z5206267@cse.unsw.edu.au)
Written 19/June/2020
reads 2 integers and prints their absolute multiple.
i.e.
./multiply
7 10
70

*/

#include<stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a < 0) {
        a = a * -1;
    }
    if (b < 0) {
        b = b * -1;
    }

    if (a == 0 || b == 0){
        printf("zero\n");
    } else {
        printf("%d\n",a * b);
    }
    

    return 0;
}