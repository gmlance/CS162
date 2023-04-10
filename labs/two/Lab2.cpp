#include "lab2.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

int main() {
   using namespace std;
   ifstream inf("inputs.txt");
   int num;
   int* ptr = &num;
   inf >> num;
   create_db(num);
   db_info(db, num, &inf);
}
