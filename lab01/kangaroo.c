// A simple C program that prints an ASCII kangaroo
// Written 7/2/2018
//  by Andrew Taylor (andrewt@unsw.edu.au)
// as a lab example for COMP1511

#include <stdio.h>

int main(void) {

    printf("\n");
    printf("  /\\   ___\n");
    printf(" <__\\_/    \\\n");
    printf("    \\_  /  _\\\n");
    printf("      \\_\\ / \\\\\n");
    printf("        //   \\\\\n");
    printf("      =//     \\==\n");
    printf("\n");

    return 0;
}
// So "\" is special character, in order to print it,
// we need to type "\\" in order to printf "\"
// Similarly "\\" required "\\\\"
/*

  /\   ___
 <__\_/    \
    \_  /  _\
      \_\ / \\
        //   \\
      =//     \==

*/
