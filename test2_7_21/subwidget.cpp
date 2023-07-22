
#include "subwidget.h"

Subwidget::Subwidget(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("小弟");
    f1.setParent(this);
    f1.setText("小弟");
    connect(&f1,&QPushButton::clicked,this,&Subwidget::sendSlot);
    resize(400,300);
}

void Subwidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250,"我是子窗口");
}

