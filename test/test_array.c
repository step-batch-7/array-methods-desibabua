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
  it("should map the elements of list", status);

  free_array(numbers);
  free_array(actual_inc_numbers);
}

int main(void)
{
  test_copy_array();
  test_map_function();
  return 0;
}
