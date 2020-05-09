#include <stdio.h>
#include <stdlib.h>
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

ArrayVoid_ptr copy_arrayVoid(Object src,int length, Copy_void copy_element)
{
  ArrayVoid_ptr arrayVoid = malloc(sizeof(ArrayVoid_ptr));
  arrayVoid->length = length;
  arrayVoid->array = create_object(src, length, copy_element);
  return arrayVoid;
}

void *copy_char(Object src,int position)
{
  char *element = malloc(sizeof(char));
  *element = ((char *)src)[position];
  return element;
}

void display_arrayVoid_ptr(ArrayVoid_ptr arrayVoid, displayer console){
  for (int i = 0; i < arrayVoid->length; i++)
  {
    (*console)(arrayVoid->array[i]);
  }
  printf("\n");
}