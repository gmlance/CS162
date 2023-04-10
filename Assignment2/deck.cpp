#include "deck.h"

#include <stdlib.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// constructors
Deck::Deck() {
    n_cards = 0;
    cards = new Card[MAX_SIZE];
}

// destructor
Deck::~Deck() {
    delete[] cards;
}

// accessors (getters)
Card* Deck::get_cards() {
    return cards;
}

int Deck::get_length() {
    return n_cards;
}

// mutators (setters)
void Deck::set_cards(Card* c) {
    cards = c;
}

// helper functions
void Deck::empty() {
    n_cards = 0;
}

void Deck::fill_deck() {
    int index = 0;
    n_cards = MAX_SIZE;
    // need all combinations of suit and rank
    // loop through each suit (range-based)
    for (int suit = 0; suit < 4; suit++) {
        // loop through each rank
        for (int rank = 0; rank < 13; rank++ ) {
            cards[index] = Card(suit, rank);
            index++;
        }
    }
}

void swap(Card& c1, Card& c2) {
    // does this actually copy?
    Card temp = c1;
    c1 = c2;
    c2 = temp;
}

void Deck::shuffle() {
    // * cursor
    // . random selection
    // swap the two

    // 1 2 3 4
    // *   .
    // 3 2 1 4
    //   *   .
    // 3 4 1 2
    //     * .
    // 3 4 2 1
    
    for (int i = 0; i < n_cards; i++) {
        int cards_remain = n_cards - i;
        int j = i + (rand() % cards_remain);
        // cout << i << ' ' << j << endl;
        swap(cards[i], cards[j]);
    }
}

void Deck::display() {
    for (int i = 0; i < n_cards; i++) {
        cards[i].display();
    }
}

bool Deck::add_card(Card card) {
    // early return (not so good path)
    if (n_cards >= MAX_SIZE) {
        return false;
    }

    // business as usual (good path)
    cards[n_cards] = card;
    n_cards++;
    return true;
}

bool Deck::draw_card(Card& card) {
    // early return (not so good path)
    if (n_cards <= 0) {
        return false;
    }

    // business as usual (good path)
    n_cards--;
    card = cards[n_cards];
    return true;
}

Card Deck::top_card() {
    if (n_cards > 0) {
        return cards[n_cards - 1];
    }
    return Card();
}
