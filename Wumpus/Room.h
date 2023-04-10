#ifndef ROOM_H
#define ROOM_H

#include "Event.h"

class Room {
private:
    Event* room_event;
public:
    Room();
    Room(Event* event_type);

    // getter
    Event* get_room_event();

    // setter
    void set_room_event(Event* new_event);

    // helper methods
    char get_abbreviation();
    void encounter();
    void percept();
    void swap_events(Room& room);
    
};

//     x,  y
// N:  0,  1
// E:  1,  0
// S:  0, -1
// W: -1,  0

#endif // ROOM_H
