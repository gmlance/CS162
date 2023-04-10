#ifndef ZOO_H
#define ZOO_H

#include "sealion.h"
#include "bear.h"
#include "tiger.h"

class Zoo {
private:
    // private data members
    double balance, feed_price;
    int month;
    int n_sealions, n_bears, n_tigers;
    bool user_quit;

    // dynamically allocated exhibits
    Sealion* sealion_exhibit;
    Bear* bear_exhibit;
    Tiger* tiger_exhibit;

public:
    // public methods
    // constructor
    Zoo();

    // destructor
    ~Zoo();

    // helper functions
    bool game_over();
    void play_turn();
    void display_ages();

    void age_game();
    void special_event();
    void collect_revenue();
    void add_animals();
    void buy_animals();
    void feed_animals();
};

#endif  // ZOO_H
