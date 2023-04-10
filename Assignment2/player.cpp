#include "player.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Player::Player() {}

Player::Player(string n, bool c) {
    name = n;
    is_computer = c;
}

// getters
Hand& Player::get_hand() {
    return hand;
}

string Player::get_name() {
    return name;
}

bool Player::get_is_computer() {
    return is_computer;
}

// setters
void Player::set_name(string n) {
    name = n;
}

void Player::set_is_computer(bool c) {
    is_computer = c;
}

// helper
int Player::ask_suit() {
    int suit = -1;
    while (suit < 0 || 3 < suit) {
        cout << "What suit do you want? (0: Diamonds, 1: Hearts, 2: Clubs, 3: Spades)" << endl;
        cin >> suit;
    }
    return suit;
}

void Player::ask_and_set_name() {
    // string name;
    cout << "Please enter your name:" << endl;
    cin >> this->name;
    // this->name = name;
}