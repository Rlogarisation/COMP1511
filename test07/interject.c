// COMP1511 Week 7 Test: Interject
//
// This program was written by Zheng Luo (z5206267)
// on 17/July/2020
//
// This program adds interjections to strings.

/*
Specifically, you should modify str so that it looks similar to the array: 
{str[0], str[1], ..., str[i - 1], interject[0], interject[1], ..., 
interject[M], str[i], ..., str[N], '\0'}

For example, if char str[100] = "Comp Science"; and you called 
interject(str, "uter", 3) you would modify str to be "Computer Science".

For example, if char str[100] = "Beginnings"; and you called 
interject(str, "New ", 0) you would modify str to be "New Beginnings".

For example, if char str[100] = "The End!"; and you called 
interject(str, " Is Nigh", 7) you would modify str to be "The End Is Nigh!".
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.
void interject(char *str, char *interject, int index) {
    int lengthOfInterject = strlen(interject);
    int lengthOfString = strlen(str);
    int counterForMovingRear = lengthOfString;

    // Move the rear words back lengthOf(interject) positions.
    while (counterForMovingRear >= index) {
        str[counterForMovingRear + lengthOfInterject] = str[counterForMovingRear];
        counterForMovingRear--;
    }
    // Interject interject into the desired position.
    int counterForInterject = 0;
    while (counterForInterject < lengthOfInterject) {
        str[index + counterForInterject] = interject[counterForInterject]; 
        counterForInterject++;
    }
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}
