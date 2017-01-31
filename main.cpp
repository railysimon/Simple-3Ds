#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Window window;
    window.show();

    return application.exec();
}
