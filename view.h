#ifndef VIEW_H
#define VIEW_H

#include "package.h"

#include <QGLWidget>
#include <QMouseEvent>

class View : public QGLWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = 0);
    ~View();

    void Cube(int &color);
    void Piramida(int &color);
    virtual QSize sizeHint() const;

protected:
            virtual void initializeGL();
            virtual void resizeGL(int nWidth, int nHeight);
            virtual void paintGL();

            virtual void mousePressEvent(QMouseEvent *ev);
            virtual void mouseMoveEvent(QMouseEvent *ev);
private:
        QPoint point;
        GLfloat rotate_x, rotate_y;

        Data post;

public slots:
            void RecieveData(Data &pack);

};


#endif // VIEW_H
