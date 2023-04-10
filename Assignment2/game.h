#include "deck.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game {
private:
    Deck cards;
    Deck pile;
    Player players[2];
    int turn;

public:
    Game();

    // getters
    Deck& get_cards();
    Deck& get_pile();
    Player* get_players();

    // setters
    void set_cards(Deck);

    // helper
    bool deal(int);
    void reset_game();
    void display();
    bool play_turn();
    bool game_over();

};

#endif
