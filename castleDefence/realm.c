// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by Zheng Luo (z5206267@ad.unsw.edu.au)
// on July/2020
//
// Version 1.0.0 (2020-07-20): Assignment released.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "realm.h"
///////////////////////////////////////////////////////////////////////

// `struct realm` represents a realm, which represents the state of the
// entire program. It is mainly used to point to a linked list of 
// locations, though you may want to add other fields to it.
struct realm {
    struct location *castle;
    struct location *lair;
};

// `struct location` represents a location, which could be a land,
// a tower, or a castle. Each of those places has a different type
// of information that this struct will need to store.
struct location {
    char name[MAX_NAME_LENGTH];
    int power;
    int uses;
    int defense;
    struct enemy *enemies;
    struct location *next;
    Effect effect;
};

// `struct enemy` represents an enemy, which will move through the
// realm (to each location). Towers can deal damage to it, and
// it can deal damage to the Castle.
struct enemy {
    char name[MAX_NAME_LENGTH];
    int hp;
    int hp_Given;
    struct enemy *next;
};


///////////////////////////////////////////////////////////////////////

// Function prototypes for helper functions
static Location new_location(char *name);
static void print_tower(char *name, int power, int uses, Effect effect);
static void print_land(char *name);
static void print_castle(char *name, int defense);
static void print_enemy(char *name, int cur_hp, int max_hp);
// Self-created functions below, 
// its detailed introductions are located in Self-Created functions
// after stage 5 function.
static void remove_enemy(struct location *current, struct enemy *currentEnemy);
static int search_function_tower (struct location *current, char *search_term);
static int search_function_enemy (struct enemy *current, char *search_term);
static void sorting(struct location *current);

///////////////////////////////////////////////////////////////////////


// Create a new realm, and return a pointer to it.
// You may need to change this function in later stages.
Realm new_realm(void) {
    struct realm *realm = malloc(sizeof(struct realm));
    realm->castle = new_location("Castle");
    realm->lair = new_location("Lair");
    // Castle's defense health.
    realm->castle->defense = STARTING_CASTLE_HP;
    // Let lair pointing to NULL.
    realm->lair->next = NULL;
    // Let the enemy in castle and lair pointing to NULL.
    realm->castle->enemies = NULL;
    realm->lair->enemies = NULL;

    if (realm->castle != NULL && realm->lair != NULL) {
        realm->castle->next = realm->lair;
    }

    return realm;
}


