#include "tests.h"
#include "assert.h"
#include <stdio.h>
#include "../array_void.h"

void test_array_void(void)
{
  describe("copy_array_void");

  char array[] = {'a', 'b', 'c'};
  Object *src = create_object(array, 3, &copy_char);
  ArrayVoid_ptr new_array = copy_arrayVoid(array, 3, &copy_char);

  Bool status = assert_arrayVoid(new_array, src, 3, &compare_char_ptr);
  it("should create arrayVoid", status);
}
