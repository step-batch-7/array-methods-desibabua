#include "array.h"

int main()
{
  int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array_ptr list = copy_array(values, 8);
  display_array(list);

  free_array(list);
  return 0;
}