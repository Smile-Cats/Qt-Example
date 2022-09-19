#include "content.h"
#include <QHBoxLayout>

Content::Content(QWidget *parent)
    : QFrame(parent)
{
    stack = new QStackedWidget(this); //新建堆栈窗口控件
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised); //设置堆栈窗口样式
    baseInfo = new BaseInfo();
    contact = new Contact();
    detail = new Detail();
    // 将基本信息、联系方式、详细信息窗口加入堆栈窗口中
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    AmendBtn = new QPushButton(tr("修改"));
    CloseBtn = new QPushButton(tr("关闭"));
    // 新建水平布局 用来部署按钮
    QHBoxLayout *BtnLayout = new QHBoxLayout();
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);

    //新建布局用于 部署堆栈窗口和按钮组
    QVBoxLayout *RightLayout = new QVBoxLayout(this);
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);
    RightLayout->addWidget(stack);
    RightLayout->addLayout(BtnLayout);

}

Content::~Content()
{
}

