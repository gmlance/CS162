#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    // what do we need to know about the player?
    int num_arrows;
    bool has_gold;
    bool has_won;
    bool is_dead;
    bool wumpus_is_dead;
    int x_pos, y_pos;
    int SIDE_LENGTH;
    bool inputtable;

public:
    // constructors
    Player(int length);

    // getters
    bool get_has_gold();
    bool get_has_won();
    bool get_is_dead();
    bool get_wumpus_is_dead();
    int get_x_pos();
    int get_y_pos();
    bool get_inputtable();

    // setters
    void set_x(int x);
    void set_y(int y);
    void set_inputtable(bool input);

    // helper methods
    void decrement_arrows();
    bool has_arrows();
    void gain_gold();
    void winner();
    void kill();
    void kill_wumpus();
};

#endif