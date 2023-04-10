#include <iostream>
#include <stdlib.h>
#include "Bats.h"

using namespace std;

// constructor
Bats::Bats(Player* play) {
    player = play;
    abbreviation = 'B';
}

void Bats::percept() {
    // print out the message
    cout << "You hear wings flapping." << endl;
}

void Bats::encounter() {
    // know about the player object
    // know at least the side length of the board
    cout << "BAT ENCOUTER" << endl << "The room is filled with oversized bats!" << endl << "They carry you into a random room." << endl;
    player->set_x(rand());
    player->set_y(rand());
    player->set_inputtable(false);
}

char Bats::get_abbreviation() {
    return abbreviation;
}
