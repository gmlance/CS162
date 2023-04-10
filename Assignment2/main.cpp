#include <iostream>
#include "game.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Welcome to Crazy Eights!" << endl
         << "(type \"quit\" to exit the game)" << endl << endl;


    Game my_game;
    string input;
    do {
        my_game.reset_game();

        while (!my_game.game_over()) {
            bool game_playable = my_game.play_turn();
            if (!game_playable) {
                cout << "No one can play!" << endl;
                break;
            }
        }

        cout << endl << "Would you like to play again? (y/N)" << endl << "> ";
        cin >> input;

        for (char & c : input) {
            c = toupper(c);
        }

    } while (input == "Y" || input == "YES");
}
