#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array_ptr copy_array(int *array, int length)
{
  Array_ptr src = malloc(sizeof(Array));
  src->length = length;
  src->array = malloc(sizeof(int) * length);

  int index;
  while (length > 0)
  {
    index = src->length - length;
    src->array[index] = array[index];
    length--;
  }

  return src;
}

void free_array(Array_ptr src)
{
  free(src->array);
  free(src);
  src = NULL;
}

void display_array(Array_ptr src)
{
  for (int i = 0; i < src->length; i++)
  {
    printf("%d ",src->array[i]);
  }
  printf("\n");
}
