#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;
typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef void *(*Copy_void)(Object, int);
typedef void(displayer)(void *);

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

ArrayVoid_ptr copy_arrayVoid(Object *src, int length);
Object *create_object(Object src, int length, Copy_void copy_element);
void *copy_int(void *numbers, int position);

void free_arrayVoid(ArrayVoid_ptr src);
void free_Object(Object *src, int length);

void display_arrayVoid_ptr(ArrayVoid_ptr, displayer);

#endif