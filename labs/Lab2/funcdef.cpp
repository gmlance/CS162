//
//  funcdef.cpp
//  Lab 2
//
//  Created by Grant on 1/16/20.
//  Copyright © 2020 Grant Lance. All rights reserved.
//

#include "funcdef.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void Lab::create_db(int num){
    if(db != NULL) delete [] db;
    db = new student[num];
    size = num;
}

void Lab::db_info(ifstream &inf){
    for(int i = 0; i < size; i++) {
        inf >> db[i].id;
        inf >> db[i].first;
        inf >> db[i].last;
        inf >> db[i].major;
    }
}

void Lab::print_info(){
    for(int i = 0; i < size; i++) {
        cout << db[i].id<<" ";
        cout << db[i].first<<" ";
        cout << db[i].last<<" ";
        cout << db[i].major<<endl;
    }
}
