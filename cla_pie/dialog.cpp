#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    bool ok;
    QString tempStr;
    QString valueString = ui->lineEdit->text();
    int valueInt = valueString.toInt(&ok);
    double area = valueInt*valueInt*3.14;
    ui->lineEdit_2->setText(tempStr.setNum(area));
}

