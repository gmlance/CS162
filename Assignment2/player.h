#include "hand.h"
#include <iostream>

using std::string;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    Hand hand;
    string name;
    bool is_computer;

public:
    Player();
    Player(string, bool);

    // getters
    Hand& get_hand();
    string get_name();
    bool get_is_computer();

    // setters
    // void set_hand(Hand);
    void set_name(string);
    void set_is_computer(bool);

    // helper
    int ask_suit();
    void ask_and_set_name();

};

#endif
