// The Word Game, a demo of strings in C

// Take in a string from standard input
// Take another string from standard input
// Output how many letters from the second
// string appear in the first

// Marc Chee (cs1511@cse.unsw.edu.au), July 2020

#include <stdio.h>

#define MAX_LINE_LENGTH 5

int count_char(char c, char *line);

int main(void) {
    char line[MAX_LINE_LENGTH];
    printf("Please enter one line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    fputs(line, stdout);
    
    // take in a second line of input
    char line2[MAX_LINE_LENGTH];
    printf("Please enter a second line of text: ");
    fgets(line2, MAX_LINE_LENGTH, stdin);
    fputs(line2, stdout);
    
    // loop through the second line
    int i = 0;
    int match_count = 0;
    // add up how many times letters in the second line
    // appear somewhere in the first line
    while (i < MAX_LINE_LENGTH && 
           line2[i] != '\n' && 
           line2[i] != '\0') {
        // we checked a few different things in the while loop
        // because we didn't want \n to be counted as a matched
        // character but also knew that sometimes there wouldn't
        // be a \n in a string if the user entered more characters
        // than MAX_LINE_LENGTH
        if ( count_char(line2[i], line) ) {
            // there was at least one match
            match_count++;
        }
        i++;
    }
    printf(
        "I found characters from the second line %d times in the first line.\n", 
        match_count
    );
}

// Loop through the string line and return
// how many times c appears in line
int count_char(char c, char *line) {
    int i = 0;
    int char_count = 0;
    while (i < MAX_LINE_LENGTH && line[i] != '\0') { // have checked i characters
        if (line[i] == c) {
            char_count++;
        }
        i++;
    }
    return char_count;
}





