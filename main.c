#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "raymath.h"

#define COLS 10
#define ROWS 10

const int screen_width = 400;
const int screen_height = 400;

const int cell_width = screen_width / COLS;
const int cell_height = screen_height / ROWS;

typedef struct {
  Vector2 pos;
  bool contains_mine;
  bool revealed;
} Cell;

Cell grid[COLS][ROWS];

void cell_draw(Cell);

int main(void) {
  srand(time(0));

  InitWindow(screen_width, screen_height, "Minesweeper");

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      grid[i][j] = (Cell){
          .pos = (Vector2){.x = i * cell_width, .y = j * cell_height},
          .contains_mine = false,
          .revealed = false,
      };
    }
  }

  while (!WindowShouldClose()) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      Vector2 mouse_pos = GetMousePosition();
      int mouse_row = floor(mouse_pos.y) / cell_height;
      int mouse_col = floor(mouse_pos.x) / cell_width;
      grid[mouse_col][mouse_row].revealed = true;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);
    for (int i = 0; i < COLS * ROWS; i++) {
      int row = i % ROWS;
      int col = i / COLS;
      cell_draw(grid[row][col]);
    }

    EndDrawing();
  }

  CloseWindow();

  return EXIT_SUCCESS;
}

void cell_draw(Cell cell) {
  DrawRectangleLines(cell.pos.x, cell.pos.y, cell_width, cell_height, BLACK);
  if (cell.revealed) {
    DrawRectangle(cell.pos.x + 4, cell.pos.y + 4, cell_width - 8, cell_height - 8, MAROON);
  }
}
