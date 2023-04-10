//
//  main.cpp
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

int main() {
    Lab test;
    ifstream inf("inputs.txt");
    if(!inf.is_open()){
        cout<<"Cannot open file"<<endl;
        return 0;
    }
    int num;
    //int* ptr = &num;
    inf >> num;
    test.create_db(num);
    test.db_info(inf);
    test.print_info();
}

