#include <iostream>
#include "Player.h"

using namespace std;

// constructors
Player::Player(int length) {
    SIDE_LENGTH = length;
    num_arrows = 3;
    has_gold = false;
    has_won = false;
    is_dead = false;
    wumpus_is_dead = false;
    x_pos = 0;
    y_pos = 0;
    inputtable = true;
}

// getters
bool Player::get_has_gold() {
    return has_gold;
}

bool Player::get_has_won() {
    return has_won;
}

bool Player::get_is_dead() {
    return is_dead;
}

bool Player::get_wumpus_is_dead() {
    return wumpus_is_dead;
}

int Player::get_x_pos() {
    return x_pos;
}

int Player::get_y_pos() {
    return y_pos;
}

bool Player::get_inputtable() {
    return inputtable;
}

// setters
void Player::set_x(int x) {
    x_pos = x % SIDE_LENGTH;
}

void Player::set_y(int y) {
    y_pos = y % SIDE_LENGTH;
}

void Player::set_inputtable(bool input) {
    inputtable = input;
}

// helper methods
bool Player::has_arrows() {
    bool check = num_arrows > 0;
    if (!check) {
        cout << "You don't have any arrows left." << endl;
    }
    return check;
}

void Player::decrement_arrows() {
    num_arrows--;
}

// if (CONDITION) {
//     return true;
// } else {
//     return false;
// }

// return CONDITION;

void Player::gain_gold() {
    has_gold = true;
}

void Player::winner() {
    has_won = true;
}

void Player::kill() {
    is_dead = true;
}

void Player::kill_wumpus() {
    if (!wumpus_is_dead) {
        cout << "Your arrow killed the Wumpus!" << endl;
        wumpus_is_dead = true;
    }
}
