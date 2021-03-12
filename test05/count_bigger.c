#include <stdio.h>

#define MIN -99
#define MAX 99

// return the number of "bigger" values in an array (i.e. larger than 99
// or smaller than -99).
int count_bigger(int length, int array[]) {
    int counter = 0;
    int counterForRequired = 0;
    while (counter < length) {
        if (array[counter] < MIN || array[counter] > MAX) {
            counterForRequired++;
        }
        counter++;
    }
    return counterForRequired;
}

// This is a simple main function which could be used
// to test your count_bigger function.
// It will not be marked.
// Only your count_bigger function will be marked.

#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    int result = count_bigger(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}