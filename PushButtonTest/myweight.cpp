#include "myweight.h"
#include <qapplication.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qlabel.h>
#include <qdatetime.h>

MyWeight::MyWeight(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(400, 120);
    setMaximumSize(400, 120);

    QPushButton *quit = new QPushButton("Quit", this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 12, QFont::Bold));
    connect(quit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    QLabel * datelabel = new QLabel(this);
    QDateTime * datetime = new QDateTime(QDateTime::currentDateTime());
    datelabel->setText(datetime->date().toString());
    datelabel->setGeometry(200, 40, 110, 30);
}

MyWeight::~MyWeight()
{
}

