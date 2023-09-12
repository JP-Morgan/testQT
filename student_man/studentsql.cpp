
#include "studentsql.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <qsqlquery.h>
StudentSql * StudentSql::ptrstuSql = nullptr;
StudentSql::StudentSql(QObject *parent)
    : QObject{parent}
{

    //打印可用的数据库
    qDebug() << QSqlDatabase::drivers();
    //    链接数据库
    MySql_link();

//    StuInfo s;

//    s.name = "小王";
//    s.id = 2;
//    //添加学生test
//    AddStudent(s);

    //查询页数
    //FindPageNumber(2,3);
    //删除学生
    //DeletStudent(4);
    //清空学生数据
    //ClearStudent();
    //删除数学
    //DeletStudent(1);
//    ModifyInfo(s);
//    userInfo us;
//    auto l = FindAllUser();
//    qDebug() << FindUserTrueFalse("us");
//    userInfo s;
//    s.aut = "us";
//    s.username = "us";
//    s.password = "543210";
//    updateUser(s);

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
            qDebug() << "错误";
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
//查询所有用户
QList<userInfo> StudentSql::FindAllUser()
{
    QList<userInfo> Numder;
    QSqlQuery studentsql(db1);
    QString sql = "SELECT * FROM username;";
    studentsql.prepare(sql);
    studentsql.exec();
    userInfo info;
    while(studentsql.next())
    {
        if (!studentsql.isValid()) {
            qDebug() << "错误";
            break;
        }
        info.aut = studentsql.value(0).toString();
        info.password = studentsql.value(1).toString();
        info.username = studentsql.value(2).toString();
        Numder.push_back(info);
    }
    return Numder;
}
//查询用户是否存在
bool StudentSql::FindUserTrueFalse(QString strUser)
{

    if (!db1.isOpen())
    {
        qDebug() << "Database is not open.";
        return false;
    }
    QSqlQuery findusertruefalse(db1);
    QString sql = "SELECT * FROM username WHERE username = :username;";
    findusertruefalse.prepare(sql);
    findusertruefalse.bindValue(":username", strUser);
    if (findusertruefalse.exec()) {
        if (findusertruefalse.size() > 0) {
            return true; // User exists
        } else {
            return false; // User doesn't exist
        }
    } else {
        qDebug() << "未能执行查询：" << findusertruefalse.lastError();
        return false;

    }
}
//更新用户信息
void StudentSql::updateUser(userInfo info)
{
    QSqlQuery updateUser(db1);
    QString sql = QString("UPDATE username SET password = :password, auth = :auth WHERE username = :username;");

    if (!updateUser.prepare(sql)) {
        qDebug() << "updateUser准备查询时出错： " << updateUser.lastError();
        return;
    }

    updateUser.bindValue(":password", info.password);
    updateUser.bindValue(":auth", info.aut);
    updateUser.bindValue(":username", info.username);

    if (!updateUser.exec()) {
        qDebug() << "updateUser执行查询时出错： " << updateUser.lastError();
    }
}

//修改学生信息
void StudentSql::ModifyInfo(StuInfo info)
{
    QSqlQuery modifyinfo(db1);
    QString sql = QString("UPDATE student SET name = ?, age = ?, grade = ?, class = ?, studentid = ?, phone = ?, wechat = ? WHERE id = ?;");

    if (!modifyinfo.prepare(sql)) {
        qDebug() << "错误: " << modifyinfo.lastError();
        return;
    }

    modifyinfo.addBindValue(info.name);
    modifyinfo.addBindValue(info.age);
    modifyinfo.addBindValue(info.grade);
    modifyinfo.addBindValue(info.myclass);
    modifyinfo.addBindValue(info.studentid);
    modifyinfo.addBindValue(info.phone);
    modifyinfo.addBindValue(info.wechat);
    modifyinfo.addBindValue(info.id);

    if (!modifyinfo.exec()) {
        qDebug() << "错误: " << modifyinfo.lastError();
    }
}
//删除用户
void StudentSql::DeletUser(QString deletUsername)
{
    QSqlQuery deletser(db1);
    QString sql = "DELETE FROM username WHERE username = ?;";
    deletser.prepare(sql);
    deletser.addBindValue(deletUsername);
    deletser.exec();
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

    if (addstudent.exec(Sql)) {
        return true; // 插入成功
    } else {
        qDebug() << "插入失败:" << addstudent.lastError();
        return false; // 插入失败
    }
}
//增加单个用户
bool StudentSql::AddOnlyUser(userInfo info)
{
    QSqlQuery addonlyuser(db1);
    //我这种发方法可以防止Sql注入:nam......
    QString Sql = QString("INSERT INTO username (username, password, auth ) VALUES (:username, :password, :auth);");
    addonlyuser.prepare(Sql);
    addonlyuser.bindValue(":username", info.username);
    addonlyuser.bindValue(":password", info.password);
    addonlyuser.bindValue(":auth", info.aut);

    if (addonlyuser.exec()) {
        return true; // 添加成功
    } else {
        qDebug() << "添加失败:" << addonlyuser.lastError();
        return false; // 添加失败
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


