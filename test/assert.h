#ifndef __ASSERT_H_
#define __ASSERT_H_

#include "../array.h"

void describe(char *function_name);
void it(char *message, Bool status);
Bool assert_array(Array_ptr src, int *array, int count);
Bool assert_num(Bool status, int num1, int num2);

#endif