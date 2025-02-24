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
    return grid;
}

