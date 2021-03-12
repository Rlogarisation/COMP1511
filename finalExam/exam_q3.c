// Zheng Luo (z5206267@ad.unsw.edu.au)
// 14/Aug/2020

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 1000

void findCounterpart(int *array, int size);

int main(void) {
    int array[MAX_SIZE] = {0};
    int number = 0;
    int counter = 0;
    while (scanf("%d", &number) != EOF && counter < MAX_SIZE) {
        array[counter] = number;
        counter++;
    }
    
    findCounterpart(array, counter);
    return 0;
}

void findCounterpart(int *array, int size) {
    int numberOfCounterpart = 0;
    int counterA = 0;
    while (counterA < size) {
        while (array[counterA] < 0) {
            counterA++;
        }
        int counterB = counterA + 1;
        while (counterB < size) {
            if (array[counterA] == - array[counterB]) {
                break;
            }
            counterB++;
        }
        if (counterB == size) {
            numberOfCounterpart++;
        }
        counterA++;
    }
    printf("%d\n", numberOfCounterpart);

}
