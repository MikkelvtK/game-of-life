#include "game_of_life.h"
#include <raylib.h>
#include <stdlib.h>

int main(void) {
    InitWindow(screen_width, screen_height, "Game of Life");

    init();

    while (!WindowShouldClose()) {
        update_draw_frame();
    }

    CloseWindow();

    cleanup();
    return EXIT_SUCCESS;
}
