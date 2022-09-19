#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*, int)),
            this, SLOT(treeItemChanged(QTreeWidgetItem*,int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    // 第一个分组
    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    group1->setCheckState(0, Qt::Unchecked);

    // 第一个单选按钮
    QTreeWidgetItem *subItem11 = new QTreeWidgetItem(group1);
    subItem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    subItem11->setText(0, "subItem11");
    subItem11->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem12 = new QTreeWidgetItem(group1);
    subItem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    subItem12->setText(0, "subItem12");
    subItem12->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem13 = new QTreeWidgetItem(group1);
    subItem13->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    subItem13->setText(0, "subItem13");
    subItem13->setCheckState(0, Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem *item, int column)
{
    QString itemText = item->text(0);
    // 如果此节点被选中
    if (Qt::Checked == item->checkState(0))
    {
        int count = item->childCount();
        // 判断 此item是否有子节点
        if (count > 0)
        {
            // 有子节点的话将下面的所有子节点全部变成选中状态
            for (int i=0; i<count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Checked);
            }
        }
        else
        {
            // item没有子节点
            updateParentItem(item);
        }
    }
    // 如果此节点未被选中
    else if (Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        // 判断 此item是否有子节点
        if (count > 0)
        {
            // 有子节点的话将下面的所有子节点全部变成未选中状态
            for (int i=0; i<count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Unchecked);
            }
        }
        else
        {
            // item没有子节点 对父节点进行处理
            updateParentItem(item);
        }
    }
}

void Widget::updateParentItem(QTreeWidgetItem* item)
{
    QTreeWidgetItem *parent = item->parent();
    if (parent == NULL)
    {
        return;
    }

    // 选中的子节点个数
    int selectedCount = 0;
    int childCount = parent->childCount();
    for (int i=0; i<childCount; i++)
    {
        QTreeWidgetItem *childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked)
        {
            selectedCount++;
        }
    }

    if (selectedCount <= 0)
    {
        // 所有的子节点都是未选中 将父节点设置为未选中
        parent->setCheckState(0, Qt::Unchecked);
    }
    else if (selectedCount > 0 && selectedCount < childCount)
    {
        // 部分子节点被选中
        parent->setCheckState(0, Qt::PartiallyChecked);
    }
    else if (selectedCount == childCount)
    {
        // 所有节点都是选中状态
        parent->setCheckState(0, Qt::Checked);
    }
}





















