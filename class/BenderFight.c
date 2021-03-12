// Bender Fight

// A simulation of a fight between element benders
// based loosely on Avatar the Last Air Bender

// A demonstration of the use of structs
// with strings and pointers

// Marc Chee (cs1511@cse.unsw.edu.au), July 2020

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define TEAM_SIZE 4

struct bender {
    char name[MAX_LENGTH];
    char element[MAX_LENGTH];
    int power;
    int health;
};

void attack(struct bender *attacker, struct bender *target);
int stillAlive(struct bender *solo, struct bender team[TEAM_SIZE]);

int main(void) {
    struct bender companions[TEAM_SIZE];
    // Aang
    strcpy(companions[0].name, "Aang");
    strcpy(companions[0].element, "Air");
    companions[0].power = 10;
    companions[0].health = 5;
    // Katara
    strcpy(companions[1].name, "Katara");
    strcpy(companions[1].element, "Water");
    companions[1].power = 7;
    companions[1].health = 7;
    // Sokka
    strcpy(companions[2].name, "Sokka");
    strcpy(companions[2].element, "None");
    companions[2].power = 3;
    companions[2].health = 10;
    // Toph
    strcpy(companions[3].name, "Toph");
    strcpy(companions[3].element, "Earth");
    companions[3].power = 8;
    companions[3].health = 6;
    
    // Individual enemy
    struct bender zuko;
    strcpy(zuko.name, "Prince Zuko");
    strcpy(zuko.element, "Fire");
    zuko.power = 20;
    zuko.health = 20;
    
    // Main loop of the fight
    //printf("Please type in a number to seed the random generator: ");
    //int randomSeed = 0;
    //scanf("%d", &randomSeed);
    srand(time(NULL));
    
    int currentCompanion = 0;
    
    // loop until either the companions or zuko are out of the fight
    while (stillAlive(&zuko, companions)) {
        if (companions[currentCompanion].health <= 0) {
            // this bender has been knocked out, move on to the next one
            currentCompanion++;
        }
        // Have attacks from both the current companion and zuko against each other
        attack(&companions[currentCompanion], &zuko);
        attack(&zuko, &companions[currentCompanion]);
    }
    printf("The fight has ended.\n");
    
}

// attack will lower the target's health by the attacker's power
// It will also print information about the attack
void attack(struct bender *attacker, struct bender *target) {
    int damage = rand() % attacker->power;
    printf(
        "%s attacks %s for %d damage.\n", 
        attacker->name, 
        target->name, 
        damage
    );
    target->health -= damage;
    if (target->health <= 0) { // target is knocked out
        printf("%s has been knocked out.\n", target->name);
    }
}

// stillAlive returns 1 if both sides still have some health left.
// It returns 0 if either or both teams have no health remaining.
// Not all the benders in team need to have health for their team
// to be considered alive.
int stillAlive(struct bender *solo, struct bender team[TEAM_SIZE]) {
    // does the solo bender have health?
    int sAlive = 0;
    if (solo->health > 0) {
        sAlive = 1;
    }
    
    // does anyone on the team have health?
    int tAlive = 0;
    int i = 0;
    while (i < TEAM_SIZE && !tAlive) {
        if (team[i].health > 0) {
            tAlive = 1;
        }
        i++;
    } // tAlive == 1 if any bender has health > 0
    
    return sAlive && tAlive;
}




