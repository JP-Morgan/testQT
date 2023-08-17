
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //仅限于当期前QLabel
    ui->label->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:rgb(255,150,234)"
                             "background-image:url(:/new/prefix1/im/Frame.jpg)"
                             "}");

    //用与全部QLabel
    this->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:red"
                             "}");

}

Widget::~Widget()
{
    delete ui;
}


