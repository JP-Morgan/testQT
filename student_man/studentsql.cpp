
#include "studentsql.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <qsqlquery.h>
StudentSql::StudentSql(QObject *parent)
    : QObject{parent}
{

    //打印可用的数据库
    qDebug() << QSqlDatabase::drivers();
    //    链接数据库
    MySql_link();
//    StuInfo s;
//    s.name = "小米";
//    //添加学生test
//    AddStudent(s);
    //查询页数
    FindPageNumber(2,3);
    //删除学生
    DeletStudent(4);
    //清空学生数据
    ClearStudent();

}
//链接数据库
QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL","student");
void StudentSql::MySql_link(QString HostName, QString UserName, QString Password, QString DatabaseName, int Port)
{

    //链接数据库
    db1.setHostName(HostName);//数据库服务器ip
    db1.setUserName(UserName);//数据库用户名
    db1.setPassword(Password);//密码
    db1.setDatabaseName(DatabaseName);//使用那个数据库
    db1.setPort(Port);

    if(!db1.open())//开失败
    {
        QMessageBox::warning(nullptr,"错误",db1.lastError().text());

        return;
    }
    qDebug()<<"成功";
}

//获取学生数量
quint32 StudentSql::FindStudents()
{
    //findstudent是一个迭代器，用于遍历学生信息。
    //value(0)表示获取该迭代器指向的学生的第一个值，这里假设学生的信息是以一系列值的形式存储的。
    //toUInt()是一个函数，用于将字符串转换为无符号整数（unsigned integer）。这里它用于将学生信息的第一个值转换为无符号整数。
    QSqlQuery findstudent(db1);
    findstudent.exec("SELECT COUNT(id) FROM student;");
    quint32 sum = 0;
    while(findstudent.next())
    {
        sum = findstudent.value(0).toUInt();
    }
    return sum;
}

//查询学生第几页数据
QList<StuInfo> StudentSql::FindPageNumber(quint32 page, quint32 uiCnt)
{
    QList<StuInfo> Numder;
    QSqlQuery findpagenumber(db1);
    QString sql = "SELECT * FROM student ORDER BY id LIMIT ? OFFSET ?;";  
    findpagenumber.prepare(sql);  
    findpagenumber.addBindValue(uiCnt);  
    findpagenumber.addBindValue(page*uiCnt);  
    findpagenumber.exec();
    StuInfo info;
    while(findpagenumber.next())
    {
        if (!findpagenumber.isValid()) {
            qDebug() << "Error in query";
            break;
        }
        info.id = findpagenumber.value(0).toUInt();
        info.name = findpagenumber.value(1).toString();
        info.age = findpagenumber.value(2).toUInt();
        info.grade = findpagenumber.value(3).toUInt();
        info.myclass = findpagenumber.value(4).toUInt();
        info.studentid = findpagenumber.value(5).toUInt();
        info.phone = findpagenumber.value(6).toString();
        info.wechat = findpagenumber.value(7).toString();
        Numder.push_back(info);
    }
    return Numder;
}

//修改学生信息
void StudentSql::ModifyInfo(StuInfo info)
{
    QSqlQuery addstudent(db1);
    //我这种发方法可以防止Sql注入:nam......
    QString Sql = QString("UPDATE student SET name = ? WHERE id = ?;");
    addstudent.prepare(Sql);
    addstudent.addBindValue(info.name);
    addstudent.addBindValue(info.id);
    addstudent.exec();
}
//删除学生
bool StudentSql::DeletStudent(int id)
{
    QSqlQuery Delet(db1);
    QString sql = "DELETE FROM student WHERE id = ?;";
    Delet.prepare(sql);
    Delet.addBindValue(id);
    if(Delet.exec()) {
        return true;
    } else {
        qDebug() << Delet.lastError();
        return false;
    }
}


//添加学生
bool StudentSql::AddStudent(StuInfo info)
{
    QSqlQuery addstudent(db1);
    //我这种发方法可以防止Sql注入:nam......
    QString Sql = QString("INSERT INTO student (name, age, grade, class, studentid, phone, wechat) VALUES (:name, :age, :grade, :class, :student, :phone, :wechat);");
    addstudent.prepare(Sql);
    addstudent.bindValue(":name", info.name);
    addstudent.bindValue(":age", info.age);
    addstudent.bindValue(":grade", info.grade);
    addstudent.bindValue(":class", info.myclass);
    addstudent.bindValue(":student", info.studentid);
    addstudent.bindValue(":phone", info.phone);
    addstudent.bindValue(":wechat", info.wechat);
    addstudent.exec();

    if (addstudent.exec(Sql)) {
        return true; // 插入成功
    } else {
        qDebug() << "Insert failed:" << addstudent.lastError();
        return false; // 插入失败
    }
}
//清空学生数据
void StudentSql::ClearStudent()
{

    QSqlQuery Delet(db1);

    QString sql = "DELETE FROM student;";

    Delet.prepare(sql);



    if(Delet.exec()) {

        QMessageBox::information(nullptr, "提示", "学生数据已清空。");
    } else {

        qDebug() << Delet.lastError();

        QMessageBox::warning(nullptr, "错误", "清空学生数据时发生错误：" + Delet.lastError().text());
    }

}


