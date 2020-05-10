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

void display_int(void *number)
{
  printf("%d ",*(int *)number);
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

Object mul_by_5(Object number)
{
  int *output = malloc(sizeof(int));
  *output = (*(int *)number) * 5;
  return output;
}

Bool is_odd_void(Object number)
{
  return (*(int *)number) % 2 != 0;
}

Object sum_void(Object init,Object number)
{
  int *result = malloc(sizeof(int));
  *result = *(int *)init + *(int *)number;
  return result;
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

  int array[5] = {1, 2, 3, 4, 5};
  Object *num_list = create_object(array, 5, &copy_int);
  ArrayVoid_ptr num_list_void = copy_arrayVoid(num_list, 5);

  ArrayVoid_ptr mapped_array = map_void(num_list_void, &mul_by_5);
  display_arrayVoid_ptr(mapped_array, &display_int);

  ArrayVoid_ptr odd_void = filter_void(num_list_void, &is_odd_void);
  display_arrayVoid_ptr(odd_void, &display_int);

  Object initial = calloc(1, sizeof(int));
  Object total_void = reduce_void(num_list_void, initial, &sum_void);
  display_int(total_void);

  free_array(list);
  free_array(inc_list);
  free_array(even_numbers);

  free_arrayVoid(num_list_void);
  free_arrayVoid(mapped_array);
  free(initial);
  free(total_void);

  return 0;
}