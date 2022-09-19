#include "baseinfo.h"

BaseInfo::BaseInfo(QWidget *parent)
    : QWidget{parent}
{
        /***********左侧**********************/
        UserNameLabel = new QLabel(tr("用户名："));
        UserNameLineEdit = new QLineEdit();
        NameLabel = new QLabel(tr("姓名："));
        NameLineEdit = new QLineEdit();
        SexLabel = new QLabel(tr("性别："));
        SexComboBox = new QComboBox();
        SexComboBox->addItem(tr("女"));
        SexComboBox->addItem(tr("男"));
        DepartmentLabel = new QLabel(tr("部门："));
        DepartmentTextEdit = new QTextEdit();
        AgeLabel = new QLabel(tr("年龄："));
        AgeLineEdit = new QLineEdit();
        OtherLabel = new QLabel(tr("备注："));
        OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);//设置部件样式 形状|阴影

        LeftLayout = new QGridLayout();
        LeftLayout->addWidget(UserNameLabel, 0, 0); // 用户名 放在 第一行 第一列
        LeftLayout->addWidget(UserNameLineEdit,0,1); //放在第一行 第二列

        LeftLayout->addWidget(NameLabel, 1, 0); // 第二行 第一列
        LeftLayout->addWidget(NameLineEdit, 1, 1);

        LeftLayout->addWidget(SexLabel, 2, 0);
        LeftLayout->addWidget(SexComboBox, 2, 1);

        LeftLayout->addWidget(DepartmentLabel, 3, 0);
        LeftLayout->addWidget(DepartmentTextEdit, 3, 1);

        LeftLayout->addWidget(AgeLabel, 4, 0);
        LeftLayout->addWidget(AgeLineEdit, 4, 1);

        //位置在第4行第1列 横向占据1个单元格 纵向占据两个单元格
        LeftLayout->addWidget(OtherLabel, 5, 0, 1, 2);

        LeftLayout->setColumnStretch(0,1); // 设置第一列长度比例为1
        LeftLayout->setColumnStretch(1,3); // 设置第二列长度比例为3

        /*************右侧********************/
        HeadLabel = new QLabel(tr("头像："));
        HeadIconLabel = new QLabel();
        QPixmap icon("D:/Demo/Learn-Qt/UserInfo/logo.png");
        HeadIconLabel->setPixmap(icon); // 将图像添加到QLabel中
        HeadIconLabel->resize(icon.width(), icon.height());
        UpdateHeadBtn = new QPushButton(tr("更新"));

        TopRightLayout = new QHBoxLayout();
        TopRightLayout->setSpacing(20);
        TopRightLayout->addWidget(HeadLabel);
        TopRightLayout->addWidget(HeadIconLabel);
        TopRightLayout->addWidget(UpdateHeadBtn);

        IntroductionLabel = new QLabel(tr("个人说明：")); //右下角部分
        IntroductionTextEdit = new QTextEdit();

        RightLayout = new QVBoxLayout();
        RightLayout->setMargin(10);
        RightLayout->addLayout(TopRightLayout);
        RightLayout->addWidget(IntroductionLabel);
        RightLayout->addWidget(IntroductionTextEdit);

        /*------------------底部------------------*/
        OkBtn = new QPushButton(tr("确定"));
        CancelBtn = new QPushButton(tr("取消"));

        ButtomLayout = new QHBoxLayout();
        ButtomLayout->addStretch();
        ButtomLayout->addWidget(OkBtn);
        ButtomLayout->addWidget(CancelBtn);

        /*------------------------------------*/
        QGridLayout *mainLayout = new QGridLayout(this);
        mainLayout->setMargin(15); // 设置外边距为15
        mainLayout->setSpacing(10); //设置内部空格10
        mainLayout->addLayout(LeftLayout, 0, 0); //将LeftLayout放入第一行第一列
        mainLayout->addLayout(RightLayout, 0, 1);
        mainLayout->addLayout(ButtomLayout, 1, 0, 1, 2); // Buttom占据一行 两列
        mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}
