#include <string>

using std::string;

#ifndef CARD_H
#define CARD_H

class Card {
public:
    // constructors
    Card();
    Card(int, int);

    // accessors (getters)
    int get_suit();
    int get_rank();

    // mutators (setters)
    void set_suit(int);
    void set_rank(int);

    // helper functions
    string to_str();
    void display();
    bool is_playable(Card);

private:
    // attributes
    int suit;
    int rank;
};

#endif  // CARD_H
