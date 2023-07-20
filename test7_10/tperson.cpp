
#include "tperson.h"

TPerson::TPerson(QString name,QObject *parent)
    :QObject{parent}
    ,_name{name}
{

}

TPerson::~TPerson()
{
    qDebug("TPerson退出");
}

size_t TPerson::age()
{
    return _age;
}
//写入
void TPerson::setAeg(size_t age)
{
    if(age != _age)
    {
        _age = age;
        emit ageChanged(_age);
    }
}

viod TPerson::incAge()
{
    ++_age;
    emit ageChanged(_age);
}

