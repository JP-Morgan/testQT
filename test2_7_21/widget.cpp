
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("大哥");
    a1.setParent(this);
    a1.setText("close");
    a1.move(100,100);
    //指针类型
    a2 = new QPushButton(this);
    a2->setText("123");

    connect(&a1,&QPushButton::pressed/*pressed 信号在按钮被按下时触发。*/,this,&Widget::close);

    //自定义槽函数
    //切换窗口
    a3.setParent(this);
    a3.setText("大哥");
    a3.move(50,50);
    //win1.show();
    //实现主窗口切换到子窗口
    connect(&a3,QPushButton::released/*released 信号在按钮被释放（松开）时触发。*/,this,&Widget::Swap);

    //处理子窗口的信号
   // connect(&win1,Subwidget::/*子窗口点击切换窗口的按钮信号接收到*/mySignal,this,&Widget::dealSib);
    resize(400,300);

    void (Subwidget::*funSignal)() = Subwidget::mySignal;
    connect(&win1,funSignal,this,&Widget::dealSib);


    void (Subwidget::*testSignal)(int ,QString) = Subwidget::mySignal;
    connect(&win1,testSignal,this,&Widget::dealSlot);
}
void Widget::Swap()
{//子窗口显示
    win1.show();
    //主隐藏
    this->hide();

}

void Widget::dealSib()
{
    this->show();
    win1.hide();
}

void Widget::dealSlot(int a, QString str)
{
    qDebug()<<a<<str;
}
Widget::~Widget()
{
    delete ui;
}




