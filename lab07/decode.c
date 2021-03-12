/*
Zheng Luo (z5206267@ad.unsw.edu.au)
Written by 15/July/2020

which decrypts text encrypted by substitution.c
e.g
./decode
qwertyuiopasdfghjklzxcvbnm
O vql leqktr gy rtfzolzl qfr zit rqka
I was scared of dentists and the dark
O vql leqktr gy hktzzn uoksl qfr lzqkzofu egfctklqzogfl
I was scared of pretty girls and starting conversations
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
// 26 + 1 (including \n)
#define NUMBER_OF_LETTERS 27
#define MAX_INPUT 1024

/*
Create 3 array, normal array, encrypted array, input array.
*/

void substitution(char *encryptedArray, char *normalArray, char *inputArray);

int main (void) {
    // Initiate normal array.
    char normalArray[NUMBER_OF_LETTERS] = "abcdefghijklmnopqrstuvwxyz";
    // Initiate encrypted array.
    char encryptedArray[NUMBER_OF_LETTERS];
    fgets(encryptedArray, NUMBER_OF_LETTERS, stdin);
    // Deal with input array.
    char inputArray[MAX_INPUT];
    while (fgets(inputArray, MAX_INPUT, stdin) != NULL) { 
        if (inputArray[0] != '\n') {
            substitution(encryptedArray, normalArray, inputArray);
            fputs(inputArray, stdout);
        }
        
    }
    return 0;
}

void substitution(char *encryptedArray, char *normalArray, char *inputArray) {
    int counter = 0;
    while (counter < strlen(inputArray)) {
        // Lower case:
        if (inputArray[counter] >= 'a' && inputArray[counter] <= 'z') 
        {
            int counterForMarching = 0;
            while (counterForMarching < NUMBER_OF_LETTERS) {
                if (inputArray[counter] == encryptedArray[counterForMarching]) {
                    inputArray[counter] = normalArray[counterForMarching];
                    break;
                }
                counterForMarching++;
            }
        }
        // Upper case:
        else if (inputArray[counter] >= 'A' && inputArray[counter] <= 'Z')
        {
            int counterForMarching = 0;
            // Convert into lower case.
            inputArray[counter] = tolower(inputArray[counter]);
            while (counterForMarching < NUMBER_OF_LETTERS) {
                if (inputArray[counter] == encryptedArray[counterForMarching]) {
                    // Convert back to upper case.
                    inputArray[counter] = 
                    toupper(normalArray[counterForMarching]);
                    break;
                }
                counterForMarching++;
            }
        }
        
        counter++;
    }
}