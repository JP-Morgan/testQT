
#include "test1_2.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//定义创建窗口程序！
    test1_2 w;
    w.show();
    return a.exec();//应用程序运行，开始消息循环和事件处理
}
