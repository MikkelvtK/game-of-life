//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define CELL_SIZE 25

typedef struct grid {
    int     num_rows;
    int     num_cols;
    int*    data;
} grid_t;

static const int screen_width = 800;
static const int screen_height = 450;
static const int fpd = 12;

void    draw(grid_t* grid);
void    update(grid_t* grid);
grid_t* init();
grid_t* build_grid(int num_rows, int num_cols);
int     get_idx(int row, int col);

#endif //GAME_OF_LIFE_H
