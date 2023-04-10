#include "bear.h"

// animal_price, revenue, food_multiplier, babies, age
Bear::Bear() : Animal(6000, 600, 3, 2, 0) {}

Bear::Bear(int age) : Animal(6000, 600, 3, 2, age) {}
