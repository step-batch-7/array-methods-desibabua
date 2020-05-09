#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array_void.h"

void display_array(Array_ptr src, char *msg)
{
  printf("%s  ", msg);
  for (int i = 0; i < src->length; i++)
  {
    printf("%d ",src->array[i]);
  }
  printf("\n");
}

void display_number(int number)
{
  printf("%d \n", number);
}

void display_char(void *character)
{
  printf("%c ",*(char *)character);
}

int increment(int a)
{
  return a + 1;
}

Bool is_even(int a)
{
  return a % 2 == 0;
}

int sum(int a, int b)
{
  return a + b;
}

int main()
{
  int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array_ptr list = copy_int_array(values, 8);
  display_array(list, "numbers :");

  Array_ptr inc_list = map(list, &increment);
  display_array(inc_list, "incremented list :");

  Array_ptr even_numbers = filter(list, &is_even);
  display_array(even_numbers, "even numbers :");

  int total = reduce(list, 0, &sum);
  display_number(total);

  char array[] = {'a', 'b', 'c'};
  ArrayVoid_ptr new_array = copy_arrayVoid(array, 3, &copy_char);
  display_arrayVoid_ptr(new_array, &display_char);

  free_array(list);
  free_array(inc_list);
  free_array(even_numbers);
  return 0;
}