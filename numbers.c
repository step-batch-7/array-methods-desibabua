#include "array.h"

int increment(int a)
{
  return a + 1;
}

int main()
{
  int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array_ptr list = copy_array(values, 8);
  display_array(list);

  Array_ptr inc_list = map(list, &increment);
  display_array(inc_list);

  free_array(list);
  free_array(inc_list);
  return 0;
}