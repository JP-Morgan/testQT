
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
    QString tr = QString("<center><h1>Mouse Release:(%1,%2)</h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(tr);
}
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString tr = QString("<center><h1>Mouse Move:(%1,%2)</h1></center>").arg(ev->x()).arg(ev->y());
    this->setText(tr);
}

void MyLabel::enterEvent(QEvent *)
{
    QString tr = QString("<center><h1>Mouse enter</h1></center>");
    this->setText(tr);
}
//离开窗口区域
void MyLabel::leaveEvent(QEvent *)
{
    QString tr = QString("<center><h1>Mouse leave</h1></center>");
    this->setText(tr);
}
