// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by Zheng Luo (z5206267@ad.unsw.edu.au)
// on July/2020
//
// Version 1.0.0 (2020-07-20): Assignment released.
// Version 1.0.1 (2020-07-21): Add return value to main.

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "realm.h"
#include "test_realm.h"
#include "capture.h"

////////////////////////////////////////////////////////////////////
//                        Function Protoypes                      //
////////////////////////////////////////////////////////////////////

// TODO: Add your own prototypes here, if necessary.

////////////////////////////////////////////////////////////////////
//                         Helper Functions                       //
////////////////////////////////////////////////////////////////////

// Find the string 'needle' in 'haystack'
int string_contains(char *haystack, char *needle) {
    return strstr(haystack, needle) != NULL;
}

// NOTE: You should not declare any structs from realm.c here.
// Declaring structs from realm.c in this function is against the
// rules of the assignment. 

// Main function: this function will not be used in testing, you do not
// need to change it.
// If you want to write your own tests, add them in `extra_tests`.
int main(int argc, char *argv[]) {
    printf("\n================== Castle Defense Tests ==================\n");

    test_add_location();
    test_print_realm();
    test_new_enemy();
    test_new_tower();
    test_apply_damage();
    extra_tests();

    return 0;
}

// NOTE: These tests are explained in `test_realm.h`

void test_add_location(void) {
    printf("Test whether this add_location follows the spec: ");

    // Test 1: Does add_location's return value count the Castle & Lair?

    Realm test_realm = new_realm();

    int num_locations = add_location(test_realm, "Location");
    if (num_locations != 3) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does add_location return the correct amount for lots of locations?
    // Test if 1024 locations will be added.
    Realm test_realm_test2 = new_realm();
    char string[1024];
    num_locations = 0;
    int counter = 0;
    while (counter < 1024) {
        // store difference names into string based on counter.
        sprintf(string, "Location%d", counter);
        // the name of location will be based on string.
        num_locations = add_location(test_realm_test2, string);
        counter++;
    }
    if (num_locations != 1026) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    // Test 3: Add your own test, and explain it below:
    // Test whether added location is located before lair.
    Realm test_realm_test3 = new_realm();
    char string3[1024];
    char expected_string[1024] = 
    " ^                           Castle [Castle Defenses: 100]\n\
 ^                        Location1 [____________________]\n\
 ^                        Location2 [____________________]\n\
 ^                             Lair [____________________]\n";
    // Two locations will be added in test 3,
    add_location(test_realm_test3, "Location1");
    add_location(test_realm_test3, "Location2");
    // the location2 must located before lair and after location1.
    // castle->location1->location2->lair
    CAPTURE(print_realm(test_realm_test3), string3, 1024);
    if (strcmp(string3, expected_string) != 0) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    

    printf(FOLLOWS_SPEC);
}

