#ifndef ANIMAL_H
#define ANIMAL_H

// https://beginnersbook.com/2017/09/cpp-enumeration/
enum AgeCode {
    BABY, ADOLESCENT, ADULT
};

class Animal {
public:
    // protected data members
    double animal_price, revenue;
    int babies, age_months, food_multiplier; 
    bool is_sick;

public:
    // public methods

    // constructors
    Animal();
    // constructor for differences between animals
    Animal(double animal_price, double revenue, int food_multiplier, int babies, int age);

    // getters
    double get_food_multiplier();
    double get_animal_price();
    double get_revenue();
    bool get_is_sick();

    // setters
    // void set_age_months();
    void set_is_sick(bool);

    // helper functions
    // add one month to the age
    void increment_age();
    // determine animal between 0, 6, 48 months old
    AgeCode determine_age_code();
    // babies get double income
    double compute_revenue();
};

#endif  // ANIMAL_H
