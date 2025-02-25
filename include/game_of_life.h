//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define CELL_SIZE 4
#define ALIVE 1
#define DEAD 0

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct grid {
    int     num_rows;
    int     num_cols;
    int*    data;
} grid_t;

static const int screen_width = 1200;
static const int screen_height = 800;
static const int fps = 8;
static const int initial_density = 3;

void    draw(grid_t *grid);
void    update(grid_t *grid);
grid_t* init();
grid_t* build_grid(int num_rows, int num_cols);
void    randomize_grid(grid_t *grid);
void    destroy_grid(grid_t **grid);
int     get_idx(const grid_t *grid, int row, int col);
int     count_neighbours(const grid_t *grid, int row, int col);
int     get_cell_state(const grid_t *grid, int row, int col);

#endif //GAME_OF_LIFE_H
