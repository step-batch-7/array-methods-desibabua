#include <stdlib.h>
#include "array.h"

Array_ptr copy_int_array(int *array, int length)
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

Array_ptr map(Array_ptr src, Mapper Mapper)
{
  int temp[src->length];
  for (int i = 0; i < src->length; i++)
  {
    temp[i] = (*Mapper)(src->array[i]);
  }
  return copy_int_array(temp, src->length);
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  int temp[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if((*predicate)(src->array[i])){
      temp[count] = src->array[i];
      count++;
    }
  }
  return copy_int_array(temp, count);
}

int reduce(Array_ptr src, int init, Reducer reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = (*reducer)(init, src->array[i]);
  }
  return init;
}
