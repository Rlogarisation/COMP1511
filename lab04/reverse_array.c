//Zheng Luo (z5206267@cse.unsw.edu.au)
//Written 25/May/2020
/*
which reads integers line by line, 
and when it reaches the end of input, 
prints those integers in reverse order, line by line.
e.g.
Enter numbers forwards:
10
50
20
40 (ctrl + D)
Reversed:
40
20
50
10
*/

#include<stdio.h>
//I increased the max from 100 to 102, 
//because I need to -2 to not print out command lines at the end 
#define MAX_SIZE_ARRAY 102

int main(void) {
    //result is 1 if valid input, otherwise 0
    int scanned_in_value;
    int result = 1;
    printf("Enter numbers forwards: \n");
    int counter = 0;
    //declear an array first
    int integers[MAX_SIZE_ARRAY] = {0};
    while (result == 1) {
        //Statement for while loop
        result = scanf("%d", &scanned_in_value);
        //Store scanned number into array called 'integers'.
        integers[counter] = scanned_in_value;
        counter++;    
    }

    //Print out the reverse part
    printf("Reversed: \n");

    //Since the programme will print out the end command as 0
    //so we start to print after end command
    counter = counter - 2; //BUT I DONT KNOW WHY IS -2 RATHER THAN -1.
    while (counter >= 0) {
        printf("%d\n", integers[counter]);
        counter = counter - 1;
    }




    return 0;
}