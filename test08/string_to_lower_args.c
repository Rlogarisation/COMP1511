// Zheng Luo (z5206267@ad.unsw.edu.au)
// Written by 25/July
// Reads command line arguments then prints them out. 
// When it prints out, 
// it will convert all upper case letters to lower case.
// e.g.
// ./string_to_lower_args Its Over 9000!
// its over 9000!


#include <stdio.h>
#include <string.h>

// Argc is number of sentence.
// Argv[i] is one sentence.
int main(int argc, char *argv[]) {
    // Assign each sentence into a char array, 
    // then analysis each character in each array.
    int counterForSentence = 1;
    while (counterForSentence < argc) {
        int counterForArray = 0;
        // Pointer to argv[i], very smart.
        char *array = argv[counterForSentence];
        while (array[counterForArray] != '\0') {
            if (array[counterForArray] >= 'A' &&
            array[counterForArray] <= 'Z') {
                array[counterForArray] += 'a' - 'A';
            }
            counterForArray++;
        }
        fputs(argv[counterForSentence], stdout);
        printf(" ");
        counterForSentence++;
    }
    printf("\n");

    return 0;
}