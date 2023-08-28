
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *event);
    //计时器事件
    void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
    int timerId;
};

#endif // WIDGET_H
