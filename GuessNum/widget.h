
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMovie>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //自定义槽函数
    void dealNum();

private slots:


    void on_start_clicked();

    void on_close_clicked();
    void on_backspace_clicked();

    void on_prompt_clicked();

protected:
    //定时器事件，此为虚函数
    void timerEvent(QTimerEvent *e);

private:
    Ui::Widget *ui;
    int gameTime;       //游戏时间
    QString randStr;    //随机数
    int gameTimerId;    //游戏时间定时器ID
    int overTimerId;    //失败动画定时器ID
    int winTimerId;     //成功动画定时器ID
    QString resultStr;  //结果数

    QMovie overMovie;   //失败动画
    QMovie winMovie;    //胜利动画
};

#endif // WIDGET_H
