#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck {
private:
    Card* cards;
    int n_cards;
    const int MAX_SIZE = 52;

public:
    // constructors
    Deck();

    // destructor
    ~Deck();

    // accessors (getters)
    Card* get_cards();
    int get_length();

    // mutators (setters)
    void set_cards(Card*);

    // helper functions
    void empty();
    void fill_deck();
    void shuffle();
    void display();

    bool add_card(Card);
    bool draw_card(Card&);
    
    Card top_card();
};

#endif
