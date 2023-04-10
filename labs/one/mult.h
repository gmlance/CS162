#ifndef mult_h
#define mult_h

#include <iostream>

struct ook{
   int mult;
   float div;
};
class Math{
   public:
      bool is_valid_dimension(char* r, char* c);
      ook** create_tab(int row, int col);
      void mult_values(ook **arr, int row, int col);
      void div_values (ook **arr, int row, int col);
      void delete_tab(ook **arr, int row, int col);
};
#endif
