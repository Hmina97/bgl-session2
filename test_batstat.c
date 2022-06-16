#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "batstat.c"



static void test_average(void **state){
      const float tab[5]={1.0,1.0,1.0,1.0,1.0};
      
      assert_float_equal(1.0,average(tab,5),0001);//true
      assert_float_equal(3.0,average(tab,5),0001);//false

}


int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_average),
    
  };
  result |= cmocka_run_group_tests_name("batstat", tests, NULL, NULL);

  return result;
}