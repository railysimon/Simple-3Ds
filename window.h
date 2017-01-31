#ifndef WINDOW_H
#define WINDOW_H

#include "view.h"
#include "package.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QSlider>

class View;

class Window : public QDialog
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

    View *scene;

private:
        Data package;

        void Layout();
        QLabel *label(QString title);
        QListWidget *list();

        QSlider *slider(int min, int max, int pos);
        QSlider *color, *scale;

        QPushButton *button(QString title);

private slots:
            void ListClicked(QListWidgetItem*);
            void ButtonClicked();

signals:
            void SendData(Data &pack);
};

#endif // WINDOW_H
