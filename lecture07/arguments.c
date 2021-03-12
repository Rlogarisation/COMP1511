// A demo of using command line arguments
// This program will start an argument with you
// It will take whatever you say and refuse to agree

// Marc Chee (cs1511@cse.unsw.edu.au)
// Edited March 2020

#include <stdio.h>
// argc counts the number of WORDS as input, not single letter.
// argv is 'argument values', which take word into string.
// and argv[0] is the command line.
// The words after the command line is storing into argv[i], where argc > i > 0.
int main(int argc, char *argv[]) {
    int i = 1;
    // argc also counts command line,
    // if you type 2 words after command line, argc = 3.
    // hence argv[0] = ./command
    // argv[1] = first word
    // argv[2] = second word
    printf("This is the number of argc %d\n", argc); // Test it.

    printf("Well actually %s says there's no such thing as ", argv[0]);
    

    while (i < argc) { // have written i - 1 words from argv to stdout
        fputs(argv[i], stdout);
        printf(" ");
        i++;
    }
    printf("\n");
}

/*
./arguments Roger is a stupid boy
Well actually ./arguments says there's no such thing as Roger is a stupid boy
*/