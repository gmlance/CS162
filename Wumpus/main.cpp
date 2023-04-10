#include <iostream>
#include <string.h>
#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
    // check for command-line arguments
    if (argc != 3) {
        cout << "Invalid number of arguments to main." << endl
             << "Format is: ./main [side length] [debug]" << endl;
        // non-zero exit
        return 1;
    }

    // side length
    const int SIDE_LENGTH = stoi(argv[1]);

    // check for side length smaller than 4
    if (SIDE_LENGTH < 4) {
      cout << "min cave size is 4x4" << endl << "exiting" << endl;
      return 2;
    }

    // debug
    string debug_in(argv[2]);
    bool DEBUG;
    if (debug_in == "true") {
        DEBUG = true;
    } else if (debug_in == "false") {
        DEBUG = false;
    } else {
        cout << "invalid case for debug argument" << endl << "exiting" << endl;
        return 3;
    }

    // play the game
    Game my_game(5, false);

    while (!my_game.game_over()) {
        my_game.play_turn();
    }

    return 0; 
} 
