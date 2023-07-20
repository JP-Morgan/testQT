
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_ageChanged(size_t value)
{

    ui->plainTextEdit->appendPlainText("数据修改");
}

void Widget::do_spinChanged(szie_t arg1)
{

}


