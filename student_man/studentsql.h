
#ifndef STUDENTSQL_H
#define STUDENTSQL_H


#include <QObject>
struct StuInfo
{
    int id;
    QString name;
    quint8 age;
    quint16 grade;
    quint16 myclass;
    quint32 studentid;
    QString phone;
    QString wechat;
};
struct userInfo
{
    QString username;
    QString password;
    QString aut;
};

class StudentSql : public QObject
{
    Q_OBJECT
public:
    explicit StudentSql(QObject *parent = nullptr);
    //链接数据库
    void MySql_link(QString HostName = "127.0.0.1", QString UserName = "root",QString Password = "Morgan2004",QString DatabaseName = "data",int Port = 3306);
    //查询学生数量
    quint32 FindStudents();

    //查询学生第几页数据
    QList<StuInfo> FindPageNumber(quint32 page,quint32 uiCnt);

    //查询所有用户
    QList<userInfo> FindAllUser();

    //查询用户是否存在
    bool FindUserTrueFalse(QString strUser);

    //修改权限
    void ModifyPower(QString str);

    //修改学生信息
    void ModifyInfo(StuInfo info);

    //删除单个用户
    void DeletUser(QString deletUsername);

    //删除学生
    bool DeletStudent(int id);

    //增加学生
    bool AddStudent(StuInfo info);

    //增加单个用户
    void AddOnlyUser(userInfo info);

    //清空学生列表
    void ClearStudent();

signals:

};

#endif // STUDENTSQL_H
