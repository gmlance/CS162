#ifndef BATS_H
#define BATS_H

#include "Event.h"

class Bats : public Event {
public:
    // constructor
    Bats(Player* play);

    // prototype
    void percept();
    void encounter();
    char get_abbreviation();
};

#endif // BATS_H
