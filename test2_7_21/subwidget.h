
#ifndef SUBWIDGET_H
#define SUBWIDGET_H


#include <QWidget>
#include <QPushButton>


class Subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Subwidget(QWidget *parent = nullptr);
    void sendSlot();
signals:
    /*
     * 信号必须要signals
     * 信号没有返回值
     * 信号函数只需要声明，不需要定义
     * 使用：emit mySignal();
     * 信号可以从重载
     */
    void mySignal();
    void mySignal(int,QString);
private:
    QPushButton f1;

};

#endif // SUBWIDGET_H
