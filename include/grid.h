//
// Created by Michiel van 't Klooster on 26/02/2025.
//

#ifndef GRID_H
#define GRID_H

#define CELL_SIZE 4
#define ALIVE 1
#define DEAD 0

typedef struct grid_s grid_t;

void        grid_draw(grid_t *grid);
grid_t*     grid_create(int width, int height);
void        grid_destroy(grid_t **grid);
void        grid_update(grid_t *grid);
void        grid_randomize(grid_t *grid);
int         grid_get_idx(grid_t *grid, int row, int col);

#endif //GRID_H
