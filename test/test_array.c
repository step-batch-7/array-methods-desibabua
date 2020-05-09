#include "../array.h"
#include "assert.h"
#include "tests.h"

void test_copy_int_array(void)
{
  describe("copy_int_array");

  int numbers[5] = {1, 2, 3, 4, 5};
  Array_ptr array = copy_int_array(numbers, 5);
  it("should copy the elements of array", assert_array(array,numbers , 5));

  free_array(array);
}

int increment(int a)
{
  return a + 1;
}

void test_map_function(void)
{
  describe("map_function");

  int values[5] = {1, 2, 3, 4, 5};
  Array_ptr numbers = copy_int_array(values, 5);

  Array_ptr actual_inc_numbers = map(numbers, &increment);
  int expected_inc_numbers[5] = {2, 3, 4, 5, 6};

  Bool status = assert_array(actual_inc_numbers, expected_inc_numbers, 5);
  it("should map the elements of list having numbers", status);

  free_array(numbers);
  free_array(actual_inc_numbers);
}

Bool is_odd(int a)
{
  return a % 2 == 1;
}

void test_filter_function(void)
{
  describe("filter_function");

  int values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Array_ptr numbers = copy_int_array(values, 8);

  Array_ptr actual_odd_numbers = filter(numbers, &is_odd);
  int expected_odd_numbers[4] = {1, 3, 5, 7};

  Bool status = assert_array(actual_odd_numbers, expected_odd_numbers, 4);
  it("should filter numbers according to predicate from list", status);

  free_array(numbers);
  free_array(actual_odd_numbers);
}

int sum(int a, int b)
{
  return a + b;
}

void test_reduce_function(void)
{
  describe("reduce_function");

  int values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Array_ptr numbers = copy_int_array(values, 8);

  int actual_sum = reduce(numbers, 0, &sum);
  int expected_sum = 36;

  Bool status = assert_num(True, actual_sum, expected_sum);
  it("should reduce according to reducer", status);

  free_array(numbers);
}

void test_array(void)
{
  test_copy_int_array();
  test_map_function();
  test_filter_function();
  test_reduce_function();
}
