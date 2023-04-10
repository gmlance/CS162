#include <iostream>
#include <math.h>
#include <stdlib.h>

#include "Game.h"

#include "Pit.h"
#include "Bats.h"
#include "Gold.h"
#include "Rope.h"
#include "Wumpus.h"

using namespace std;

// constructor
Game::Game(int board_size, bool bug) {
    // initialize values
    SIDE_LENGTH = board_size;
    DEBUG = bug;
    player = new Player(SIDE_LENGTH);

    // shuffle the random events
    int squared = pow(SIDE_LENGTH, 2);

    Event* events[squared];
    for (int i = 0; i < squared; i++) {
        events[i] = NULL;
    }

    // 1 Wumpus
    // 1 Gold
    // 2 Bats
    // 2 Pits
    // 1 Rope

    for (int e = 0; e < 7; e++) {
        // find the random index
        int index;
        do {
            index = rand() % squared;
        } while (events[index] != NULL);

        if (e < 1) {
            // wumpus
            events[index] = new Wumpus(player);
            wumpus_x = (index % SIDE_LENGTH);
            wumpus_y = (index / SIDE_LENGTH);
        } else if (e < 2) {
            // gold
            events[index] = new Gold(player);
        } else if (e < 4) {
            // bats
            events[index] = new Bats(player);
        } else if (e < 6) {
            // pits
            events[index] = new Pit(player);
        } else {
            // rope
            events[index] = new Rope(player);
            // set player at rope
            player->set_x(index % SIDE_LENGTH);
            player->set_y(index / SIDE_LENGTH);
            // index = (i * SIDE_LENGTH) + j;
        }
    }

    // x = (i * SIDE_LENGTH) + j

    // set up the board
    for (int i = 0; i < SIDE_LENGTH; i++){
        vector<Room> row;
        for (int j = 0; j < SIDE_LENGTH; j++) {
            // some Events are different (Wumpus, Gold, Bats, Pit)
            int index = (i * SIDE_LENGTH) + j;
            row.push_back(Room(events[index]));
        } 
        this->board.push_back(row);
    }
}

// +---+---+---+---+
// |   |   |   |   |
// | * | B | B | B |
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// | B | B | B | B |
// |   |   |   |   |
// +---+---+---+---+

void Game::print_board(){
    // +---+---+
    // |   |   |
    // | W |   |
    // |   |   |
    // +---+---+

    // make the decorative strings
    // +---+
    // |   |

    string line, space;
    for (int i = 0; i < SIDE_LENGTH; i++) {
        line += "+---";
        space += "|   ";
    }
    line += "+";
    space += "|";
    
    char letter = ' ';
    for (int i = 0; i < SIDE_LENGTH; i++) {
        // row
        cout << line << endl;
        cout << space << endl;
        for (int j = 0; j < SIDE_LENGTH; j++) {
            // room
            if (DEBUG) {
                Room room = board[i][j];
                letter = room.get_abbreviation();
            }
            if (player->get_x_pos() == j && player->get_y_pos() == i) {
                letter = '*';
            }
            cout << "| " << letter << " ";
            if (player->get_x_pos() == j && player->get_y_pos() == i) {
                letter = ' ';
            }
        }
        cout << "|" << endl;
        cout << space << endl;
    }
    cout << line << endl;

}

bool Game::game_over() {
    return player->get_is_dead() || player->get_has_won();
}

void Game::play_turn() {
    int x = player->get_x_pos();
    int y = player->get_y_pos();

    // assume the player will input
    player->set_inputtable(true);

    // display the board
    print_board();
    
    // is there an encounter?
    // board[y][x]
    board[y][x].encounter();

    // if the erncounter requires no input
    if (!player->get_inputtable()) {
        return;
    }

    // display percepts
    // find location of player and their neighboring tiles
    // 4 directions

    // North
    if (y != 0) {
        board[y - 1][x].percept();
    }
    // East
    if (x != SIDE_LENGTH - 1) {
        board[y][x + 1].percept();
    }
    // South
    if (y != SIDE_LENGTH - 1) {
        board[y + 1][x].percept();
    }
    // West
    if (x != 0) {
        board[y][x - 1].percept();
    }
    
    // take input (N, E, S, W, ' ')
    // validated to board dimensions
    char input;
    string str_input;
    cout << "moving > ";
    input = cin.get();
    cout << endl;

    // get char from a string
    // input = str_input.at(0);

    // case-insensitive
    input = toupper(input);

    // North
    if (input == 'W' && y != 0) {
       player->set_y(y - 1); 
    }
    // East
    else if (input == 'D' && x != SIDE_LENGTH - 1) {
        player->set_x(x + 1);
    }
    // South
    else if (input == 'S' && y != SIDE_LENGTH - 1) {
        player->set_y(y + 1); 
    }
    // West
    else if (input == 'A' && x != 0) {
        player->set_x(x - 1);
    }
    // Shoot an Arrow
    else if (input == ' ' && player->has_arrows()) {
        bool shot_arrow = false;
        cout << "arrow  > ";
        // last cin was ' '
        // ignore that one space
        cin.ignore(1);
        input = cin.get();
        cout << endl;

        // case-insensitive
        input = toupper(input);

        // North
        if (input == 'W') {
            shot_arrow = true;
            player->decrement_arrows();
            // y - 1, y - 2, y -3
            // y - 3 < wumpus_y < y - 1
            // wumpus_x == x
            if (wumpus_x == x && y - 3 <= wumpus_y && wumpus_y <= y - 1) {
                // kill the wumpus
                player->kill_wumpus();
            }
        }
        // East
        else if (input == 'D') {
            shot_arrow = true;
            player->decrement_arrows();
            if (wumpus_y == y && x + 3 >= wumpus_x && wumpus_x >= x + 1) {
                player->kill_wumpus();
            }
        }
        // South
        else if (input == 'S') {
            shot_arrow = true;
            player->decrement_arrows();
            if (wumpus_x == x && y + 3 >= wumpus_y && wumpus_y >= y + 1) {
                player->kill_wumpus();
            }
        }
        // West
        else if (input == 'A') {
            shot_arrow = true;
            player->decrement_arrows();
            if (wumpus_y == y && x - 3 <= wumpus_x && wumpus_x <= x - 1) {
                player->kill_wumpus();
            }
        }
        
        // wake up the Wumpus and move it
        if (shot_arrow && !player->get_wumpus_is_dead() && rand() % 4 != 0) {
            bool moved = false;
            do {
                int trial_x = rand() % SIDE_LENGTH;
                int trial_y = rand() % SIDE_LENGTH;

                if (board[trial_y][trial_x].get_abbreviation() == ' ') {
                    moved = true;
                    // board[wumpus_y][wumpus_x].swap_events(board[trial_y][trial_x]);
                    board[trial_y][trial_x].swap_events(board[wumpus_y][wumpus_x]);
                    wumpus_x = trial_x;
                    wumpus_y = trial_y;
                    cout << "x: " << trial_x << ", y: " << trial_y << endl;
                    cout << "The Wumpus has moved!" << endl;
                }
            } while (!moved);
        }

        cin.ignore(1);
    }
}
