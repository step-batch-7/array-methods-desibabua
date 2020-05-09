#ifndef __ASSERT_H_
#define __ASSERT_H_

#include "../array.h"
#include "../array_void.h"

typedef Bool (*is_equal)(void *,void *);

void describe(char *function_name);
void it(char *message, Bool status);
Bool assert_array(Array_ptr src, int *array, int count);
Bool assert_num(Bool status, int num1, int num2);

Bool compare_char_ptr(void *a, void *b);
Bool compare_int_ptr(void *a, void *b);
Bool assert_arrayVoid(ArrayVoid_ptr src, Object *array, int count, is_equal compare);

#endif