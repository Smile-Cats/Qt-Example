#include "myweight.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>
#include <qpushbutton.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget();
    window->resize(320,240);
    window->show();

    QPushButton * button = new QPushButton("Press me", window);
    button->move(100, 100);
    button->show();
    return a.exec();
}
