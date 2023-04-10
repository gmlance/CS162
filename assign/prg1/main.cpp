//
//  main.cpp
//  Lab 2
//
//  Created by Grant on 1/16/20.
//  Copyright © 2020 Grant Lance. All rights reserved.
//

#include "gml.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    Tab test;
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
    
    Gml assign;
    
    ifstream use("users.txt");
    if(!use.is_open()){
        cout<<"Cannot open file"<<endl;
        return 0;
    }
    ifstream bud("budgets.txt");
    if(!bud.is_open()){
        cout<<"Cannot open file"<<endl;
        return 0;
    }
    assign.grabfirst();
    assign.grabfirstb();
    assign.create_usertab();
    assign.create_tbtab(bud);
    assign.fill_usertab(use);
    assign.printinfo(0);
    cout << "1" << endl;
    
}

