
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include"subwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT//信号槽函数

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //切换到子窗口
    void Swap();
    void dealSib();
    void dealSlot(int ,QString);
private:
    Ui::Widget *ui;
private:
    QPushButton a1;
    QPushButton *a2;
    //切换窗口
    QPushButton a3;
    Subwidget win1;
};

#endif // WIDGET_H
