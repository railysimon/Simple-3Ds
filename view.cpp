#include "view.h"

View::View(QWidget *parent): QGLWidget(parent), rotate_x(0), rotate_y(0)
{
    this->setCursor(Qt::PointingHandCursor);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

View::~View()
{

}

void View::Cube(int &color)
{
    float brush = (float) color / 100;

    glBegin(GL_QUADS); // top
        glColor3f(1-brush, brush, brush);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 1, 1);
        glVertex3f(0, 1, 1);
    glEnd();

    glBegin(GL_QUADS); // bottom
        glColor3f(brush, 1-brush, brush);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
        glVertex3f(0, 0, 1);
    glEnd();

    glBegin(GL_QUADS); // left
        glColor3f(brush, brush, 1-brush);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 1, 1);
        glVertex3f(0, 0, 1);
    glEnd();

    glBegin(GL_QUADS); // right
        glColor3f(1-brush, 1-brush, brush);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, 0);
    glEnd();

    glBegin(GL_QUADS); // front
        glColor3f(1-brush, brush, 1-brush);
        glVertex3f(0, 0, 1);
        glVertex3f(0, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 0, 1);
    glEnd();

    glBegin(GL_QUADS); // back
        glColor3f(brush, 1-brush, 1-brush);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 0, 0);
    glEnd();
}

void View::Piramida(int &color)
{
     float brush = (float) color / 100;

    glBegin(GL_TRIANGLE_FAN);
            glColor3f(1-brush, brush, brush);
            glVertex3f(0, 1, 0);
            glVertex3f(-1, -1, 1);
            glVertex3f(1, -1, 1);
            glColor3f(brush, 1-brush, brush);
            glVertex3f(1, -1, -1);
            glColor3f(brush, brush, 1-brush);
            glVertex3f(-1, -1, -1);
            glColor3f(1-brush, 1-brush, brush);
            glVertex3f(-1, -1, 1);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(1-brush, brush, 1-brush);
            glVertex3f(-1, -1, 1);
            glVertex3f(1, -1, 1);
            glVertex3f(1, -1, -1);
            glVertex3f(-1, -1, -1);
        glEnd();

}

QSize View::sizeHint() const
{
    return QSize(500, 500);
}

void View::initializeGL()
{
    qglClearColor(Qt::gray);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
}

void View::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glOrtho(-2, 2, -2, 2, -7, 7);
}

void View::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float step = (float) post.scale / 100;
    glScalef(1 + step, 1 + step, 1 + step);

    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);

    switch (post.choice)
    {
        case 1: { Cube(post.color); break; }
        case 2: { Piramida(post.color); break; }
    }
}

void View::mousePressEvent(QMouseEvent *ev)
{
    point = ev->pos();
}

void View::mouseMoveEvent(QMouseEvent *ev)
{
    rotate_x += (180 * ((GLfloat)ev->y() - (GLfloat)point.y()) / height());
    rotate_y += (180 * ((GLfloat)ev->x() - (GLfloat)point.x()) / width());

    point = ev->pos();
    updateGL();
}

void View::RecieveData(Data &pack)
{
    post = pack;
    updateGL();
}
