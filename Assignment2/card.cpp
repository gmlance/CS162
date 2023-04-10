#include "card.h"

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

// constructors
Card::Card() {}

// Card::Card(string s, int r) : suit(s), rank(r) {}
Card::Card(int s, int r) {
    suit = s;
    rank = r;
}

// accessors (getters)
int Card::get_suit() {
    return suit;
}

int Card::get_rank() {
    return rank;
}

// mutators (setters)
void Card::set_suit(int s) {
    suit = s;
}

void Card::set_rank(int r) {
    rank = r;
}

string RANKS[]{"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
string SUITS[]{"D", "H", "C", "S"};


// helper functions
string Card::to_str() {
    return RANKS[rank] + SUITS[suit];
}

void Card::display() {
    cout << to_str();
}

bool Card::is_playable(Card other) {
    return rank == other.get_rank() || suit == other.get_suit();
}
