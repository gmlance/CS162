#include "lab2.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
lab::student* create_db(int num){
   
   student *db = new student[num];
   for(int i = 0; i < num; i++) {
   student[num] = 1;
}
}

void lab::db_info(student arr,int num, fstream &inf){
	for(int i = 0; i < num; i++) {
   	inf >> arr[i].id;
  	inf >> arr[i].first;
   	inf >> arr[i].last;
	inf >> arr[i].major;
	}
}
