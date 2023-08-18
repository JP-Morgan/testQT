
#include "mylabel.h"
#include <QMouseEvent>
#include <QString>
MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{

}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    QString tr = QString("<center><h1>Mouse Press:(%1,%2)</h1></center>").arg(i).arg(j);
    this->setText(tr);
}
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

}
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{

}
