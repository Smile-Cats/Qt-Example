#include "content.h"

#include <QApplication>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("AR PL KaitiM GB", 12);
    a.setFont(font);

    //新建一个水平分割窗对象 作为主布局框
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setOpaqueResize(true);
    // 新建一个list 并插入splitterMain对象
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0, QObject::tr("基本信息"));
    list->insertItem(1, QObject::tr("联系方式"));
    list->insertItem(2, QObject::tr("详细资料"));

    // 将Content堆栈窗插入 水平分割窗 splitterMain
    Content *content = new Content(splitterMain);
    QObject::connect(list, SIGNAL(currentRowChanged(int)), content->stack,
                     SLOT(setCurrentIndex(int)));

    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());
    splitterMain->show();

    return a.exec();





}
