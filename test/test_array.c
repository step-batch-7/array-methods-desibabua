#include "../array.h"
#include "assert.h"

void test_copy_array(void)
{
  describe("copy_array");

  int numbers[5] = {1, 2, 3, 4, 5};
  Array_ptr array = copy_array(numbers, 5);
  Bool status = assert_array(array,numbers , 5);
  free_array(array);
  
  it("should copy the elements of array", status);
}

int main(void)
{
  test_copy_array();
  return 0;
}
