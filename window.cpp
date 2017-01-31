#include "window.h"

Window::Window(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(710, 500);

    scene = new View;
    scene->setFixedWidth(500);
    connect(this, SIGNAL(SendData(Data&)), scene, SLOT(RecieveData(Data&)));

    Layout();
}

Window::~Window()
{

}

void Window::Layout()
{
    QLabel *title1 = label("Choose figure:");
    QListWidget *lst = list();
    color = slider(1, 100, 60);
    QLabel *title2 = label("Color:");
    QLabel *title3 = label("Scale:");
    scale = slider(0, 200, 0);
    QPushButton *okay = button("Create");

    QVBoxLayout *menu = new QVBoxLayout;
    menu->setAlignment(Qt::AlignRight | Qt::AlignTop);
    menu->addWidget(title1);
    menu->addWidget(lst);
    menu->addWidget(title2);
    menu->addWidget(color);
    menu->addWidget(title3);
    menu->addWidget(scale);
    menu->addWidget(okay);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(scene);
    lay->addLayout(menu);

    this->setLayout(lay);
}

QLabel *Window::label(QString title)
{
    QLabel *lbl = new QLabel(title);
    lbl->setFixedWidth(180);
    lbl->setFont(QFont("Ubuntu", 10, 0));

    return lbl;
}

QListWidget *Window::list()
{
    QListWidget *lst = new QListWidget;
    lst->setFixedWidth(180);
    lst->setCursor(Qt::PointingHandCursor);
    QListWidgetItem *item;

    QString names[] = {"Cube", "Piramida"};

    for(int i=0; i<2; i++)
    {
        item = new QListWidgetItem(names[i], lst);
    }

    connect(lst, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ListClicked(QListWidgetItem*)));

    return lst;
}

QSlider *Window::slider(int min, int max, int pos)
{
    QSlider *sl = new QSlider;
    sl->setFixedSize(180, 60);
    sl->setOrientation(Qt::Horizontal);
    sl->setCursor(Qt::PointingHandCursor);
    sl->setMaximum(max);
    sl->setMinimum(min);
    sl->setValue(pos);

    return sl;
}

QPushButton *Window::button(QString title)
{
    QPushButton *btn = new QPushButton(title);
    btn->setFixedWidth(180);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setFont(QFont("Ubuntu", 10, QFont::Bold));

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(ButtonClicked()));

    return btn;
}

void Window::ListClicked(QListWidgetItem *item)
{
    QString names[] = {"Cube", "Piramida"};

    for(int i=0; i<2; i++)
    {
        if(item->text() == names[i])
        {
            package.choice = i+1;
            break;
        }
    }
}

void Window::ButtonClicked()
{
    package.color = color->value();
    package.scale = scale->value();
    emit SendData(package);
}
