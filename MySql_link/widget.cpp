
#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
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
//    创建数据库
//    QSqlQuery query;
//    query.exec("create table student(id int primary key auto_increment, name varchar(255), age int, score int);");

    //插入数据
    QSqlQuery insert;
    insert.exec("insert into student(id, name, age, score) values(1, 'mike', 18, 20);");
    insert.exec("insert into student(id, name, age, score) values(2, 'lucy', 22, 90);");
//    批量插入
//    odbc风格
//    预处理语句 ？相当于站位符号
//    insert.exec("insert into student(name, age, score) values(?,?,?);");
//    //给字段设置内容 list
//    QVariantList namelist;
//    namelist<< "xiaoming" <<"xhaownag" << "xiaoli";
//    QVariantList agelist;
//    agelist<< 12 << 21 << 33;
//    QVariantList scorelist;
//    scorelist << 99 << 77 <<100;

//    //给字段绑定相应的值
//    insert.addBindValue(namelist);
//    insert.addBindValue(agelist);
//    insert.addBindValue(scorelist);
//    //执行预处理
//    insert.execBatch();
//    //建议封装使用


    //oracle风格_站位符改变->:任意名字(建议为字段名)
    insert.prepare("insert into student(name, age, score) values(:name, :age, :score);");
    //给字段设置内容 list
    QVariantList namelist;
    namelist<< "xiaowu" <<"zhangfan" << "lilong";
    QVariantList agelist;
    agelist<< 22 << 31 << 73;
    QVariantList scorelist;
    scorelist << 100 << 79 <<80;
    //给字段绑定
    insert.bindValue(":name",namelist);
    insert.bindValue(":age",agelist);
    insert.bindValue(":score",scorelist);
    //执行预处理命令
    insert.execBatch();
/*
    //如果有两个数据库的话要在addDatabase("QMYSQL"后面加“任意一个定义名建议用数据库名”);
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL","test");
    db1.setHostName("localhost");//数据库服务器ip
    db1.setUserName("root");//数据库用户名
    db1.setPassword("Morgan2004");//密码
    db1.setDatabaseName("test");//使用那个数据库
    db1.setPort(3306);

    if(!db1.open())//开失败
    {
        QMessageBox::warning(this,"错误",db1.lastError().text());
        return;
    }

    QSqlQuery query1(db1);
    query1.exec("create table student(id int primary key auto_increment, name varchar(255), age int, score int);");
*/

     QSqlQuery query;
    query.exec("select * from student where name = 'lilong'");
     while(query.next())//一行一行的遍历
    {
        //取出当前行的内容·
        qDebug() << query.value("id").toInt()
                 << query.value("naem").toString()
                 << query.value("age").toInt()
                 << query.value("score").toInt();
    }
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_delete_2_clicked()
{
    //获取类容
    QString txt = ui->lineEdit->text();

    QString sql = QString("delete from student where name = '%1'").arg(txt);
    //开启一个事务
    QSqlDatabase::/*可以获取当前操作的数据库*/database().transaction();
    QSqlQuery Delete;
    Delete.exec(sql);

}


void Widget::on_Confir_delete_clicked()
{
//    确定删除
    QSqlDatabase::/*可以获取当前操作的数据库*/database().commit();
}


void Widget::on_pushButton_2_clicked()
{
//    回滚，撤销
    QSqlDatabase::/*可以获取当前操作的数据库*/database().rollback();
}

