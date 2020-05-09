#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "assert.h"
#include "../array_void.h"

void test_copy_array_void(void)
{
  describe("copy_array_void");

  int array[] = {1, 2, 3};
  Object *act_list = create_object(array, 3, &copy_int);

  ArrayVoid_ptr copied_array = copy_arrayVoid(act_list, 3);
  Object *exp_array = create_object(array, 3, &copy_int);
  Bool status = assert_arrayVoid(copied_array, exp_array, 3, &compare_int_ptr);
  it("should create same arrayVoid", status);
}

Object mul_by_2(Object number)
{
  int *output = malloc(sizeof(int));
  *output = (*(int *)number) * 2;
  return output;
}

void test_map_void(void)
{
  describe("map_void");

  int array[] = {1, 2, 3};
  Object *numbers = create_object(array, 3, &copy_int);
  ArrayVoid_ptr numbers_voids = copy_arrayVoid(numbers, 3);

  int exp_array[] = {2, 4, 6};
  Object *exp_numbers = create_object(exp_array, 3, &copy_int);

  ArrayVoid_ptr act_numbers = map_void(numbers_voids, &mul_by_2);
  Bool status = assert_arrayVoid(act_numbers, exp_numbers, 3, &compare_int_ptr);
  it("should map the elements of list", status);
}

void test_array_void(void)
{
  test_copy_array_void();
  test_map_void();
}
