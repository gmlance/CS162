#ifndef GOLD_H
#define GOLD_H

#include "Event.h"

class Gold : public Event {
public:
    // constructor
    Gold(Player* play);

    // prototype
    void percept();
    void encounter();
    char get_abbreviation();
};

#endif // GOLD_H
