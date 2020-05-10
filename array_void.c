#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_void.h"

Object *create_object(Object src, int length, Copy_void copy_element)
{
  Object *array = malloc(sizeof(Object) * length);
  for (int i = 0; i < length; i++)
  {
    array[i] = (*copy_element)(src, i);
  }
  return array;
}

ArrayVoid_ptr copy_arrayVoid(Object *src,int length)
{
  ArrayVoid_ptr arrayVoid = malloc(sizeof(ArrayVoid));
  arrayVoid->length = length;
  arrayVoid->array = src;
  return arrayVoid;
}

void *copy_int(Object numbers,int position)
{
  int *element = malloc(sizeof(int));
  *element = ((int *)numbers)[position];
  return element;
}

void free_Object(Object *src, int length)
{
  for (int index = 0; index < length; index++)
  {
    free(src[index]);
  }
  free(src);
  src = NULL;
}

void free_arrayVoid(ArrayVoid_ptr src)
{
  free_Object(src->array, src->length);
  free(src);
  src = NULL;
}

void display_arrayVoid_ptr(ArrayVoid_ptr arrayVoid, displayer console){
  for (int i = 0; i < arrayVoid->length; i++)
  {
    (*console)(arrayVoid->array[i]);
  }
  printf("\n");
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper){
  Object *temp = malloc(sizeof(Object) * src->length);

  for (int i = 0; i < src->length; i++)
  {
    temp[i] = (*mapper)(src->array[i]);
  }
  return copy_arrayVoid(temp, src->length);
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object temp[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if((*predicate)(src->array[i])){
      temp[count] = src->array[i];
      count++;
    }
  }
  Object *filtered_value = malloc(sizeof(Object) * count);
  memcpy(filtered_value, temp, (sizeof(Object) * count));

  return copy_arrayVoid(filtered_value, count);
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = (*reducer)(init, src->array[i]);
  }
  return init;
}
