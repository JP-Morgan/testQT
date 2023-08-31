
#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //打印可用的数据库
    qDebug() << QSqlDatabase::drivers();
    //查看错误信息
//    qDebug() << db.lastError().text();
//    链接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //链接数据库
    db.setHostName("localhost");//数据库服务器ip
    db.setUserName("root");//数据库用户名
    db.setPassword("Morgan2004");//密码
    db.setDatabaseName("qwe");//使用那个数据库
    db.setPort(3306);

    if(!db.open())//开失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    //操作sql语句
    QSqlQuery query;


}

Widget::~Widget()
{
    delete ui;
}


