#ifndef CELL_H
#define CELL_H

#include <stdbool.h>
#include <stddef.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x;
    int y;
    bool revealed;
    bool has_mine;
} Cell;

typedef struct {
    Cell cells[COLS][ROWS];
    int width;
    int height;
} Grid;

void grid_init(Grid* grid, int width, int height);
void grid_draw(Grid* grid);
void grid_reveal(Grid* grid, int x, int y);

#endif