// Return a new location created with malloc.
static Location new_location(char *name) {
    // Allocate memory for new locations.
    struct location *place = malloc(sizeof(struct location));
    // Initiate the NULL pointer for place->enemy.
    place->enemies = NULL;
    // Initiate the variable for place->power and place->uses.
    place->power = 0;
    place->uses = 0;
    place->effect = EFFECT_NONE;
    // Assign the name into location.
    strcpy(place->name, name);
    // Return pointer for new location.
    return place;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a new location to the realm, and return the total number of
// locations in the realm.
int add_location(Realm realm, char *name) {
    // Assign the new position as newLand.
    struct location *newLand = new_location(name);
    // Assign the corresponded name into newLand.
    strcpy(newLand->name, name);
    // Assuming 4 buildings.
    int counter = 4;
    // If no building in land yet, which means
    // castle is connecting to the lair.
    if (realm->castle->next == realm->lair) {
        // castle(head)->newLand->Lair->NULL
        newLand->next = realm->lair;
        realm->castle->next = newLand;
        counter--;
    } else { // Land(s) exist between castle and 
        // (head)->original    Lair->NULL
        //            |          |
        //             ->newLand->
        // Loop thro until the insert position is reached.

        // realm->land is same as head.
        // Here current should point to the first newLand, not NULL.
        struct location *current = realm->castle->next;
        while (current->next != realm->lair) {
            counter++;
            current = current->next;
        }
        newLand->next = current->next;
        current->next = newLand;
        
    }

    return counter; 
}

// Print out the realm by looping through everything in the realm,
// including castle/land/tower/lair and enemies under each location.
// The print_realm function take realm as input,
// no output due to its void type function.
void print_realm(Realm realm) {
    // Pointer "current" start from first land.
    struct location *current = realm->castle;
    // Print out castle, lands and lair.
    // Loop thro until current reached NULL terminator at the end.
    while (current != NULL) {
        // Land will be printed if there is no power or uses.
        if (strcmp(current->name, "Castle") == 0) {
            // Print out castle.
            print_castle(realm->castle->name, realm->castle->defense);
        } else if (current->power == 0 || current->uses == 0) {
            print_land(current->name);
        } 
        else {
            print_tower(current->name, current->power, current->uses, 
            current->effect);
        }
         
        // If there's enemies under the location, proceed.
        if (current->enemies != NULL) {
            // Create a new pointer "currentEnemy" at current enemies,
            // in order to loop thro enemies under each location.
            struct enemy *currentEnemy = current->enemies;
            // Loop thro each enemy under the location
            while (currentEnemy != NULL) {
                // Print out enermies.
                print_enemy(currentEnemy->name, 
                currentEnemy->hp, currentEnemy->hp_Given);
                // Move to the next enemy under the same location.
                currentEnemy = currentEnemy->next;
            }
            
            
        }
        current = current->next;
    }
    

}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add an enemy to the realm by looping through the list, and insert it
// at the end of the list. 
// The function take realm, location name, the name of enemy, its hp as input.
// The function will return SUCCESS(0) if new enemy if successfully created.
int new_enemy(Realm realm, char *location_name, char *name, int hp) {
    // Ensure that the stats you have been given for HP are not below 1. 
    // If they are, return ERROR_INVALID_STAT.
    if (hp < 1) {
        return ERROR_INVALID_STAT;
    }
    // Find the Location called location_name. 
    // If one does not exist, return ERROR_NO_LOCATION
    // Create a pointer current, used to loop thro the list, 
    // in order to match the same name.
    struct location *current = realm->castle;

    while (current != NULL) {
        if (strcmp(current->name,location_name) == 0) {
            // Place a new enemy, with the given stats, 
            // directly after the last enemy at the location you found above.
            struct enemy *newEnemy = malloc(sizeof(struct enemy));
            // Create a pointer "currentEnemy", 
            // in order to insert the new enemy.
            struct enemy *currentEnemy = NULL;
            // Assign the name and hp to the enemy.
            strcpy(newEnemy->name, name);
            newEnemy->hp = hp;
            newEnemy->hp_Given = hp;
            // Link another end of newEnemy to NULL.
            newEnemy->next = NULL;

            // If there is nothing in the enemies section yet.
            if (current->enemies == NULL) {
                // Link the newEnemy under the tower.
                current->enemies = newEnemy;
            } else { // These is existing enemy in enemies section.
                // Loop thro enemies until current->enemies->next == NULL.
                currentEnemy = current->enemies;
                while (currentEnemy->next != NULL) {
                    currentEnemy = currentEnemy->next;
                }
                // Inserting newEnemy into list.
                currentEnemy->next = newEnemy;

            }
            // Break the program, so it will not continue to scan the same name
            // for the rest of the linked list.
            break;
        }
        current = current->next;
        if (current == NULL) {
            return ERROR_NO_LOCATION;
        }
    }
    return SUCCESS;
}

// Add a new tower to the realm by looping through the list, and insert it
// after previous position.
// The function take realm, previous position, the new name of tower, 
// its power and uses as input.
// The function will return SUCCESS(0) if new tower if successfully created.
int new_tower(Realm realm, char *prev_name, char *name, int power, int uses) {
    // Ensure that the stats you have been given for power 
    // and uses are not below 1. If they are, return ERROR_INVALID_STAT.
    if (power < 1 || uses < 1) {
        return ERROR_INVALID_STAT;
    }

    // Create a pointer current, used to loop thro the list, 
    // in order to match the same name.
    struct location *current = realm->castle;
    while (current != NULL) {
        // If current location is same name as required.
        if (strcmp(prev_name, current->name) == 0) {
            // Place a new tower, with the given stats, 
            // directly after the location which you found above. 
            // This tower is inserted into the linked list, 
            // which adds an element and doesn't replace the Location prev_name.
            
            // Create a new location for new tower.
            struct location *newTower = new_location(name);
            // Assign name, power and uses to new tower.
            strcpy(newTower->name, name);
            newTower->power = power;
            newTower->uses = uses;
            // For stage 5, effect of EFFECT_NONE added to all new tower.
            newTower->effect = EFFECT_NONE;
            // Assign the new tower into desired position.
            newTower->next = current->next;
            current->next = newTower;
            // Break the program, so it will not continue to scan the same name
            // for the rest of the linked list.
            break;
        }

        current = current->next;
        // If current reaches the NULL after the move, return error.
        if (current == NULL) {
            return ERROR_NO_LOCATION;
        }

    }

    // Return SUCCESS to indicate success.
    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Destroy the realm, and free any associated memory by looping through 
// all the links including both tower/land/castle/lair and enemies.
// The function take realm as input, 
// there is no output as this is void type function.
void destroy_realm(Realm realm) {
    // Free the enemies first, then locations, and lastly castle and lair.
    // Create two pointers, one "current" to loop thro the linked list,
    // another "privious" pointing to the memory will be free.
    struct location *current = realm->castle;

    // Create two while loop to scan thro each enemy in each location.
    // Free location as decleared in new_location.
    while (current != NULL) {
        struct location *previous = NULL;
        struct enemy *currentEnemy = current->enemies;
        // Free enemies as decleared in new_enemy.
        while (currentEnemy != NULL) {
            struct enemy *previousEnemy = NULL;

            previousEnemy = currentEnemy;
            currentEnemy = currentEnemy->next;
            free(previousEnemy);
        }
        previous = current;
        current = current->next;
        free(previous);
    }
    // At the end, free realm as decleared in Realm new_realm(void).
    free(realm);
}



/*
Advance enemies towards the castle.
Advance_enemies will go through the realm, 
moving each enemy from their current Location to 
the Location above in the linked list. 
The function take realm as input, 
the number of enemies who pass the castle will be recorded as output.
*/
int advance_enemies(Realm realm) {
    // Create a pointer "current", started at Castle
    // (We could started From Lair, but required to inverted the link),
    // used to loop thro the linked list, and move the enemies forward.
    struct location *current = realm->castle;
    // Create a pointer "previous", started at NULL,
    // previous always move one step slower than current,
    // in order to reference current to pass enemy forward.
    struct location *previous = NULL;
    // Create a counter in record the number of enemies have been removed.
    int counter = 0;

    // Loop thro linked list until NULL is reached.
    while (current != NULL) {
        // Check whether the enemy section is empty under current location.
        // If empty, current move on.
        // Otherwise, change the link to previous location, 
        // if current is castle, then previous is NULL.
        if (current->enemies != NULL) {
            // Create a new pointer to loop thro until NULL is reached.
            struct enemy *currentEnemy = current->enemies;
            struct enemy *previousEnemy = current->enemies;
            if (strcmp(current->name, "Castle") == 0) {
                // Check the number of enemies in the castle.
                while (currentEnemy != NULL) {
                    // Number of enemies pass thro castle.
                    counter++;
                    currentEnemy = currentEnemy->next;
                }
                // Then remove all these enemies from the map.
                current->enemies = NULL;
                
            } 
            // For stage 5, if tower with effect of ice has been detected.
            else if (current->power > 0 && current->uses > 0 && 
            current->effect == EFFECT_ICE) {
                // Determine the enemy who has HP less than current's power.
                while (currentEnemy != NULL) {
                    // If current enemy has hp less than tower's power,
                    // then it will be frozen under this tower.
                    // Hence no further action is required other than move pass.
                    if (currentEnemy->hp < current->power) {
                        // Move pass it.
                        previousEnemy = currentEnemy;
                        currentEnemy = currentEnemy->next;
                    } 
                    // If the first enemy under the tower has hp > power,
                    // who cannot limited to ice effect.
                    // It will advance to next tower as normal. 
                    else if (currentEnemy->hp >= current->power &&
                    currentEnemy == current->enemies)
                    {
                        current->enemies = currentEnemy->next;
                        currentEnemy->next = previous->enemies;
                        previous->enemies = currentEnemy;
                        currentEnemy = current->enemies;
                    }
                    // If enemies are not in the two categories above,
                    // then advance to next tower as normal.
                    else {
                        previousEnemy->next = currentEnemy->next;
                        currentEnemy->next = previous->enemies;
                        previous->enemies = currentEnemy;
                        currentEnemy = previousEnemy->next;
                    }
                }
            } 
            // Enemies will advance to next tower normally 
            // as no effect is applied.
            else {
                while (currentEnemy != NULL) {
                    current->enemies = currentEnemy->next;
                    currentEnemy->next = previous->enemies;
                    previous->enemies = currentEnemy;
                    currentEnemy = current->enemies;
                }
            }
        }
        // Move previous to the current position.
        previous = current;
        // Then move the current to next position in the linked list.
        current = current->next;
    }

    // Function for portal effect below, and reset the pointers.
    // Since effect portal only applied when the movement is finished,
    // hence the portal effect function is created after the advance function
    // is completed.
    current = realm->castle;
    while (current != NULL) {
        struct enemy *currentEnemy = current->enemies;
        if (current->power > 0 && current->uses > 0 && 
        current->effect == EFFECT_PORTAL)
        {
            // Move all the enemies under portal effect tower back to lair.
            while (currentEnemy != NULL) {
                current->enemies = currentEnemy->next;
                currentEnemy->next = realm->lair->enemies;
                realm->lair->enemies = currentEnemy;
                currentEnemy = current->enemies;
                // Convert the portal effect back to none effect,
                // after the portal effect has been applied once.
                current->effect = EFFECT_NONE;
            }
            
        }
        // This is sorting function, more detailed see function description.
        // which sorts enemies alphabetically under the same location.
        // As all the effects and re-arrangements are completed,
        // we should sort the enemies alphabetically to conclude the function.
        if (current->enemies != NULL) {
            sorting(current);
        }
        
        current = current->next;
    }
    return counter;
}



// Apply damage from the enemies at each tower to that tower.
// Go through each Enemy at that Tower, and reduce it's HP by the Tower's power.
// After the forward movements have been done to enemies,
// apply damage to enemies, and reduce use by one to tower. 
// This function take realm as input, the number of damaged enemies as outputs.
int apply_damage(Realm realm) {
    // Initiate a counter to record the number of enemies damaged this way.
    int counter = 0;
    // Create a pointer "current" to loop thro locations from castle till NULL.
    struct location *current = realm->castle;

    while (current != NULL) {
        // Proceed if current location is tower.
        // Tower is when it has both non-zero power and uses.
        if (current->uses != 0 && current->power != 0 && 
        current != realm->castle) {
            // Check the number of enemies in the location.
            // Create a new pointer to loop thro until NULL is reached.
            struct enemy *currentEnemy = current->enemies;
            
            // Apply damage to all enemies under the tower.
            while (currentEnemy != NULL) {
                // Apply damage to current enemy.
                currentEnemy->hp = (currentEnemy->hp) - current->power;
                // Reduce tower's use by one.
                current->uses--;
                // The number of damaged enemy increase by one.
                counter++;
                // Move on.
                currentEnemy = currentEnemy->next;
            }
            remove_enemy(current, currentEnemy);

        } 
        else if (current == realm->castle) { // When enemy is under castle.
            // Enemies can cause castle's defense to decrease.
            // Check the number of enemies in the castle.
            // Create a new pointer to loop thro until NULL is reached.
            struct enemy *currentEnemy = current->enemies;
            while (currentEnemy != NULL) {
                // Castle's remaining health.
                realm->castle->defense -= currentEnemy->hp;
                currentEnemy = currentEnemy->next;
            }

        }
        current = current->next;
    }
    
    return counter;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

/*
The function of "apply_buff" apply the specified buff 
to the relevant towers or enemies based on search term and buff type.
This funtion take realm, search term, buff type, and amount of buff as inputs.
The number of buff will be applied are the outputs of this function.
*/
int apply_buff(Realm realm, char *search_term, Buff buff, int amount){
    // Record number of buff has been applied.
    int counterForBuff = 0;
    // Loop through linked list, to determine amount of 
    // towers or enemies are matching the search terms.
    // Based on the effect type, different function can be achieved.
    // Create a pointer "current" to matching cases.
    struct location *current = realm->castle;
    while (current != NULL) {
        // Seperate tower and enemies into two different types.
        if (current->power != 0 && current->uses != 0 && 
        buff != BUFF_ENEMY_HP && 
        search_function_tower(current, search_term) == 1) { // Tower
            // Apply buff.
            if (buff == BUFF_TOWER_POWER) {
                // Increase each of their power by the specified amount.
                current->power += amount;
                // Return the number of towers you found this way.
                counterForBuff++;
            } else if (buff == BUFF_TOWER_USES) {
                // Increase each of their uses by the specified amount.
                current->uses += amount;
                counterForBuff++;
            }

        } else if (current->enemies != NULL) { // Enemies.
            // Create a pointer "currentEnemy" to matching cases.
            struct enemy *currentEnemy = current->enemies;
            // Loop thro each enemy under the location until NULL is reached.
            while (currentEnemy != NULL) {
                // Apply buffs to enemy.
                if (buff == BUFF_ENEMY_HP && 
                search_function_enemy(currentEnemy, search_term) == 1) { 
                    // Increase each of their HP by the specified amount. 
                    currentEnemy->hp += amount;
                    // Return the number of enemies you found this way.
                    counterForBuff++;
                }
                currentEnemy = currentEnemy->next;
            }
            // If debuff has been applied,
            // enemies' hp has decreased, then remove enemy.
            remove_enemy(current, currentEnemy);
        }
        current = current->next;
    }
    return counterForBuff;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

/*
Apply the effect described by effect_type to every tower matching search_term.
The function take realm, search term, and effect type as inputs,
the number of towers that match search term will be returned.
*/
int apply_effect(Realm realm, char *search_term, Effect effect) {
    // Record number of towers that have been matched.
    int counterForMatchedTower = 0;
    // Loop through linked list, to determine amount of 
    // towers are matching the search terms.
    // Based on the effect type, different function can be achieved.
    // Create a pointer "current" to matching cases.
    struct location *current = realm->castle;
    while (current != NULL) {
        // Locate the towers matching search term.
        if (current->power > 0 && current->uses > 0 &&
        search_function_tower(current, search_term)) {
            // Then determine different effect.
            if (effect == EFFECT_ICE) 
            {
                // If an Enemy would move from the Tower with this effect 
                // to the next Location, 
                // and that enemy has HP less than to the current tower's power, 
                // it stays at the current Tower. 

                // Assign effect to the tower.
                current->effect = EFFECT_ICE;
                counterForMatchedTower++;
            }
            else if (effect == EFFECT_PORTAL)
            {
                /*
                After all enemies have moved, 
                if there are enemies at portal towers, 
                they should all be moved back to the Lair. 
                This effect is removed from a tower after 
                it has finished moving enemies.
                */
                // Assign effect to the tower.
                current->effect = EFFECT_PORTAL;
                counterForMatchedTower++;
            }
        }
        current = current->next;
    }
    return counterForMatchedTower;
}


////////////////////////////////////////////////////////////////////////
//                       Self-Created Functions                       //
////////////////////////////////////////////////////////////////////////

/*
The function of "remove_enemy" removes the enemy who has hp not above zero.
The function takes current location (tower/land), and currentEnemy as inputs.
It will scan through every single enemies under the location,
and remove it if hp < 0 is detected (free node), then re-do the process,
until all enemies have hp > 0.
This function is void type, hence no output will be produced.
*/
static void remove_enemy(struct location *current, struct enemy *currentEnemy) {
    // Remove enemies.
    // Reset the currentEnemy, loop thro the enemies again,
    // in order to check any enemies'hp are below 0.
    currentEnemy = current->enemies;
    // Create a pointer "previousEnemy",
    // which is move one step slower than currentEnemy,
    // in order to link the previousEnemy and currentEnemy->next,
    // when currentEnemy is removed.
    struct enemy *previousEnemy = NULL;
    while (currentEnemy != NULL) {
        // Check whether hp is below 0.
        if (currentEnemy->hp <= 0) {
            // If this is the first enemy under the tower.
            if (current->enemies == currentEnemy) {
                current->enemies = currentEnemy->next;
                free(currentEnemy);
                // Reset currentEnemy back to head.
                currentEnemy = current->enemies;
            } else { // Else this is not the first enemy under.
                previousEnemy->next = currentEnemy->next;
                free(currentEnemy);
                // Reset.
                currentEnemy = current->enemies;
                previousEnemy = NULL;
            }
        } else { // hp > 0, move on.
            previousEnemy = currentEnemy;
            currentEnemy = currentEnemy->next;
        }
        
    }
}

/*
Search function for tower and enemy by looping through each elements,
and conduct required searches.
These search functions are implementing prefix search, not exact match.
which means the word can pass the test as long as 
the search term can match the word for the same length.
Both functions take current location (either tower or enemy), 
and required search term as inputs.
They will return 1 if matching, otherwise return 0.
These two functions are basically have the same content, but different input,
search_function_tower takes struct location type of current as input,
search_function_enemy takes struct enemy type of current as input.
*/
static int search_function_tower (struct location *current, char *search_term) {
    // Initiate a counter for counting each word in current.
    int counter = 0;
    // Counting each word for search term.
    int counterForRange = 0;
    // Prefix search:
    // Search will finished if looped thro search term.
    // Return 0 if any character is not matching,
    // return 1 only if all search terms are exactly matching.
    while (counterForRange < strlen(search_term)) {
        
        // If no [] is detected, match each character.
        if (search_term[counterForRange] != '[' ) { 
            if (search_term[counterForRange] == current->name[counter]) {
                // matched, move on to next character.
            } else {
                // Not matched, end the function.
                return 0;
            }
        } else if (search_term[counterForRange] == '[') {
            // Each character will have a unique matching number,
            // If it is still 1 at the end of the 
            int matching = 0;
            // Then we need to find the location of ].
            while (search_term[counterForRange] != ']') {
                // For single matching stype input. e.g.[abc]
                if (search_term[counterForRange] == current->name[counter]) {
                    // Then matched.
                    matching = 1;
                }
                // For range style input e.g.[a-z]
                else if (search_term[counterForRange] == '-') {
                    if (search_term[counterForRange - 1] <= 
                    current->name[counter]
                    && search_term[counterForRange + 1] >= 
                    current->name[counter]) {
                        // Matched
                        matching = 1;
                    } 
                }
                counterForRange++;
                
            }
            // If the programme didnt found corresponded characters,
            // at the end of ]
            // Which means no matched.
            if (matching != 1) {
                return 0;
            }
        }
        counter++;
        counterForRange++;
    }
   
    return 1;
}

// Search function for enemy.
// Return 1 if completely matched.
// Detailed description is above.
static int search_function_enemy (struct enemy *current, char *search_term) {
    // Initiate a counter for counting each word in current.
    int counter = 0;
    // Counting each word for search term.
    int counterForRange = 0;
    // Prefix search:
    // Search will finished if looped thro search term.
    // Return 0 if any character is not matching,
    // return 1 only if all search terms are exactly matching.
    while (counterForRange < strlen(search_term)) {
        
        // If no [] is detected, match each character.
        if (search_term[counterForRange] != '[' ) { 
            if (search_term[counterForRange] == current->name[counter]) {
                // matched, move on to next character.
            } else {
                // Not matched, end the function.
                return 0;
            }
        } else if (search_term[counterForRange] == '[') {
            // Each character will have a unique matching number,
            // If it is still 1 at the end of the 
            int matching = 0;
            // Then we need to find the location of ].
            while (search_term[counterForRange] != ']') {
                // For single matching stype input. e.g.[abc]
                if (search_term[counterForRange] == current->name[counter]) {
                    // Then matched.
                    matching = 1;
                }
                // For range style input e.g.[a-z]
                else if (search_term[counterForRange] == '-') {
                    if (search_term[counterForRange - 1] <= 
                    current->name[counter]
                    && search_term[counterForRange + 1] >= 
                    current->name[counter]) {
                        // Matched
                        matching = 1;
                    } 
                }
                counterForRange++;
                
            }
            // If the programme didnt found corresponded characters,
            // at the end of ]
            // Which means no matched.
            if (matching != 1) {
                return 0;
            }
        }
        counter++;
        counterForRange++;
    }
   
    return 1;
}


/*
The function "sorting" sorts all enemies alphabetically based on their names 
under the same location. This function is achieved similar to the
bubble sort technique, which compares two variables, then swap, move to the 
next position, and then repeat until all variables are in alphabetical order.
The function take struct location * type as input, and no output based on its 
void type.
*/
static void sorting(struct location *current) {
    struct enemy *previousEnemy = current->enemies;
    struct enemy *currentEnemy = current->enemies;
    struct enemy *nextEnemy = current->enemies->next;
    while (nextEnemy != NULL) {
        while (strcmp(currentEnemy->name, nextEnemy->name) > 0) {
            // Z > A.
            // First number
            if (currentEnemy == current->enemies) {
                currentEnemy->next = nextEnemy->next;
                nextEnemy->next = current->enemies;
                current->enemies = nextEnemy;
                // reset
                previousEnemy = current->enemies;
                currentEnemy = current->enemies;
                nextEnemy = current->enemies->next;
                
            }
            else {// Assuming in the middle of role.
                currentEnemy->next = nextEnemy->next;
                previousEnemy->next = nextEnemy;
                nextEnemy->next = currentEnemy;
                // reset
                previousEnemy = current->enemies;
                currentEnemy = current->enemies;
                nextEnemy = current->enemies->next;
            }
            
        }
        previousEnemy = currentEnemy;
        currentEnemy = nextEnemy;
        nextEnemy = nextEnemy->next;
    }

}




////////////////////////////////////////////////////////////////////////
//                    Provided print functions                        //
//         NOTE: YOU SHOULD NOT MODIFY THE FOLLOWING FUNCTIONS        //
////////////////////////////////////////////////////////////////////////

void print_tower(char *name, int power, int uses, int effect) {
    printf(" ^ %32s [pow: %3d | uses: %3d]", name, power, uses);
    if (effect == EFFECT_NONE) printf(" {%c}", EFFECT_NONE_CHAR);
    if (effect == EFFECT_PORTAL) printf(" {%c}", EFFECT_PORTAL_CHAR);
    if (effect == EFFECT_ICE) printf(" {%c}", EFFECT_ICE_CHAR);
    printf("\n");
}

void print_land(char *name) {
    printf(" ^ %32s [____________________]\n", name);
}

void print_castle(char *name, int defense) {
    printf(" ^ %32s [Castle Defenses: %3d]\n", name, defense);
}

void print_enemy(char *name, int cur_hp, int max_hp) {
    printf(" ^ %40s [hp: %d/%d]\n", name, cur_hp, max_hp);
}

////////////////////////////////////////////////////////////////////////
//               End of provided print functions                      //
////////////////////////////////////////////////////////////////////////




