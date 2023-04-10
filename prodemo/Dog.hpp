#include "Pet.hpp"

class Dog : public Pet {
  private:
  string breed;

  public:
  Dog(){}
  Dog(string n, double w, string b) : Pet(n, w), breed(b) {}

  string get_breed() {
    return breed;
  }

  void set_breed(string b){
    breed = b;
  }
  string get_lifespan() {
    if(weight >= 100) {
      return "7 years";
    } else {
      return "13 years";
    }
  }
};