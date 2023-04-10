//
//  funcdef.hpp
//  Lab 2
//
//  Created by Grant on 1/16/20.
//  Copyright © 2020 Grant Lance. All rights reserved.
//

#ifndef gml_hpp
#define gml_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


struct user {
    std::string name;
    int id;
    std::string pwd;
};

struct transact {
    float amnt;
    std::string date;
    std::string cat;
    std::string desc;
};

struct budget {
    int id;
    float balance;
    int num_trans;
    transact *t;
};

struct student{
    int id;
    std::string first;
    std::string last;
    std::string major;
};

class Tab{
private:
    student* db;
    int size;
public:
    Tab(){
        db = NULL;
        size = 0;
    };
    
    int get_size(){return size;};
    void set_size(int s){size = s;};
    
    void create_db(int);
    
    void db_info(std::ifstream &);
    
    void print_info();
    
    ~Tab(){
        delete[] db;
    }
};
class Gml{
private:
    int id;
    int unum;
    int tnum;
    int bnum;
    
    std::string pwd;
    
    user* info;
    transact** rec;
    budget* ledge;
    
public:
    Gml(){
        id = 0;
        unum = 0;
        tnum = 0;
        bnum = 0;
        pwd = " ";
        info = NULL;
        rec = NULL;
        ledge = NULL;
    };
    
    void create_usertab();
    void fill_usertab(std::ifstream &);
    void print_usertab();
    void create_tbtab(std::ifstream &);
    void fill_tbtab(std::ifstream &);
    void print_tbtab();
    void grabfirst();
    void grabfirstb();
    void printinfo(int);

};
#endif /* funcdef_hpp */
