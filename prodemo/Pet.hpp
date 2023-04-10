#include <iostream>

using namespace std;

class Pet{
  
  protected:
  string name;
  double weight;

  public:
  Pet(){}
  Pet(string n, double w){
    name = n;
    weight = w;
  }
  string get_name(){
    return name;
  }
  double get_weight(){
    return weight;
  }
  void set_name(string n) {
    name = n;
  }
  void set_weight(double w){
    weight = w;
  }
  string get_lifespan(){
    return "unknown lifespan";
  }
};