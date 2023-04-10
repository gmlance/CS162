#include <iostream>
#include "Room.h"

using namespace std;

// constructor
Room::Room() {
    room_event = NULL;
}

Room::Room(Event* event_type) {
    room_event = event_type;
}

// getters
Event* Room::get_room_event() {
    cout << "GETTING" << endl;
    if (room_event != NULL) {
        cout << room_event->get_abbreviation() << endl;
    }
    return room_event;
}

// setters
void Room::set_room_event(Event* new_event) {
    cout << "SETTING" << endl;
    if (new_event != NULL) {
        cout << new_event->get_abbreviation() << endl;
    }
    room_event = new_event;
    if (room_event != NULL) {
        cout << room_event->get_abbreviation() << endl;
    }
}

// helper methods
char Room::get_abbreviation() {
    if (room_event == NULL) {
        return ' ';
    }
    return room_event->get_abbreviation();
}

void Room::percept() {
    if (room_event == NULL) {
        return;
    }
    room_event->percept();
}

void Room::encounter() {
    if (room_event == NULL) {
        return;
    }
    room_event->encounter();
}

void Room::swap_events(Room& room) {
    Event* temp = room_event;
    room_event = room.get_room_event();
    room.set_room_event(temp);
}
