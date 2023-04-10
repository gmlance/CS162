#include <iostream>
#include "Rope.h"

using namespace std;

// constructor
Rope::Rope(Player* play) {
    player = play;
    abbreviation = 'R';
}

void Rope::percept() {
}

void Rope::encounter() {
    cout << "ROPE ENCOUNTER" << endl << "Grab the gold and make it back here without the Wumpus eating you!" << endl << "Move with W, A, S, and D." << endl << "You can shoot an arrow into an adjacent room by pressing space," << endl << "and chosing a room with W, A, S, or D." << "If you hit the Wumpus you will kill it," << endl << "but if you miss it might move!" << endl;
    if (player->get_has_gold()) {
        cout << "You found the gold and made it back to the rope!" << endl << "You win! Play and try again." << endl;
        player->winner();
        player->set_inputtable(false);
    }
}

char Rope::get_abbreviation() {
    return abbreviation;
}
