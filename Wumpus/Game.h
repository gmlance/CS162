#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Room.h"
#include "Player.h"

using namespace std;

class Game {
private:
    // parameters from shell
    int SIDE_LENGTH;
    bool DEBUG;

    // board is a collection of Rooms
    vector<vector<Room> > board;

    // player
    Player* player;

    // wumpus
    int wumpus_x, wumpus_y;

public:
    // constructor
    Game(int side_len, bool bug);

    // helper methods
    void print_board();
    bool game_over();
    void play_turn();
};

#endif // GAME_H
