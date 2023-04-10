
#include "Dog.hpp"


int main() {

double weight;
int x;
string name, breed;

Pet somepet;

cout<<"Give the pet a name: ";
cin >> name;
cout<<"How much does the pet weigh?";
cin >> weight;

somepet.set_name(name);
somepet.set_weight(weight);

cout << somepet.get_lifespan() << endl;

cout << "how many dogs?" << endl << ">";
cin >> x;

Dog *poodles = new Dog[x];
for(int i=0; i<x; i++) {
  cout << "give the dog a name: ";
  cin >> name;
  cout << "how much doe the dog weigh: ";
  cin >> weight;
  cout << "what breed of dog?: ";
  cin >> breed;
  poodles[i].set_breed(breed);
  poodles[i].set_name(name);
  poodles[i].set_weight(weight);
}

for(int i = 0; i < x; i++) {
  cout << poodles[i].get_lifespan() << endl;
}

delete [] poodles;


return 0;

}