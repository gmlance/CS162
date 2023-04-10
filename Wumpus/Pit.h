#ifndef PIT_H
#define PIT_H

#include "Event.h"

class Pit : public Event {
public:
    // constructor
    Pit(Player* play);

    // prototype
    void percept();
    void encounter();
    char get_abbreviation();
};

#endif // PIT_H
