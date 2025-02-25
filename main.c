#include <game_of_life.h>
#include <raylib.h>
#include <stdlib.h>

int main(void) {
    InitWindow(screen_width, screen_height, "Game of Life");

    grid_t *grid = init();

    while (!WindowShouldClose()) {
        draw(grid);
    }

    CloseWindow();
    destroy_grid(&grid);
    if (grid != NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
