#include "dialog.h"

#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("StackedWidget"));
    list = new QListWidget(this); // 新建QListWidget控件
    // 在QListWidget控件里 插入3个条目作为选项
    list->insertItem(0, tr("window1"));
    list->insertItem(1, tr("window2"));
    list->insertItem(2, tr("window3"));

    // 创建3个QLabel标签对象
    label1 = new QLabel(tr("windowTest1"));
    label2 = new QLabel(tr("windowTest2"));
    label3 = new QLabel(tr("windowTest3"));

    // 新建QStackWidget堆栈窗体对象 并将标签插入窗体中 此时stack有三个窗体分别为label1、label2、lebel3
    stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    // 对整个对话框进行布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5); // 设定对话框边据为5
    mainLayout->setSpacing(5); // 设定对话框间距为5
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack, 0 ,Qt::AlignHCenter);
    mainLayout->setStretchFactor(list, 1); // 设定可伸缩控件
    mainLayout->setStretchFactor(stack, 3);
    // 根据list的变化，切换stack的窗体变化
    connect(list,SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

Dialog::~Dialog()
{
}

