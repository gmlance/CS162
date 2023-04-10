#include "hand.h"

#include <stdlib.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// constructors
Hand::Hand() {
    n_cards = 0;
    cards = new Card[MAX_SIZE];
}

// destructor
Hand::~Hand() {
    delete[] cards;
}

// accessors (getters)
Card* Hand::get_cards() {
    return cards;
}

int Hand::get_n_cards() {
    return n_cards;
}

// mutators (setters)
void Hand::set_cards(Card* c) {
    cards = c;
}

// helper functions
void Hand::display() {
    for (int i = 0; i < n_cards; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cards[i].display();
    }
    cout << endl;
}

bool Hand::add_card(Card card) {
    // early return (not so good path)
    if (n_cards >= MAX_SIZE) {
        return false;
    }

    // business as usual (good path)
    cards[n_cards] = card;
    n_cards++;
    return true;
}

bool Hand::draw_card(Card& card) {
    // early return (not so good path)
    if (n_cards <= 0) {
        return false;
    }

    // business as usual (good path)
    n_cards--;
    card = cards[n_cards];
    return true;
}

bool Hand::remove_card(int i) {
    if (n_cards <= 0 || i < 0 || n_cards <= i) {
        return false;
    }

    // i == 2
    // 0 1 2 3 4 . ; n_cards == 5
    // 0 1 3 4 . 4 ; n_cards == 4

    for (; i < n_cards; i++) {
        // current card is now equal to the next card
        cards[i] = cards[i + 1];
    }
    n_cards--;
    return true;
}
