#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
    vector<int> v;   //Our vector class
    std::vector<int> stdv; //Standard vector

    // Compare operation of our vector to std
    v.push_back(23);
    stdv.push_back(23);

    cout << "Our vector size: " << v.size() << endl;
    cout << "STL vector size: " << stdv.size() << endl;

    // copy constructor
    vector<int> v_copy(v);
    std::vector<int> stdv_copy(stdv);

    cout << "Our copied vector size: " << v_copy.size() << endl;
    cout << "STL copied vector size: " << stdv_copy.size() << endl;

    v_copy[0] = 12;
    // v = v_copy;
    v.resize(2);

    cout << v[0] << ' ' << v_copy[0] << endl;

    // int check = v.at(100);
    // cout << "Not a valid item: " << check << endl;

    // v == v_copy ???
    bool complete = true;
    for (int i = 0; i < v.size() && complete; i++ ) {
      if (v[i] != v_copy[i]){
        cout << "Vector not the same at index: " << i << endl;
        complete = false;
      }
    }

    if (complete) {
        cout << "Vectors are the same" << endl;
    }

    return 0;
}