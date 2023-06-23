#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)//以便正确地构造父类部件。
    , ui(new Ui::Widget)//Ui::Widget是一个自动生成的类，用于创建和管理窗口部件的用户界面。
{
    //ui->setupUi(this)，它是由Qt的用户界面设计器生成的一个函数。
    //这个函数将设置用户界面的各种元素（如按钮、文本框、标签等）并将它们添加到窗口部件中。
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
