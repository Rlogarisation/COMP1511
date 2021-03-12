// Zheng Luo (z5206267@cse.unsw.edu.au)
// Date: 21/June/2020
// UNSW Freefall assignment.
// Update 24/June: Everything is finished except for most of the stage 4.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The size of the array.
#define SIZE 15
// The meaning of each command number.
#define EMPTY 0
#define STONE 1
#define MARCHING_BLOCK 2
// Define the number of stone will be destroyed by the laser.
#define LASERPOWER 3
// For marching blocks, define 4 is left, 6 is right, 2 is down.
// MOVED is used to prevent repeated movements
#define MOVED 1
#define DOWN 2
#define LEFT 4
#define RIGHT 6
// Define the valid input range for placing stone in stage 1.1.
#define EXPRESSION_FOR_VALID_ROW ((row[counterForSets] >= 0)\
&& (row[counterForSets] < 15))
#define EXPRESSION_FOR_VALID_COLUMN ((column[counterForSets] >= 0)\
&& (column[counterForSets] < 15))
#define EXPRESSION_FOR_VALID_LENGTH ((length[counterForSets] >= 0)\
&& (length[counterForSets] <= 15))

// The functions below follow same order as appeared in main function.
// Scan inputs and placing stones.
void placingStone(int map[SIZE][SIZE], int playerX);

// Print out the map.
void printMap(int map[SIZE][SIZE], int playerX);

// Move the player for stage 1.2.
int playerMovement(int command, int direction, int playerX);

// Detect the objects(stone/TNT) above the player, clear them as required.
void clearObject(int map[SIZE][SIZE], int playerX);

// Check the end game condition for stage 2.2.
int wonConditionCheck(int map[SIZE][SIZE]);
int lostConditionCheck(int map[SIZE][SIZE]);

// Limit the range of counterForMarchingBlocks to stay between 1-4.
int rangeForCounterMarchingBlocks(int counterForMarchingBlocks);

// Shifting for both non-marching and marching blocks.
void shiftBlocks(int map[SIZE][SIZE], int playerX, int numberForDirection, 
int gameLost);

// Vertically flip the map.
void verticallyFlip(int map[SIZE][SIZE], int playerX);



int main (void) {
    // This line creates our 2D array called "map" and sets all as EMPTY.
    int map[SIZE][SIZE] = {EMPTY};
    // This line creates out playerX variable. 
    int playerX = SIZE / 2;
    // Scan input and placing stones.
    placingStone(map, playerX);
    // Print out the map.
    printMap(map, playerX);
    
    int gameLost = 0; // For stage 2.1, 0 means game is still running.
    int command4Used = 0; // For stage 3.1, 0 means command 4 havent been used.
    // Initiate a counter for counting the number of downshift it has made,
    // in order to decide next movement for stage 4.1.
    int counterForMarchingBlocks = 0;
    int command, directionForPlayer; // Initiate command and direction variables.

    // This programme continue to operate until the command is end of file (EOF).
    while (scanf("%d", &command) != EOF) {
        // Process the different types of command below.
        if (command == 1) { // Stage 1.2: Moving the player.
            scanf("%d", &directionForPlayer);
            // It will continue from last position by equating these. 
            playerX = playerMovement(command, directionForPlayer, playerX);  
        } 
        else if (command == 2) { // Stage 1.3: Firing the laser.
            clearObject(map, playerX);
        }
        else if (command == 3) { // Stage 2.1: Shift everything down.
            // Check lost game condition first, if not lose yet, proceed.
            while (lostConditionCheck(map) == 1) {
                gameLost = 1;
                break;
            }
            // The numbers of downshift command +1 if within range,
            // and always counting within the range of 1 to 4.
            counterForMarchingBlocks = 
            rangeForCounterMarchingBlocks(counterForMarchingBlocks);

            shiftBlocks(map, playerX, counterForMarchingBlocks, gameLost);
        }
        // Stage 3.1, vertically flip.
        else if (command == 4 && command4Used == 0) { 
            // command4 has been used now, this function cannot be used again.
            command4Used = 1;

            verticallyFlip(map, playerX);
        }
        // Print out the map for the lastest command.
        printMap(map, playerX);
        // Print out end game statement.
        if (wonConditionCheck(map) == 1) {
            printf("Game Won!\n");
            break;
        } else if (gameLost == 1) {
            printf("Game Lost!\n");
            break;
        }
    }
    return 0;
}




// Functions below:


