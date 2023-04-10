/*
 * Lab 1
 * Grant Lance
 * 1/8/20
 * Structs and Arrays
 * */

#include  <iostream>
#include <string>
#include <cstdlib>
#include "mult.h"

		
int main(int argc, char** argv) {
   std::cout<<"argc = " << argc<<std::endl;
   std::cout << argv[0] << std::endl;
   std::cout << argv[1] << std::endl;
   std::cout << argv[2] << std::endl;
        
  Math mth_obj;
  
  int row, col;
  char *r = argv[1];
  char *c = argv[2];
  if (mth_obj.is_valid_dimension(r, c)) {
       row = atoi(argv[1]);
       col = atoi(argv[2]);
  }
  //if (argv[1].size() > 1 || argv[2].size() > 1) {
  //   return 0;
  //}
  else {
    return 0;
  }


  struct ook **arr = mth_obj.create_tab(row, col);
  std::cout << std::endl;
  mth_obj.mult_values(arr, row, col); 
  std::cout << std::endl;
  mth_obj.div_values(arr,row,col);
  mth_obj.delete_tab(arr, row, col);
}

