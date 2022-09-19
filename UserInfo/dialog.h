#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    // 左侧
    QLabel *UserNameLabel;
    QLabel *NameLabel;
    QLabel *SexLabel;
    QLabel *DepartmentLabel;
    QLabel *AgeLabel;
    QLabel *OtherLabel;
    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexComboBox;
    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout;

    //右侧
    QLabel *HeadLabel; //右上角部分
    QLabel *HeadIconLabel;
    QPushButton *UpdateHeadBtn;
    QHBoxLayout *TopRightLayout;

    QLabel *IntroductionLabel;
    QTextEdit *introductionTextEdit;
    QVBoxLayout *RightLayout;

    // 底部
    QPushButton *OkBtn;
    QPushButton *CancelBtn;
    QHBoxLayout *ButtomLayout;
};
#endif // DIALOG_H
