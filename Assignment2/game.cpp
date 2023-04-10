#include <iostream>
#include "game.h"

using std::cout;
using std::cin;
using std::endl;

Game::Game() {}

// getters
Deck& Game::get_cards() {
    return cards;
}

Deck& Game::get_pile() {
    return pile;
}

Player* Game::get_players() {
    return players;
}

// setters
// void Game::set_cards(Deck c) {
//     cards = c;
// }

// helper
bool Game::deal(int turn) {
    Card my_card;
    if (cards.draw_card(my_card)) {
        // successfully drew a card
        players[turn].get_hand().add_card(my_card);
        return true;
    }
    return false;
}

void Game::reset_game() {
    // initialize turn as 0
    turn = 0;
    // reset pile
    pile.empty();
    // fill, shuffle deck (cards)
    cards.fill_deck();
    cards.shuffle();
    // set variables for players
    // user
    players[0].ask_and_set_name();
    players[0].set_is_computer(false);
    // computer
    players[1].set_name("Computer");
    players[1].set_is_computer(true);
    // deal 7 cards to each player
    for (int i = 0; i < 7; i++) {
        deal(0);
        deal(1);
    }
    // put one card on the pile
    Card my_card;
    cards.draw_card(my_card);
    pile.add_card(my_card);
}

void Game::display() {
    cout << endl << players[0].get_name() << "'s Hand:" << endl;
    players[0].get_hand().display();
    cout << endl;

    // for debugging
    // cout << players[1].get_name() << "'s Hand:" << endl;
    // players[1].get_hand().display();
    // cout << endl;

    cout << "Top of pile:" << endl;
    pile.top_card().display();
    cout << endl << endl;
}

bool Game::play_turn() {
    // grab the hand of the player and the top card in the pile
    Hand& my_hand = players[turn].get_hand();
    Card top_card = pile.top_card();
    bool played = false;
    bool game_playable = true;

    if (players[turn].get_is_computer()) {
        // computer
        // display();
        
        for (int i = 0; !played && i < my_hand.get_n_cards(); i++) {
            Card my_card = my_hand.get_cards()[i];
            // check to see if I can play my_card on top_card
            if (top_card.is_playable(my_card) || my_card.get_rank() == 8) {
                // can play, so remove card from hand
                my_hand.remove_card(i);
                // add this card to the pile
                pile.add_card(my_card);
                // designate that we've played
                played = true;
            }
        }
        // deal if we didn't play a card
        if (!played) {
            game_playable = deal(turn);
        }
    } else {
        // user
        display();
        string input;

        // the user has not put down a card or drawn a card
        while (!played) {
            cout << "What card to play, or \"draw\" a new one?" << endl << "> ";
            cin >> input;

            // convert input to uppercase
            for (char & c : input) {
                c = toupper(c);
            }

            if (input == "DRAW") {
                game_playable = deal(turn);
                played = true;
            } else if (input == "QUIT") {
                cout << endl << "Exiting game..." << endl;
                exit(0);
            }

            for (int i = 0; !played && i < my_hand.get_n_cards(); i++) {
                Card my_card = my_hand.get_cards()[i];

                // input == "8C"
                if (my_card.to_str() == input) {

                    // check to see if I can play my_card on top_card
                    if (top_card.is_playable(my_card) || my_card.get_rank() == 8) {
                        if (my_card.get_rank() == 8) {
                            my_card.set_suit(players[turn].ask_suit());
                        }
                        my_hand.remove_card(i);
                        pile.add_card(my_card);
                        played = true;
                    } else {
                        cout << "This card is not playable on the pile." << endl;
                    }
                }
            }

        }  // end user-play loop


    }
    // switch turn
    turn = 1 - turn;
    return game_playable;
}

bool Game::game_over() {
    if (players[0].get_hand().get_n_cards() <= 0) {
        cout << players[0].get_name() << " has won!" << endl;
        return true;
    } else if (players[1].get_hand().get_n_cards() <= 0) {
        cout << players[1].get_name() << " has won!" << endl;
        return true;
    }
    // return cards.get_length() <= 0;
    return false;
}