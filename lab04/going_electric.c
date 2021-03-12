// Solution to Going Electric
// Tom Kunc (t.kunc@unsw.edu.au) - 2020-06-20
// Commented and reviewed by Zheng Luo (z5206267@ad.unsw.edu.au) on 8/Aug/2020.
// The solution don't assume the existence of car,
// it will continously add the fuel, but no consumption in fuel.
// then search for the next fuel station, based on the current fuel,
// and record the amount of stops eventually.


#include <stdio.h>
#include <stdbool.h>

#define MAX_STATIONS 10000

// Search for future fuel stations based on the current fuel in the tank.
// The function will return ture if we can reach next fuel station by 
// the amount of fuel left in the tank. 
// Otherwise return false.
// This function take amount of fuel left in the tank as first input,
// and the map as second input.
int contains_nonzero(int size, int array[size]) {
    int i = 0;
    while (i < size) {
        if (array[i] > 0) {
            return true;
        }
        i++;
    }
    return false;
}

// This function searches the location of fuel station,
// which has the most amount of fuel, within our driving range.
// This function take amount of fuel left in the tank as first input,
// and the map as second input. 
// Return the position of best fuel station within range.
int find_max_index(int size, int array[size]) {
    int max_index = 0;

    int i = 0;
    while (i < size) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
        i++;
    }

    return max_index;

}

int main(void) {
    // Create a 1 dimentional array map.
    int stations[MAX_STATIONS] = {0};
    // Store each input number into map, 
    // note: 0 is also station but no fuel.
    int num_stations = 0;
    while (scanf("%d", &stations[num_stations++]) == 1);

    int num_stops = 0;
    // The amount of fuel left in the tank.
    int fuel = 1;

    // The first condition: If I could reach next station by current fuel.
    // Second condition: I need to stop to charge based on my current fuel.
    while (contains_nonzero(fuel, stations) && fuel < num_stations - 1) {
        int max_index = find_max_index(fuel, stations);
        // Add fuel.
        fuel += stations[max_index];
        // Empty the fuel station.
        stations[max_index] = 0;
        // Increase number of stop.
        num_stops++;
    }

    if (fuel >= num_stations - 1) {
        printf("%d\n", num_stops);
    } else {
        printf("%d\n", 0);
    }
    return 0;
}