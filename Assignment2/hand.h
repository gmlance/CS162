#ifndef HAND_H
#define HAND_H

#include "card.h"

class Hand {
private:
    Card* cards;
    int n_cards;
    const int MAX_SIZE = 52;

public:
    // constructors
    Hand();

    // destructor
    ~Hand();

    // accessors (getters)
    Card* get_cards();
    int get_n_cards();

    // mutators (setters)
    void set_cards(Card*);

    // helper functions
    bool add_card(Card);
    bool draw_card(Card&);
    void display();
    bool remove_card(int);
};

#endif
