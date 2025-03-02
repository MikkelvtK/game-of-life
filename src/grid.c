//
// Created by Michiel van 't Klooster on 26/02/2025.
//

#include "grid.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grid_s {
    int rows;
    int cols;
    int data[];
};

static const int initial_density = 4;

inline int grid_get_idx(grid_t *grid, int row, int col) {
    return row * grid->cols + col;
}

int grid_count_neighbours(grid_t *grid, int row, int col) {
    const int num_neighbours = 8;
    const Vector2 ndeltas[num_neighbours] = {
        {.x = -1, .y = 0},
        {.x = 1, .y = 0},
        {.x = 0, .y = -1},
        {.x = 0, .y = 1},
        {.x = -1, .y = -1},
        {.x = -1, .y = 1},
        {.x = 1, .y = -1},
        {.x = 1, .y = 1},
    };

    int count = 0;
    for (int i = 0; i < num_neighbours; i++) {
        const int nrow = (int)(row + ndeltas[i].y + grid->rows) % grid->rows;
        const int ncol = (int)(col + ndeltas[i].x + grid->cols) % grid->cols;
        count += grid->data[grid_get_idx(grid, nrow, ncol)];
    }

    return count;
}

int grid_get_cell_state(grid_t *grid, int row, int col) {
    const int ncount = grid_count_neighbours(grid, row, col);
    const int cell = grid->data[grid_get_idx(grid, row, col)];

    if (cell && (ncount < 2 || ncount > 3)) {
        return DEAD;
    }

    if (!cell && ncount != 3) {
        return DEAD;
    }

    return ALIVE;
}

grid_t *grid_create(int width, int height) {
    const int rows = height / CELL_SIZE;
    const int cols = width / CELL_SIZE;

    grid_t *grid = (grid_t *)malloc(sizeof(grid_t) + (rows * cols * sizeof(int)));
    if (grid == NULL) {
        return NULL;
    }

    grid->cols = cols;
    grid->rows = rows;
    grid_randomize(grid);
    return grid;
}

void grid_destroy(grid_t **grid) {
    free(*grid);
    *grid = NULL;
}

void grid_draw(grid_t *grid) {
    if (grid == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->cols; col++) {
            const Color c = grid->data[grid_get_idx(grid, row, col)] ? LIGHTGRAY : BLACK;
            DrawRectangle(col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, c);
        }
    }
}

int grid_update(grid_t *grid) {
    int *tgrid = (int *)calloc(grid->rows * grid->cols, sizeof(int));
    if (tgrid == NULL) {
        return -1;
    }

    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->cols; col++) {
            tgrid[grid_get_idx(grid, row, col)] = grid_get_cell_state(grid, row, col);
        }
    }

    int *dst = memcpy(grid->data, tgrid, sizeof(int) * grid->rows * grid->cols);
    if (dst == NULL) {
        return -1;
    }
    return 0;
}

void grid_randomize(grid_t *grid) {
    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->cols; col++) {
            grid->data[grid_get_idx(grid, row, col)] = GetRandomValue(0, initial_density) == initial_density;
        }
    }
}
