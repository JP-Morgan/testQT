
#ifndef TPERSON_H
#define TPERSON_H


#include <QObject>
#include <string>


class TPerson : public QObject
{
    Q_OBJECT
public:
    explicit TPerson(QString name,QObject *parent = nullptr);
    ~TPerson();
    size_t age();
    void setAeg(size_t age);
    void incAge();
signals:
    void ageChanged(int ageValue);

private:

    //QString _sex;
    QString _name;
    size_t _age = 0;
    size_t _score = 0;

};

#endif // TPERSON_H
