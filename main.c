#include <game_of_life.h>
#include <raylib.h>

int main(void) {
    InitWindow(screen_width, screen_height, "Game of Life");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello World!", 20, 20, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}