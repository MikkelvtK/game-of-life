//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#include "unity.h"

void
setUp(void) {}

void
tearDown(void) {}

void
test_set_up(void) {
    TEST_ASSERT_EQUAL(0, 0);
}

int
main(void) {
UNITY_BEGIN();
RUN_TEST(test_set_up);
return UNITY_END();
}
