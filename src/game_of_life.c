//
// Created by Michiel van 't Klooster on 24/02/2025.
//

#include "game_of_life.h"

#include <menu.h>

#include "grid.h"

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

static grid_t *grid;
static menu_t menu;

void draw(void) {
    BeginDrawing();
    ClearBackground(BLACK);

    grid_draw(grid);

    EndDrawing();
}

void update(void) {
    grid_update(grid);
}

void init() {
    SetTargetFPS(fps);
    printf("Game of Life\n");
    menu = menu_create();
    grid = grid_create(screen_width, screen_height);
    grid_randomize(grid);
    grid_draw(grid);
}

void update_draw_frame(void) {
    update();
    draw();
}

void cleanup(void) {
    grid_destroy(&grid);
    if (grid != NULL) {
        exit(EXIT_FAILURE);
    }
}