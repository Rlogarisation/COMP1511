// ZHENG LUO (z5206267@cse.unsw.edu.au)
// Written 26/May/2020
/*
We need to set up our grid and the tourist's position
The tourist needs to move one step at a time
Each time the tourist visits a location, we set it to 1
We also check each location to make sure it's new
*/

#include<stdio.h>

// Define the size of map
#define N_ROWS 10
#define N_COLS 10

// Function to print the map
void printMap(int map[N_ROWS][N_COLS], int posR, int posC);

int main(void) {
    // Filled the whole map with 0 initially
    int map[N_ROWS][N_COLS] = {0};

    // Initiate the tourist in the middle of map
    int posR = N_ROWS / 2;
    int posC = N_COLS / 2;

    printMap(map, posR, posC); 
    // Be careful, "map" could give the whole array, map[][] only gives a position.

    int gameOver = 0;
    while (!gameOver) {
        // Losing the game?
        if (map[posR][posC] > 0) { // we've been hewre before
            printf("I've already seen this location, how boring.\n");
            gameOver = 1;
        }

        // mark where we've been as digit 1
        map[posR][posC]++;   
    
        // take input and move the tourist
        printf("Please type in a num-pad direction: ");
        int inputDir = 0;
        scanf("%d", &inputDir);
        if (inputDir == 2) { // down
            posR++;
        } else if (inputDir == 4) { // left
            posC--;
        } else if (inputDir == 6) { // right
            posC++;
        } else if (inputDir == 8) { // up
            posR--;
        } else if (inputDir == 0) { // exit
            gameOver = 1;
        }
        // what if the tourist walks off the map?
        // don't allow the tourist to leave the map
        if (posR < 0) { // top
            posR = 0;
        } else if (posR >= N_ROWS) { // bottom
            posR = N_ROWS - 1;
        } else if (posC < 0) { // left
            posC = 0;
        } else if (posC >= N_COLS) { // right
            posC = N_COLS - 1;
        }
        
        printMap(map, posR, posC);
    }
    
    return 0;
}
    
    
    
    
 











// Function to print the map filled with 0 initially
// Prints the map, by printing the integer value stored in
// each element of the 2-dimensional map array.
// Prints a T instead at the position posR, posC
void printMap(int map[N_ROWS][N_COLS], int posR, int posC) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            if(posR == row && posC == col) { // at the tourist's position
                printf("T ");
            } else {
                printf("%d ", map[row][col]);
            }            
            col++;
        }
        row++;
        printf("\n");
    }
}