#include "../array.h"
#include "assert.h"

void test_copy_array(void)
{
  describe("copy_array");

  int numbers[5] = {1, 2, 3, 4, 5};
  Array_ptr array = copy_array(numbers, 5);
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
  Array_ptr numbers = copy_array(values, 5);

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
  Array_ptr numbers = copy_array(values, 8);

  Array_ptr actual_odd_numbers = filter(numbers, &is_odd);
  int expected_odd_numbers[4] = {1, 3, 5, 7};

  Bool status = assert_array(actual_odd_numbers, expected_odd_numbers, 4);
  it("should filter numbers according to predicate from list", status);

  free_array(numbers);
  free_array(actual_odd_numbers);
}

int main(void)
{
  test_copy_array();
  test_map_function();
  test_filter_function();
  return 0;
}
