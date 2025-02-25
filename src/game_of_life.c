//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#include "game_of_life.h"

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void
draw(grid_t *grid) {
    BeginDrawing();
    ClearBackground(BLACK);

    for (int row = 0; row < grid->num_rows; row++) {
        for (int col = 0; col < grid->num_cols; col++) {
            const Color c = grid->data[get_idx(grid, row, col)] ? LIGHTGRAY : BLACK;
            DrawRectangle(col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, c);
        }
    }

    EndDrawing();
}

void
update(grid_t *grid) {
    int *tgrid = calloc(grid->num_rows * grid->num_cols, sizeof(int));
    if (tgrid == NULL) {
        destroy_grid(&grid);
        exit(EXIT_FAILURE);
    }

    for (int row = 0; row < grid->num_rows; row++) {
        for (int col = 0; col < grid->num_cols; col++) {
            tgrid[get_idx(grid, row, col)] = get_cell_state(grid, row, col);
        }
    }

    free(grid->data);
    grid->data = tgrid;
}

grid_t*
init() {
    SetTargetFPS(fps);

    grid_t *grid = build_grid(screen_height / CELL_SIZE, screen_width / CELL_SIZE);
    if (grid->data == NULL) {
        exit(EXIT_FAILURE);
    }

    randomize_grid(grid);
    return grid;
}

grid_t*
build_grid(int num_rows, int num_cols) {
    grid_t* grid = malloc(sizeof(grid_t));
    if (grid == NULL) {
        exit(EXIT_FAILURE);
    }

    grid->num_rows = num_rows;
    grid->num_cols = num_cols;
    grid->data = calloc(num_rows * num_cols, sizeof(grid_t));
    if (grid->data == NULL) {
        free(grid);
        exit(EXIT_FAILURE);
    }

    return grid;
}

void
randomize_grid(grid_t *grid) {
    for (int row = 0; row < grid->num_rows; row++) {
        for (int col = 0; col < grid->num_cols; col++) {
            grid->data[get_idx(grid, row, col)] = GetRandomValue(0, initial_density) == initial_density;
        }
    }
}

void
destroy_grid(grid_t **grid) {
    free((*grid)->data);
    free(*grid);
    *grid = NULL;
}

int
get_idx(const grid_t *grid, int row, int col) {
   return row * grid->num_cols + col;
}

int
count_neighbours(const grid_t *grid, int row, int col) {
    const int num_neighbours = 8;
    const pos_t ndeltas[num_neighbours] = {
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
        const int nrow = (row + ndeltas[i].y + grid->num_rows) % grid->num_rows;
        const int ncol = (col + ndeltas[i].x + grid->num_cols) % grid->num_cols;
        count += grid->data[get_idx(grid, nrow, ncol)];
    }

    return count;
}

int
get_cell_state(const grid_t *grid, int row, int col) {
    const int ncount = count_neighbours(grid, row, col);
    const int cell = grid->data[get_idx(grid, row, col)];

    if (cell && (ncount < 2 || ncount > 3)) {
        return DEAD;
    }

    if (!cell && ncount != 3) {
        return DEAD;
    }

    return ALIVE;
}
