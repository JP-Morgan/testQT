
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timerId = this->startTimer(1000);//每一毫秒触发一次定时器
//    this->killTimer(); MyButton *pushButton;
//    connect(ui->pushButton, &Mybutton::clicked
    connect(ui->pushButton, &Mybutton::clicked,
            [=]()
            {
                qDebug() << "按钮被按下";
            }

            );
}

Widget::~Widget()
{
    delete ui;
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<< event->key();
    if(event->key()==Qt::Key_A)
    {
        qDebug()<<"A";
    }
}

void Widget::timerEvent(QTimerEvent *event)
{
    static int sec =0;
    ui->label->setText(QString("<center><h1>time out:(%1)</h1></center>").arg(sec++));
    if(sec == 4)
    {
        this->killTimer(this->timerId);
//      this->close();
    }
}
