#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <OpenGL/gl.h>

class WindowManager {
public:
    int width;
    int height;
    int cell_size;
    bool x_is_even;
    bool y_is_even;

    WindowManager(int width, int height, int cell_size);

    void resize(int width, int height);
    int xCellDemand();
    int yCellDemand();
    int leftMargin();
    int bottomMargin();

    //private:
    bool hasLeft();
    bool hasBottom();
};

#endif
