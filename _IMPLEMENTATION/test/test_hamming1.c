#include "unity.h"
#include "hamming1.h"
#include "test_hamming1.h"


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
int arr[6]={1,0,1,1,1,1};
int arr1[10]={1,1,1,0,0,1,1,0,1,0};
int arr2[10]={1,0,1,0,0,1,1,0,1,1};
int arr3[10]={1,0,1,1,0,1,1,0,1,1};

void test_hamming1(void)
{
  //TEST_ASSERT_EQUAL(101011011, hamming1(101111,6,101011011));
  TEST_ASSERT_EQUAL_INT16_ARRAY(arr2, hamming1(arr,6,arr2),10);
}
void test_error(void)
{
  //TEST_ASSERT_EQUAL(101011011, hamming1(101111,6,101011010));
  TEST_ASSERT_EQUAL_INT16_ARRAY(arr2, hamming1(arr,6,arr1),10);

}

int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_hamming1);
  RUN_TEST(test_error);
  

/* Close the Unity Test Framework */
  return UNITY_END();
}
