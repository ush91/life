#include <iostream>

#include "view_manager.hpp"

static WindowManager window(INIT_HEIGHT, INIT_WIDTH, CELLSIZE);

void setupView(int argc, char **argv, int name_first_char) {
    glutInitWindowSize(INIT_WIDTH, INIT_HEIGHT);
    glutInit(&argc, argv);
    glutCreateWindow(argv[0] + name_first_char);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);

    init();

    glutMainLoop();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    int left_start = window.leftMargin();
    int bottom_start = window.bottomMargin();

    int x_zero = (xCellSize() - window.xCellDemand()) / 2;
    int y_zero = (yCellSize() - window.yCellDemand()) / 2;

    for (int y = 0; bottom_start + y * CELLSIZE < window.height; y++) {
        for (int x = 0; left_start + x * CELLSIZE < window.width; x++) {
            if (isAlive(x_zero + x, y_zero + y)) {
                glColor3d(ALIVE_R, ALIVE_G, ALIVE_B);
            } else {
                glColor3d(DEAD_R, DEAD_G, DEAD_B);
            }
            glRectd(left_start + x * CELLSIZE,
                    bottom_start + y * CELLSIZE,
                    left_start + (x + 1) * CELLSIZE,
                    bottom_start + (y + 1) * CELLSIZE);
        }
    }

    glColor3d(BORDER_R, BORDER_G, BORDER_B);
    for (int x = 0; left_start + x * CELLSIZE <= window.width; x++) {
        for (int y = 0; bottom_start + y * CELLSIZE <= window.height; y++) {
            glBegin(GL_LINES);
            glVertex2d(left_start + x * CELLSIZE, 0);
            glVertex2d(left_start + x * CELLSIZE, window.height);
            glEnd();
            glBegin(GL_LINES);
            glVertex2d(0, bottom_start + y * CELLSIZE);
            glVertex2d(window.width, bottom_start + y * CELLSIZE);
            glEnd();
        }
    }
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
    window.resize(w, h);
    expandWorld(window.xCellDemand(), window.yCellDemand());
}

void mouse(int button, int state, int x_coord, int y_coord) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            std::cout << x_coord << " " << y_coord << std::endl;
            glutPostRedisplay();
        }
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    initWorld(window.xCellDemand(), window.yCellDemand());
}
