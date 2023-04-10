#include <iostream>
#include <stdlib.h>
#include "Gold.h"

using namespace std;

// constructor
Gold::Gold(Player* play) {
    player = play;
    abbreviation = 'G';
}

void Gold::percept() {
    // print out the message
    cout << "You see a glimmer nearby." << endl;
}

void Gold::encounter() {
    // know about the player object
    // know at least the side length of the board
    cout << "GOLD ENCOUNTER" << endl << "You grab the gold. Nothing else happens." << endl << "Now make it back to the rope!" << endl;
    player->gain_gold();
}

char Gold::get_abbreviation() {
    return abbreviation;
}
