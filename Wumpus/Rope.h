#ifndef ROPE_H
#define ROPE_H

#include "Event.h"

class Rope : public Event {
public:
    // constructor
    Rope(Player* play);

    // prototype
    void percept();
    void encounter();
    char get_abbreviation();
};

#endif // ROPE_H
