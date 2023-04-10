#ifndef lab2_h
#define lab2_h

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

struct student{
   int id;
   std::string first;
   std::string last;
   std::string major;
};
class lab{
student * create_db(int);

void db_info(student *, int,std::ifstream &);

void delete_info(student **, int);
};
#endif