void test_print_realm(void) {
    printf("Test whether this print_realm follows the spec: ");

    // Test 1: Does print_realm show the Castle?

    Realm test_realm = new_realm();

    char print_text[10000];
    CAPTURE(print_realm(test_realm), print_text, 10000);

    if (!string_contains(print_text, "Castle")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does print_realm show the correct HP of the castle?

    Realm test2_realm = new_realm();

    char print_text_test2[10000];
    CAPTURE(print_realm(test2_realm), print_text_test2, 10000);

    if (!string_contains(print_text_test2, "Castle Defenses: 100")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 1: Does print_realm show the Lair?

    Realm test3_realm = new_realm();

    char print_text3[10000];
    CAPTURE(print_realm(test3_realm), print_text3, 10000);

    if (!string_contains(print_text, "Lair")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    printf(FOLLOWS_SPEC);
}

// Stage 2

void test_new_enemy(void) {
    printf("Test whether this new_enemy follows the spec: ");

    // Test 1: Does new_enemy work if you're adding to the Lair?
    Realm test_realm = new_realm();
    // Generate a tested enemy call "Roger" with 5hp at Lair.
    // This is following the spec, if return value is SUCCESS.
    if (new_enemy(test_realm, "Lair" , "Roger", 5) != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 2: Does new_enemy work if you're adding to the Castle?
    Realm test2_realm = new_realm();
    // Generate a tested enemy call "Roger" with 5hp at Castle.
    // This is following the spec, if return value is SUCCESS.
    if (new_enemy(test2_realm, "Castle" , "Roger", 5) != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    printf(FOLLOWS_SPEC);
}

void test_new_tower(void) {
    printf("Test whether this new_tower follows the spec: ");

    // Test 1: Does new_tower work if you're adding after another tower?
    Realm test_realm = new_realm();
    // Create first test tower right after the Castle with power and uses 5.
    new_tower(test_realm, "Castle", "TestTower1", 5, 5);
    // Then create second test tower after test tower 1.
    // If second tower does not return success, then print "NOT FOLLOW SPEC"
    if (new_tower(test_realm, "TestTower1", "TestTower2", 5, 5) != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return; 
    }
    
    // Test 2: Does new_tower work if it's power or uses are less than 1?
    Realm test2_realm = new_realm();
    // Create a tower with power 0, uses 0.
    // if it return success, then print "NOT FOLLOW SPEC".
    if (new_tower(test2_realm, "Castle", "TestTower", 0, 0) == SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return; 
    }

    // Test 3: Does new_tower work if there is no previous location
    // in the link as given in the function?
    Realm test3_realm = new_realm();
    // Create a tower after a non-existing location.
    // If it return success, then print "NOT FOLLOW SPEC".
    if (new_tower(test3_realm, "NON_EXISTING LOCATION",
        "TestTower", 5, 5) == SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return; 
    }

    printf(FOLLOWS_SPEC);
}

// Stage 3 (2 marks)

void test_apply_damage(void) {
    
    printf("Test whether this apply_damage follows the spec: ");

    // Test 1: Does apply_damage actually destroy enemies?
    Realm test_realm = new_realm();
    char string[1024];
    
    
    // Create a tower and a enemy under the tower,
    // with a hp lower than tower's power.
    new_tower(test_realm, "Castle", "TestTower", 5, 5);
    new_enemy(test_realm, "TestTower", "TestEnemy", 3);
    // Apply damage
    apply_damage(test_realm);
    CAPTURE(print_realm(test_realm), string, 1024);

    if (string_contains(string, "TestEnemy")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    

    // Test 2: Could apply damage function destory and damage multiple enemies
    // under the same location at the same time?
    Realm test2_realm = new_realm();
    char string2[1024];
    // Create a tower and multiple enemies under the tower, with different hp.
    new_tower(test2_realm, "Castle", "TestTower", 5, 5);
    new_enemy(test2_realm, "TestTower", "TestEnemy1", 3);
    new_enemy(test2_realm, "TestTower", "TestEnemy2", 10);
    new_enemy(test2_realm, "TestTower", "TestEnemy3", 3);
    // Apply damage
    apply_damage(test2_realm);
    CAPTURE(print_realm(test2_realm), string2, 1024);
    if (string_contains(string2, "TestEnemy1") || 
    string_contains(string2, "TestEnemy3")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    printf(FOLLOWS_SPEC);
}

// Stage 4 (1 marks)

void test_apply_buff(void) {
    printf("Test whether this apply_buff follows the spec: ");
    // Test 1: Does the buff has been successfully added?
    // Apply 5 power buff to TestTower, if the function is not returning 1
    // then print DOES NOT FOLLOW SPEC.
    Realm test_realm = new_realm();
    new_tower(test_realm, "Castle", "TestTower", 5, 5);
    if (apply_buff(test_realm, "TestTower", BUFF_TOWER_POWER, 5) != 1) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 2: Does the buff has been added correctly?
    // Apply 5 power buff to TestTower with 5 power originally, 
    // if it is not returning 10 as buff, then return DOES NOT FOLLOW SPEC.
    Realm test2_realm = new_realm();
    char string[1024];
    new_tower(test2_realm, "Castle", "TestTower", 5, 5);
    apply_buff(test2_realm, "TestTower", BUFF_TOWER_POWER, 5);
    CAPTURE(print_realm(test2_realm), string, 1024);
    if (!string_contains(string, "TestTower [pow:  10 | uses:   5] {n}")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    printf(FOLLOWS_SPEC);
}

// Extra Tests (not worth marks, but fun!)

void extra_tests(void) {
    // TODO: add extra tests, if you'd like to.
}