void placingStone(int map[SIZE][SIZE], int playerX) {
    // Scan in the number of lines of blocks.
    int linesOfStone;
    printf("How many lines of stone? ");
    scanf("%d", &linesOfStone);

    // Scan the locations of the lines as a group of four integers.
    // Create 4 different arrays for row, column, length, value correspondently
    // with the same size as input above.
    int row[linesOfStone], column[linesOfStone],
    length[linesOfStone], value[linesOfStone]; 

    printf("Enter lines of stone:\n");
    // To consist with the number of lines,
    // corresponded amount of sets of four integers have to be scanned.
    int counterForScanLocation = 0;
    while (counterForScanLocation < linesOfStone) {
        scanf("%d %d %d %d", &row[counterForScanLocation], 
        &column[counterForScanLocation],
        &length[counterForScanLocation], &value[counterForScanLocation]);

        counterForScanLocation++;
    }

    // Stage 1.1: Placing stone.

    int counterForSets = 0;
    // Moving the inputs from array to map by
    // dealing with each set of 4 integer command once at a time.
    while (counterForSets < linesOfStone) {
        int counterForLength = 0;
        // Dealing with each square in each set once at a time
        while (counterForLength < length[counterForSets]) {
            if (EXPRESSION_FOR_VALID_ROW && EXPRESSION_FOR_VALID_COLUMN && 
                EXPRESSION_FOR_VALID_LENGTH) {
                map[row[counterForSets]][column[counterForSets] + 
                counterForLength] = value[counterForSets];
            }
            
            counterForLength++;
        }
        counterForSets++;
    }
}



// Print out the contents of the map array. Then print out the player line
// which will depends on the playerX variable.
void printMap(int map[SIZE][SIZE], int playerX) {
    
    // Print values from the map array.
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }    
    // Print the player line.
    i = 0;
    while (i < playerX) {
        printf("  ");
        i++;
    }
    printf("P\n");
}



int playerMovement(int command, int directionForPlayer, int playerX) {
    // command == 1: Valid command to initiate the movement.
    // playerX < (SIZE - 1): Make sure the player will stay within the range.
    if (command == 1 && playerX < (SIZE - 1)) {
        if (directionForPlayer == -1) { // Left
            playerX--;
        } else if (directionForPlayer == 1) { // Right
            playerX++;
        } 
    } 
    return playerX;

}


int wonConditionCheck(int map[SIZE][SIZE]) {
    int gameWon = 1;
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            // If map is not empty for all squares, then no gameWon.
            if (map[i][j] != EMPTY) {
                gameWon = 0;
            }
            j++;
        }
        i++;
    }
    return gameWon;
      
}

int lostConditionCheck(int map[SIZE][SIZE]) {
    int gameLost = 0;
    int row = SIZE - 1; // Bottom line
    int column = 0;

    while (column < SIZE) {
        if (map[row][column] == STONE) {
            gameLost = 1;
        }
        column++;
    }     

    return gameLost;
}



int rangeForCounterMarchingBlocks(int counterForMarchingBlocks) {
    if (counterForMarchingBlocks < 4) {
        counterForMarchingBlocks++;
    } else {
        counterForMarchingBlocks = 1;
    }
    return counterForMarchingBlocks;
}



