#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256
#define MAX_INPUT_LINES 10



int main(int argc, char *argv[]) {
    char string[MAX_INPUT_LINES][MAX_SIZE];
    int numberOfDifference[MAX_INPUT_LINES];
    int lengthOfArgv = strlen(argv[1]);
    int counter = 0;
   
    while (scanf("%[^\n]%*c", string[counter]) == 1 && counter < lengthOfArgv) {
        numberOfDifference[counter] = 0;
        int counterForEachChar = 0;
        while (counterForEachChar < lengthOfArgv) {
            if (tolower(argv[1][counterForEachChar]) != 
            tolower(string[counter][counterForEachChar])) {
                numberOfDifference[counter] += 1;
            }
            counterForEachChar++;
        }
        counter++;
    }
    counter = 0;
    int min = numberOfDifference[0];
    while (counter < lengthOfArgv) {
        if (numberOfDifference[counter] < min) {
            min = numberOfDifference[counter];
        }
        counter++;
    }
    printf("%d %s\n", min, string[counter]);


    return 0;
}
