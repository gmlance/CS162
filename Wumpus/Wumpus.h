#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"

class Wumpus : public Event {
public:
    // constructor
    Wumpus(Player* play);

    // prototype
    void percept();
    void encounter();
    char get_abbreviation();
};

#endif // WUMPUS_H
