#include <stdio.h>

// Return the number of increasing pairs in the array.
int count_increasing(int size, int array[size][2]) {
    int counterForIncreasing = 0;
    int counter = 0;
    while (counter < size) {
        if (array[counter][0] < array[counter][1]) {
            counterForIncreasing++;
        }
        counter++;
    }
    return counterForIncreasing;
}

// This is a simple main function which could be used
// to test your count_increasing function.
// It will not be marked.
// Only your count_increasing function will be marked.

#define TEST_ARRAY_SIZE 5

int main(void) {
    int test_array[TEST_ARRAY_SIZE][2] = {{16, 7}, {8, 12}, {13, -9}, {-3, 12}, {1, 1}};

    int result = count_increasing(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}
