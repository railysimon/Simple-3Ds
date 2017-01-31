#include "shape.h"

Shape::Shape()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//    glRotatef(rotate_x, 1, 0, 0);
//    glRotatef(rotate_y, 0, 1, 0);

    glBegin(GL_QUADS); // top
        glColor3f(0.22, 0.22, 0.22);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 1, 1);
        glVertex3f(0, 1, 1);
    glEnd();

    glBegin(GL_QUADS); // bottom
        glColor3f(0.45, 0.1, 0.8);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
        glVertex3f(0, 0, 1);
    glEnd();

    glBegin(GL_QUADS); // left
        glColor3f(0.1, 0.65, 0.3);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 1, 1);
        glVertex3f(0, 0, 1);
    glEnd();

    glBegin(GL_QUADS); // right
        glColor3f(0.1, 0.3, 0.85);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, 0);
    glEnd();

    glBegin(GL_QUADS); // front
        glColor3f(0.7, 0.3, 0.1);
        glVertex3f(0, 0, 1);
        glVertex3f(0, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 0, 1);
    glEnd();

    glBegin(GL_QUADS); // back
        glColor3f(0.6, 0.2, 0.8);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 0, 0);
    glEnd();

}
