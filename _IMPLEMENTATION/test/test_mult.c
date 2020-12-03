#include "unity.h"
#include "mult.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_mult(void)
{
  TEST_ASSERT_EQUAL(2,mult(0));
}

int test1_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_mult);



/* Close the Unity Test Framework */
  return UNITY_END();
}
