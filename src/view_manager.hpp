#ifndef VIEW_MANAGER_H
#define VIEW_MANAGER_H

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "window_manager.hpp"
#include "cell_controller.hpp"

void setupView(int, char **, int);

void display();
void reshape(int, int);
void mouse(int, int, int, int);

void init();

constexpr int CELLSIZE = 10;
constexpr int INIT_WIDTH = 510;
constexpr int INIT_HEIGHT = 510;

// color
constexpr double ALIVE_R = 1.0;
constexpr double ALIVE_G = 1.0;
constexpr double ALIVE_B = 1.0;
constexpr double DEAD_R = 0.0;
constexpr double DEAD_G = 0.0;
constexpr double DEAD_B = 0.0;
constexpr double BORDER_R = 0.4;
constexpr double BORDER_G = 0.4;
constexpr double BORDER_B = 0.4;

#endif
