#include <iostream>
#include <stdlib.h>
#include "Wumpus.h"

using namespace std;

// constructor
Wumpus::Wumpus(Player* play) {
    player = play;
    abbreviation = 'W';
}

void Wumpus::percept() {
    // print out the message
    cout << "You smell a terrible stench." << endl;
}

void Wumpus::encounter() {
    // cout << "WUMPUS ENCOUTER" << endl;
    if (!player->get_wumpus_is_dead()) {
        player->set_inputtable(false);
        player->kill();
        cout << "The Wumpus has eaten you!" << endl << "Play the game and try again!" << endl;
    }
}

char Wumpus::get_abbreviation() {
    return abbreviation;
}
