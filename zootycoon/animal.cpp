#include "animal.h"

// constructor
Animal::Animal(double price, double income, int multiplier, int offspring, int age) : animal_price(price), revenue(income), food_multiplier(multiplier), babies(offspring), age_months(age) {}

// getters
double Animal::get_food_multiplier() {
    return food_multiplier;
}

double Animal::get_animal_price() {
    return animal_price;
}

double Animal::get_revenue() {
    return revenue;
}

bool Animal::get_is_sick() {
    return is_sick;
}

// setters
void Animal::set_is_sick(bool sick) {
    is_sick = sick;
}

// helper_functions
void Animal::increment_age() {
    age_months++;
}

AgeCode Animal::determine_age_code() {
    if (age_months < 6) {
        // baby case
        return BABY;
    } else if (age_months < 48) {
        // adolescent case
        return ADOLESCENT;
    } else {
        // adult case
        return ADULT;
    }    
}

double Animal::compute_revenue() {
    if (determine_age_code() == BABY) {
        return revenue * 2.0;
    }
    return revenue;
}
