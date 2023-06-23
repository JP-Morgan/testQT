
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget//定义了一个名为Widget的类，它继承自QWidget类，也就是说Widget是QWidget的子类。

{
    Q_OBJECT//这是一个Qt的宏，用于启用Qt的元对象系统（Meta-Object System）。它允许在类中使用Qt的信号（signal）和槽（slot）机制。

public:
    //这里定义了Widget类的公有成员函数。构造函数Widget(QWidget *parent = nullptr)是类的构造函数
    //，接受一个可选的父部件参数，默认为nullptr。析构函数~Widget()是类的析构函数，用于释放资源和清理操作。
    Widget(QWidget *parent = nullptr);//
    ~Widget();

private:
    //它是Ui::Widget类型的指针。Ui::Widget是在前面定义的命名空间Ui中声明的一个类，
    //它用于生成和管理用户界面部件。
    Ui::Widget *ui;
};

#endif // WIDGET_H
