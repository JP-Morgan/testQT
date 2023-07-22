
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    TImer = new QTimer;
    QImage img;

    img.load("F:\\代码\\GitHub\\testQT\\objectTimer\\pix\\1.jpg");
    //显示
    ui->label->setPixmap(QPixmap::fromImage(img));

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{
    TImer->start(TIMEOUT);
}

