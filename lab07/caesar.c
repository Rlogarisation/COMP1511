/*
Zheng Luo (z5206267@ad.unsw.edu.au)
Written by 14/July/2020

which reads characters from its input and 
writes the characters to its output encrypted with a Caesar cipher.

The number of positions to shift will be given to your program 
as the first line of input. 
The next lines of input will be the actual text to be shifted.

Characters other than letters should not be encrypted.

Your program should stop only at the end of input.

Your program should contain at least one function other than main.
e.g
./caesar
1
Water. Earth. Fire. Air.
Xbufs. Fbsui. Gjsf. Bjs.
Long ago, the four nations lived together in harmony.
Mpoh bhp, uif gpvs obujpot mjwfe uphfuifs jo ibsnpoz.
*/

#include<stdio.h>

#define RANGE_FOR_LOWER_CASE character >= 'a' && character <= 'z'
#define RANGE_FOR_UPPER_CASE character >= 'A' && character <= 'Z'



int encryptCharacter(int numberOfShift, int character);

int main (void) {
    int numberOfShift;
    scanf("%d", &numberOfShift); 

    int inputChar = getchar();
    while (inputChar != EOF) {
        putchar(encryptCharacter(numberOfShift, inputChar));
        // get next character.
        inputChar = getchar();
    }
    return 0;
}

int encryptCharacter(int numberOfShift, int character) {
    // Rearrange number of shift into range (26 letters)
    int modifiedNumberOfShift = numberOfShift % (26);

    if (RANGE_FOR_LOWER_CASE) {
        // If encrypted character is over 'z' after the shift,
        // then shift start from 'a'.
        if (character + modifiedNumberOfShift > 'z') {
            return character + modifiedNumberOfShift - 26;
        } else if (character + modifiedNumberOfShift < 'a') { 
            // If encrypted character is over 'a' after the (negative) shift,
            // continue decreasing shift from 'z'
            return character + modifiedNumberOfShift + 26;
        } else { // When encrypted character is within the range.
            return character + modifiedNumberOfShift;
        }
    } else if (RANGE_FOR_UPPER_CASE) {
        // If encrypted character is over 'Z' after the shift,
        // then shift start from 'A'.
        if (character + modifiedNumberOfShift > 'Z') {
            return character + modifiedNumberOfShift - 26;
        } else if (character + modifiedNumberOfShift < 'A') { 
            // If encrypted character is over 'A' after the (negative) shift,
            // continue decreasing shift from 'Z'
            return character + modifiedNumberOfShift + 26;
        } else { // When encrypted character is within the range.
            return character + modifiedNumberOfShift;
        }
    } 
    else { // else remain the same.
        return character;
    }
}

/*
./caesar 
17 
J qdwmanm hnjab yjbbnm jwm vh kaxcqna jwm R mrblxenanm cqn wnf Jejcja, 
jw jraknwmna wjvnm Jjwp, jwm jucqxdpq qrb jraknwmrwp btruub jan panjc, 
qn qjb j uxc cx unjaw knoxan qn'b anjmh cx bjen jwhxwn. Kdc R knurnen 
Jjwp ljw bjen cqn fxaum. 
A hundred years passed and my brother and I discovered the new Avatar, 
an airbender named Aang, and although his airbending skills are great, 
he has a lot to learn before he's ready to save anyone. But I believe 
Aang can save the world.
*/