#include "cell.h"
#include <raylib.h>

#define CELL_PADDING 4

static int grid_cell_width(Grid grid) { return grid.width / ROWS; }

static int grid_cell_height(Grid grid) { return grid.height / COLS; }

void grid_init(Grid* grid, int width, int height) {
    grid->width = width;
    grid->height = height;

    int cell_width = grid_cell_width(*grid);
    int cell_height = grid_cell_height(*grid);

    size_t grid_size = ROWS * COLS;
    for (size_t i = 0; i < grid_size; i++) {
        size_t col = i / COLS;
        size_t row = i % ROWS;
        grid->cells[col][row] = (Cell){
            .x = col * cell_width,
            .y = row * cell_height,
            .has_mine = false,
            .revealed = false,
        };
    }
}

static void cell_draw(Cell cell, int width, int height) {
    DrawRectangleLines(cell.x, cell.y, width, height, BLACK);

    if (!cell.revealed) {
        return;
    }

    DrawRectangle(
        cell.x + CELL_PADDING / 2,
        cell.y + CELL_PADDING / 2,
        width - CELL_PADDING,
        height - CELL_PADDING,
        cell.has_mine ? MAROON : GREEN
    );
}

void grid_draw(Grid* grid) {
    size_t grid_size = ROWS * COLS;
    for (size_t i = 0; i < grid_size; i++) {
        size_t col = i / COLS;
        size_t row = i % ROWS;
        cell_draw(grid->cells[col][row], grid_cell_width(*grid),
                  grid_cell_height(*grid));
    }
}

static Cell* grid_at(Grid* grid, int x, int y) {
    size_t col = x / grid_cell_width(*grid);
    size_t row = y / grid_cell_height(*grid);
    return &grid->cells[col][row];
}

void grid_reveal(Grid* grid, int x, int y) {
    grid_at(grid, x, y)->revealed = true;
}
