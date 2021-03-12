// A Command Line Arguments demo
// Showing the ability to read command line arguments
// as numbers and using them

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int total = 0;
    
    int i = 1;
    while (i < argc) { // have added i - 1 numbers to the total
        total += strtol(argv[i], NULL, 10); // What does base 10 means?
        i++;
    }    
    printf("Total is %d.\n", total);
}

/*
The C library function 
long int strtol(const char *str, char **endptr, int base) 
converts the initial part of the string in str to a long int value 
according to the given base, 
which must be between 2 and 36 inclusive, or be the special value 0.
*/

// strtol will ignore/skip non-integer input.
// ./strtol 2 Roger ! 
// Total is 2. 