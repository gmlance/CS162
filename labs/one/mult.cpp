
#include "mult.h"
#include <iostream>
#include <cstdlib>
bool Math::is_valid_dimension(char* r, char* c){
   int row, col, n;
   n= 0;
   row= atoi(r);
   col = atoi(c);
   if(row > 0) {
      if(row<=9){
	 n = n + 1;
      }
      else {
	 return false;
      }
      if(col > 0){
	 if (col <=9) {
	    n = n + 1;
	 }
	 else {
	    return false;
	 }
      }
   }
   if(n = 2) {
      return true;
   }
   else{
      return false;
   }
}
ook** Math::create_tab(int row, int col) {

   ook **arr = NULL; 
   arr = new ook*[row];
   for(int i = 0; i<row;i++){
	 arr[i] = new ook[col];
   }
	 return arr;
}
void Math::mult_values(ook **arr, int row, int col) {
 for(int i = 0; i<row;i++){
  for(int j = 0; j < col; j++){
    arr[i][j].mult = (i+1)*(j+1);
    }
 }
 for(int i = 0; i < row; i++){
  for(int j = 0; j < col; j++) {
  std::cout << arr[i][j].mult<<" ";
  }
  std::cout << std::endl;
 }
}
void Math::div_values (ook **arr, int row, int col){
 for( int i = 0; i<row; i++){
  for(int j= 0; j<col; j++){
    arr[i][j].div = (i +1.0)/(j+1);
  }
 }
 for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++){
       std::cout<<arr[i][j].div<<" ";
    }
    std::cout << std::endl;
 }
}
void Math::delete_tab(ook **arr, int row, int col){
   for(int i = 0; i<row; i++){
      delete [] arr[i];
   }
   delete [] arr;
}
