#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "batstat.c"


static void check_args(void **state) {
  
  assert_int_equal(-1, parse_args(1, (char*[]){"batstat"}));
  assert_int_equal(-1, parse_args(3, (char*[]){"batstat", "1", "2"}));

  assert_int_equal(-1, parse_args(2, (char*[]){"batstat", "2"}));
  assert_int_equal(-1, parse_args(2, (char*[]){"batstat", "-1"}));
  assert_int_equal(-1, parse_args(2, (char*[]){"batstat", "1"}));
  
  assert_int_equal(3, parse_args(3, (char*[]){"batstat", "Dataset.csv","Phyllostomidae"}));
}



static void test_average(void **state){
      const float tab[5]={1.0,1.0,1.0,1.0,1.0};
      
      assert_float_equal(1.0,average(tab,5),00001);//true
      assert_float_equal(3.0,average(tab,5),00001);//false

}


int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_average),
      cmocka_unit_test(check_args),
    
  };
  result |= cmocka_run_group_tests_name("batstat", tests, NULL, NULL);

  return result;
}
