#include <stdlib.h>

#include "cell.h"
#include "raylib.h"

#define NUM_BOMBS 10

const int screen_width = 400;
const int screen_height = 400;

int main(void) {
    InitWindow(screen_width, screen_height, "Minesweeper");

    Grid grid;
    grid_init(&grid, screen_width, screen_height);

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            grid_reveal(&grid, GetMouseX(), GetMouseY());
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        grid_draw(&grid);

        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}
