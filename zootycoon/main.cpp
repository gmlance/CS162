#include <iostream>
#include "zoo.h"

using namespace std;

int main() {
    cout << "Welcome to Zoo Tycoon!" << endl
         << "(type \"quit\" to exit the game)" << endl;

    Zoo* my_zoo;
    string input;
    do {
        cout << endl << endl;

        // default Zoo at start of each game
        my_zoo = new Zoo();
        while (!my_zoo->game_over()) {
            my_zoo->play_turn();
        }
        cout << "Game Over!" << endl << endl;

        cout << endl << "Would you like to play again? (y/N)" << endl << "> ";
        cin >> input;

        for (char & c : input) {
            c = toupper(c);
        }

    } while (input == "Y" || input == "YES");

    delete my_zoo;
}
