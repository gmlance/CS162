#include <iostream>
#include <stdlib.h>
#include "Pit.h"

using namespace std;

// constructor
Pit::Pit(Player* play) {
    player = play;
    abbreviation = 'P';
}

void Pit::percept() {
    // print out the message
    cout << "You feel a breeze." << endl;
}

void Pit::encounter() {
    // cout << "PIT ENCOUTER" << endl;
    player->set_inputtable(false);
    player->kill();
    cout << "You fell into a pit!" << endl;
}

char Pit::get_abbreviation() {
    return abbreviation;
}
