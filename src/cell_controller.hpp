#ifndef CELL_CONTROLLER_H
#define CELL_CONTROLLER_H

#include <queue>

void expandWorld(int x_size, int y_size);
void initWorld(int x_size, int y_size);

bool isAlive(int x_coord, int y_coord);
int xCellSize();
int yCellSize();

int cell_alive_x_start(int window_width, int cell_width);
int cell_alive_y_start(int window_height, int cell_height);

#endif
