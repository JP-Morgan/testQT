
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //链接信号与槽—谁发送信号 发出什么信号 谁处理信号 如何处理
    //宏的方式
    connect(ui->lineEdit,SIGNAL(returnPressed()/*回车*/),this,SLOT(on_pushButton_clicked()));
    //引用的方式
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Widget::on_pushButton_3_clicked);
    //
    connect(ui->pushButton_2,&QPushButton::clicked,[this]()
    {
        QMessageBox::information(/*父类*/this,"信息","浏览");
    });
}


Widget::~Widget()
{
    delete ui;


}



void Widget::on_pushButton_clicked()
{
    //获取lineedit数据
    QString program = ui->lineEdit->text();
    //创建process对象
    QProcess *myProcess = new QProcess(this);
    //这一行代码使用之前获取的 program 变量的值，也就是用户在 lineEdit 中输入的程序名称
    //通过调用 start() 函数来启动该程序。这将导致操作系统在后台运行该程序。
    myProcess->start(program);
}


void Widget::on_pushButton_3_clicked()
{
    this->close();
}

