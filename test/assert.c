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