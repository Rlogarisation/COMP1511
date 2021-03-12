//z5206267@cse.unsw.edu.au
//written 24/May/2020
/*
Modify this code so that the loop counts down from 10 until 0.
*/

#include <stdio.h>

int main(void)
{
    //initialise counter to 10
    int counter = 10; 
    
    while (counter >= 0) 
    { 
        // print counter
        printf("%d\n", counter);
        // increment counter
        counter = counter - 1; 
    } 
    return 0;
}

