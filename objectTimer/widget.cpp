
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix("F:\\代码\\GitHub\\testQT\\objectTimer\\pix\\1.jpg");
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event())
{
    if(event()->timerId() != mytimerid)
    //if(event->timerId() != mytimerid)
    {return;}
    QString path("F:\\代码\\GitHub\\testQT\\objectTimer\\pix\\");
    path += QString::number(picID);
    path += ".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picID++;
    if(picID == 5)
    {
        picID = 1;
    }
}

void Widget::on_pushButton_clicked()
{
    // 开启定时器，返回定时器的编号
    mytimerid = this->startTimer(TIMEOUT);
}


void Widget::on_stopButton_clicked()
{
    this->killTimer(mytimerid);
}