void shiftBlocks(int map[SIZE][SIZE], int playerX, int numberForDirection, 
int gameLost) {
    
    // Create an array to make sure that marching block will only move once.
    // If compiler detects one, which means moved already,
    //  it will not move again by single shifting commmand.
    int arrayForRepeatMoving[SIZE + 1][SIZE + 1] = {0};

    // Scan and filter everything in reverse manner,
    // i.e. from bottom right to top right then (column - 1) and repeat.
    int counterForColumn = SIZE - 1; 
    while (counterForColumn >= 0 && gameLost == 0) {
        int counterForRow = SIZE - 1;

        while (counterForRow > 0) {

            // Specfic the direction.
            // Calculate the next moving direction for marching block 
            // by counterForMarchingBlocks.
            int direction = numberForDirection;
            if (numberForDirection == 1 || numberForDirection == 3) {
                direction = 2; // 2 is down
            } else if (numberForDirection == 2) {
                direction = 6; // 6 is right
            } else if (numberForDirection == 4) {
                direction = 4; // 4 is left
            }

            // If marching block(2) has been detected from one square below.
            if (map[counterForRow - 1][counterForColumn] == MARCHING_BLOCK) { 

                if (direction == DOWN) 
                {
                    // Move 2 to the desire location.
                    map[counterForRow][counterForColumn] = 
                    map[counterForRow - 1][counterForColumn];
                    // Make original position empty.
                    map[counterForRow - 1][counterForColumn] = EMPTY;
                    // Assume next new line come from above is empty.
                    if (counterForRow == 1) {
                        map[0][counterForColumn] = EMPTY;
                    }
                    
                }
                else if (direction == RIGHT)
                {
                    // Do not move if outside the range, and mark.
                    if (counterForColumn + 1 >= SIZE) {
                        arrayForRepeatMoving[counterForRow - 1]
                        [counterForColumn] = MOVED;
                    } else {  // Move 2 to the desire location.
                        map[counterForRow - 1][counterForColumn + 1] =
                        map[counterForRow - 1][counterForColumn];
                        // Make original position empty.
                        map[counterForRow - 1][counterForColumn] = EMPTY;
                    }
                    
                }
                else if (direction == LEFT && 
                arrayForRepeatMoving[counterForRow - 1][counterForColumn + 1] != 
                MOVED && counterForColumn - 1 >= 0)
                {
                    // Move 2 to the desire location.
                    map[counterForRow - 1][counterForColumn - 1] =
                    map[counterForRow - 1][counterForColumn];
                    // Make original position empty.
                    map[counterForRow - 1][counterForColumn] = EMPTY;
                    // Mark the old position has been moved.
                    arrayForRepeatMoving[counterForRow - 1]
                    [counterForColumn] = MOVED;
                }
            }

            // If non-marching block has been detected.
            else if (map[counterForRow - 1][counterForColumn] != 
            MARCHING_BLOCK && 
            arrayForRepeatMoving[counterForRow][counterForColumn + 1] != MOVED
            /* To prevent moved square to be erased*/)
            { 
                // Move 2 to the desire location.
                map[counterForRow][counterForColumn] = 
                map[counterForRow - 1][counterForColumn];
                // Make original position empty.
                map[counterForRow - 1][counterForColumn] = EMPTY;
                // Assume next line come from above is empty.
                if (counterForRow == 1) {
                    map[0][counterForColumn] = EMPTY;
                }
            }

            counterForRow--;
        }
        counterForColumn--;
    }
}


    
void clearObject(int map[SIZE][SIZE], int playerX) {
    // Detect the existence of stone above the player.
    int counterForLaser = 0;
    while (counterForLaser < SIZE) {

        // If non-empty is detected, proceed.
        // Otherwise it will keep scanning until non-empty is detected.
        if (map[SIZE - 1 - counterForLaser][playerX] != EMPTY) {

            // Clear each stone/TNT once at a time
            int counterForClearing = 1;
            while (counterForClearing < LASERPOWER + 1 && 
            (SIZE - counterForClearing - counterForLaser) >= 0 && 
            (SIZE - counterForClearing - counterForLaser) < SIZE) {

                // If stone is detected, clear itself in this while loop.
                if (map[SIZE - counterForClearing - 
                counterForLaser][playerX] == STONE) { 
                    map[SIZE - counterForClearing - 
                    counterForLaser][playerX] = EMPTY;
                } 
                // If TNT is detected (value 3 - 9), clear circle of stones.
                else if (map[SIZE - counterForClearing - 
                counterForLaser][playerX] != STONE &&
                map[SIZE - counterForClearing - 
                counterForLaser][playerX] != EMPTY)
                {

                    // Determine the radius of TNT base on its value.
                    int radiusForTNT = map[SIZE - counterForClearing - 
                    counterForLaser][playerX];
                    // EMPTY if (within the range && STONE in the square only).
                    int counterForRow = 0;
                    while (counterForRow < SIZE) {
                        int counterForColumn = 0;
                        while (counterForColumn < SIZE) {

                            // Calculate the range for TNT.
                            int rangeForTNT = sqrt((counterForRow - 
                            (SIZE - counterForClearing - counterForLaser)) *
                            (counterForRow - 
                            (SIZE - counterForClearing - counterForLaser)) + 
                            (counterForColumn - playerX) * 
                            (counterForColumn - playerX));
                            // If distance between TNT and chosen point is 
                            // smaller than the power range of TNT,
                            // all stones within the area will be cleared.
                            
                            if ((rangeForTNT< radiusForTNT) && 
                            (map[counterForRow][counterForColumn] == STONE
                            || map[counterForRow][counterForColumn] == 
                            radiusForTNT)) 
                            {
                                map[counterForRow][counterForColumn] = EMPTY;
                            }
                            counterForColumn++;
                        }
                        counterForRow++;
                    }
                }
                
                counterForClearing++;
            }
            // The program will break when it clear 3 stones,
            // Otherwise it will keep firing laser utill 
            // whole column is empty.
            break; 
        }  
        counterForLaser++;
    }

}



void verticallyFlip(int map[SIZE][SIZE], int playerX) {
    int temporaryArray[SIZE][SIZE]; // For swapping numbers

    // Copy the old array into a temporary array
    int counterForColumn = 0;
    while (counterForColumn < SIZE) {
        int counterForRow = 0;
        while (counterForRow < SIZE) { 
            temporaryArray[counterForRow][counterForColumn] = 
            map[counterForRow][counterForColumn];
            counterForRow++;
        }
        counterForColumn++;
    } 
    // Flip the array by moving data from temporary array to map[][].
    counterForColumn = 0;
    while (counterForColumn < SIZE) {
        int counterForRow = 0;
        while (counterForRow < SIZE) { 
            map[SIZE - 1 - counterForRow][counterForColumn] = 
            temporaryArray[counterForRow][counterForColumn];
            counterForRow++;
        }
        counterForColumn++;
    } 
}