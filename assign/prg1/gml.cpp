//
//  funcdef.cpp
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

void Tab::create_db(int num){
    if(db != NULL) delete [] db;
    db = new student[num];
    size = num;
}

void Gml::grabfirstb(){
    ifstream inf("budgets.txt");
    if(!inf.is_open()){
        cout<<"Cannot open file"<<endl;
        exit(0);
    }
    int amnt;
    inf >> amnt;
    bnum = amnt;
    
}

void Gml::grabfirst(){
    ifstream inf("users.txt");
    if(!inf.is_open()){
        cout<<"Cannot open file"<<endl;
        exit(0);
    }
    int amnt;
    inf >> amnt;
    unum = amnt;

}

void Gml::create_usertab() {
    if(info != NULL) delete[] info;
    info = new user[unum];
    
}
void Gml::fill_usertab(ifstream &inf) {
    int num;
    inf >> num;
    
    for(int i = 0; i < unum; i++) {
        inf >> info[i].name;
        inf >> info[i].id;
        inf >> info[i].pwd;
    }
}

void Gml::create_tbtab(ifstream &inf) {
    int num;
    inf >> num;
    
    if(ledge != NULL) delete[] ledge;
    if(rec != NULL) delete[] rec;

    ledge = new budget[bnum];
    
    for (int i = 0; i < bnum; i++){
        inf >> ledge[i].id;
        inf >> ledge[i].balance;
        inf >> ledge[i].num_trans;
        
        
        rec = new transact*[bnum];
        ledge[i].t = rec[i];
        for (int j = 0; j < bnum; j++){
            rec[j] = new transact[ledge[i].num_trans];
            
            for(int h = 0; h < ledge[i].num_trans; h++) {
            inf >> rec[j][h].date;
            inf >> rec[j][h].amnt;
            inf >> rec[j][h].desc;
            inf >> rec[j][h].cat;
            }
            }

        }
    }
void Gml::fill_tbtab(ifstream &inf) {
    
    for (int i = 0; i < bnum; i++){
        inf >> ledge[i].id;
        inf >> ledge[i].balance;
        inf >> ledge[i].num_trans;
        
}
}
void Tab::db_info(ifstream &inf){
    for(int i = 0; i < size; i++) {
        inf >> db[i].id;
        inf >> db[i].first;
        inf >> db[i].last;
        inf >> db[i].major;
    }
}

void Gml::printinfo(int u) {
    cout << ledge[u].id<<" ";
    cout << ledge[u].balance <<" ";
    cout << ledge[u].num_trans<<" ";
    cout << endl;
    
    for(int i = 0; i < ledge[u].num_trans; i++) {
        for(int j = 0; j < 3; j++) {
            cout << rec[i][j].amnt << " ";
            cout << rec[i][j].date << " ";
            cout << rec[i][j].desc << " ";
            cout << rec[i][j].cat << " ";
        }
        cout << endl;
    }
}

void Tab::print_info(){
    for(int i = 0; i < size; i++) {
        cout << db[i].id<<" ";
        cout << db[i].first<<" ";
        cout << db[i].last<<" ";
        cout << db[i].major<<endl;
    }
}
