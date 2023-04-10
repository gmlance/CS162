// https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
// https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

class Event {
protected:
    char abbreviation;
    Player* player;
public:
    virtual void percept() = 0;
    virtual void encounter() = 0;
    virtual char get_abbreviation() = 0;
};


#endif // EVENT_H
