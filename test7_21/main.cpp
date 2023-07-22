
#include "widget.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //指定父对象方法二setParent法
    QPushButton b1;
    b1.setText("abc");
    b1.setParent(&w);
    b1.move(100,100);
    //指定父对象方法一默认构构造法
    QPushButton b(&w);
    b.setText("123");

    w.show();
    return a.exec();
}
