#include <stdio.h> 
#include "assert.h"

Bool assert_array(Array_ptr src, int *array, int count)
{
  Bool status = (src->length == count);

  int index;
  while (status && count)
  {
    index = src->length - count;
    status = assert_num(status, src->array[index], array[index]);
    count--;
  }

  return status;
}

Bool assert_arrayVoid(ArrayVoid_ptr src, Object *array, int count, is_equal compare)
{
  Bool status = (src->length == count);

  int index;
  while (status && count)
  {
    index = src->length - count;
    status = status && (*compare)(src->array[index], array[index]);
    count--;
  }

  return status;
}

Bool compare_char_ptr(void *a,void *b)
{
  return *(char *)a == *(char *)b;
}

Bool compare_int_ptr(void *a,void *b)
{
  return *(int *)a == *(int *)b;
}

Bool assert_num(Bool status, int num1,int num2)
{
  return status && (num1 == num2);
}

void describe(char *function_name)
{
  printf("\n # %s\n\n", function_name);
}

void it(char *message, Bool status)
{
  char *symbol = status ? "✓" : "✘";
  printf("  %s %s\n",symbol, message);
}