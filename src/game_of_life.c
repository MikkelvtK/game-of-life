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
static menu_t *menu;

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

    grid = grid_create(screen_width, grid_height);
    if (grid == NULL) {
        printf("Failed to create grid\n");
        exit(EXIT_FAILURE);
    }

    grid_randomize(grid);
    grid_draw(grid);

    menu = menu_create(screen_width, menu_height, (Vector2){0, screen_height});
    if (menu == NULL) {
        printf("Failed to create menu\n");
        grid_destroy(&grid);
        exit(EXIT_FAILURE);
    }
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

    menu_destroy(&menu);
    if (menu != NULL) {
        exit(EXIT_FAILURE);
    }
}