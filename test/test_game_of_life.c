//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#include <stdlib.h>

#include "unity.h"
#include "game_of_life.h"

void
setUp(void) {}

void
tearDown(void) {}

void
test_set_up(void) {
    TEST_ASSERT_EQUAL(0, 0);
}

void
test_build_grid(void) {
    grid_t *grid = build_grid(5, 5);
    TEST_ASSERT_NOT_NULL(grid);
    TEST_ASSERT_NOT_NULL(grid->data);
    TEST_ASSERT_EQUAL_size_t(sizeof(*grid), sizeof(grid_t));
    TEST_ASSERT_EQUAL(grid->num_cols, 5);
    TEST_ASSERT_EQUAL(grid->num_rows, 5);
    TEST_ASSERT_EQUAL(grid->data[grid->num_cols * grid->num_rows - 1], 0);

    destroy_grid(&grid);

    TEST_ASSERT_NULL(grid);
}

void
test_get_idx(void) {
    grid_t *grid = build_grid(5, 5);
    int len = 5 * 5;
    TEST_ASSERT_NOT_NULL(grid);
    TEST_ASSERT_NOT_NULL(grid->data);
    TEST_ASSERT_EQUAL(get_idx(grid, 4, 4), len - 1);

    destroy_grid(&grid);

    TEST_ASSERT_NULL(grid);
}

int
main(void) {
UNITY_BEGIN();
    RUN_TEST(test_set_up);
    RUN_TEST(test_build_grid);
    RUN_TEST(test_get_idx);
return UNITY_END();
}
