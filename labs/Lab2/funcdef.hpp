//
//  funcdef.hpp
//  Lab 2
//
//  Created by Grant on 1/16/20.
//  Copyright © 2020 Grant Lance. All rights reserved.
//

#ifndef funcdef_hpp
#define funcdef_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct student{
    int id;
    std::string first;
    std::string last;
    std::string major;
};

class Lab{
private:
    student* db;
    int size;
public:
    Lab(){
        db = NULL;
        size = 0;
    };
    
    int get_size(){return size;};
    void set_size(int s){size = s;};
    
    void create_db(int);
    
    void db_info(ifstream &);
    
    void print_info();
    
    ~Lab(){
        delete[] db;
    }
};
#endif /* funcdef_hpp */
