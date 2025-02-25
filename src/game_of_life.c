//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#include "game_of_life.h"

#include <stdio.h>
#include <stdlib.h>

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
destroy_grid(grid_t **grid) {
    free((*grid)->data);
    free(*grid);
    *grid = NULL;
}

int
get_idx(grid_t *grid, int row, int col) {
   return row * grid->num_cols + col;
}

