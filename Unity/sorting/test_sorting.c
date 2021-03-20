#include <stddef.h>

#include "sorting.h"
#include "unity.h"

#define LEN 5

void setUp(void) {}
void tearDown(void) {}

void test_insertion_sort(void) {
    int expected[LEN] = {1, 2, 3, 4, 5};
    int actual[LEN] = {2, 4, 3, 5, 1};
    insertion_sort(LEN, actual);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, LEN);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_insertion_sort);
    return UNITY_END();
}
