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
    int rows = 5, cols = 5;
    grid_t *grid = build_grid(rows, cols);
    int len = rows * cols;
    TEST_ASSERT_NOT_NULL(grid);
    TEST_ASSERT_NOT_NULL(grid->data);
    TEST_ASSERT_EQUAL(get_idx(grid, rows - 1, cols - 1), len - 1);

    destroy_grid(&grid);
    TEST_ASSERT_NULL(grid);

    rows = 800, cols = 450;
    grid = build_grid(rows, cols);
    len = rows * cols;
    TEST_ASSERT_NOT_NULL(grid);
    TEST_ASSERT_NOT_NULL(grid->data);
    TEST_ASSERT_EQUAL(get_idx(grid, rows - 1, cols - 1), len - 1);

    destroy_grid(&grid);
    TEST_ASSERT_NULL(grid);
}

void
test_randomize_grid(void) {
    grid_t *grid = build_grid(5, 5);
    randomize_grid(grid);

    TEST_ASSERT_NOT_NULL(grid);
    TEST_ASSERT_NOT_NULL(grid->data);

    int count = 0;
    for (int row = 0; row < grid->num_rows; row++) {
        for (int col = 0; col < grid->num_cols; col++) {
            if (grid->data[get_idx(grid, row, col)] == 1) {
                count++;
            }
        }
    }

    TEST_ASSERT(count > 0);
    TEST_ASSERT(count <= grid->num_cols * grid->num_rows);

    destroy_grid(&grid);
    TEST_ASSERT_NULL(grid);
}

void test_count_neighbours(void) {
    grid_t *grid = build_grid(3, 3);
    grid->data[get_idx(grid, 0, 0)] = 1;
    grid->data[get_idx(grid, 0, 1)] = 1;
    grid->data[get_idx(grid, 1, 0)] = 1;

    int count = count_neighbours(grid, 1, 1);
    TEST_ASSERT_EQUAL(count, 3);

    count = count_neighbours(grid, 0, 0);
    TEST_ASSERT_EQUAL(count, 2);

    count = count_neighbours(grid, 2, 2);
    TEST_ASSERT_EQUAL(count, 3);

    destroy_grid(&grid);
    TEST_ASSERT_NULL(grid);
}

void
test_get_cell_state(void) {
    grid_t *grid = build_grid(3, 3);
    grid->data[get_idx(grid, 0, 0)] = 1;
    grid->data[get_idx(grid, 0, 1)] = 1;

    int s = get_cell_state(grid, 1, 1);
    TEST_ASSERT_EQUAL(s, 0);

    s = get_cell_state(grid, 0, 0);
    TEST_ASSERT_EQUAL(s, 0);

    s = get_cell_state(grid, 0, 1);
    TEST_ASSERT_EQUAL(s, 0);

    destroy_grid(&grid);
    TEST_ASSERT_NULL(grid);
}

int
main(void) {
UNITY_BEGIN();
    RUN_TEST(test_set_up);
    RUN_TEST(test_build_grid);
    RUN_TEST(test_get_idx);
    RUN_TEST(test_randomize_grid);
    RUN_TEST(test_count_neighbours);
    RUN_TEST(test_get_cell_state);
return UNITY_END();
}
