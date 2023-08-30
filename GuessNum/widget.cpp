
#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include <QMessageBox>
#include <QString>
#include <QMovie>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->Home_page);
    //初始化数据
    //失败动画
    overMovie.setFileName(":/new/prefix1/Image/over.gif");
    ui->Failure_page_2->setMovie(&overMovie);//给标签设置动画
    ui->Failure_page_2->setScaledContents(true);//让动画自动适应标签大小

    //胜利动画
    winMovie.setFileName(":/new/prefix1/Image/win.gif");
    ui->Victory_page_2->setMovie(&winMovie);
    ui->Victory_page_2->setScaledContents(true);

    connect(ui->Button_1,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_2,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_3,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_4,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_5,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_6,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_7,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_8,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_9,&QPushButton::clicked,this,&Widget::dealNum);
    connect(ui->Button_0,&QPushButton::clicked,this,&Widget::dealNum);

}

Widget::~Widget()
{
    delete ui;
}





//开始位置
void Widget::on_start_clicked()
{
    //获取下拉框的时间 .toInt()：字符串转换为 int
    gameTime = ui->comboBox->currentText().toInt();
    qDebug() << gameTime << "s";
    //  跳转界面
    ui->stackedWidget->setCurrentWidget(ui->Game_page);
    int num;
    //以从0时0分0秒到现在的秒数为种子

    srand( QTime(0,0,0).secsTo(QTime::currentTime()));
    //调用全局的qrand()函数生成随机数，对10000取余，保证位于10000的范围内
    while( ( num = rand()%10000 ) < 999 );
    randStr = QString::number(num);
    qDebug() << "randNum = " << randStr;

    gameTimerId = 0;
    //启动定时器
    gameTimerId = startTimer(1000); //以 1000 毫秒（即1s）作为时间间隔

    resultStr.clear();
    ui->textEdit->clear();
}
//退出
void Widget::on_close_clicked()
{
    this->close();
}

void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == gameTimerId)//游戏时间
    {
        gameTime--;


        if(0 == gameTime)//时间到
        {
            //关闭定时器
            killTimer(gameTimerId);

            QMessageBox::information(this, "失败", "时间到了啊！！！");


            overMovie.start();//启动动画

            //切换失败动画页面
            //ui->stackedWidget->setCurrentIndex(2);
            ui->stackedWidget->setCurrentWidget(ui->Failure_page);

            overTimerId = startTimer(5000); //启动定时器

        }

    }
    else if(e->timerId() == overTimerId)//失败动画时间
    {

        //停止动画，停止定时器，回到游戏设置页面
        overMovie.stop();//停止动画
        killTimer(overTimerId);  //停止定时器
        //切换到游戏设置页面
        ui->stackedWidget->setCurrentWidget(ui->Home_page);

    }
    else if(e->timerId() == winTimerId)//胜利动画时间
    {

        winMovie.stop();//停止动画
        killTimer(winTimerId);  //停止定时器

        //切换到游戏设置页面
        ui->stackedWidget->setCurrentWidget(ui->Home_page);

    }
}
//数字键处理
void Widget::dealNum()
{
    //获取信号接收者
    QObject * mySender = sender();
    //转换为按钮类型
    QPushButton *p = (QPushButton *)mySender;
    if(NULL != p)
    {
        //获取按钮的内容
        QString numStr = p->text();
        resultStr += numStr;

        //数字不能以0开始
        if(resultStr.size() == 1 && resultStr == "0")
        {
            resultStr.clear();
        }

        if( resultStr.size() <= 4) //保证显示结果为4位
        {
            ui->textEdit->setText( resultStr );

            if(resultStr.size() == 4) //数字到第4位时
            {
                if(resultStr > randStr)
                {
                    ui->textEdit->append("数字大了点!!!");
                }
                else if(resultStr < randStr)
                {
                    ui->textEdit->append("数字小了点!!!");
                }
                else
                {
                    ui->textEdit->append("恭喜你猜对了!!!");

                    //停止定时器
                    //关闭定时器
                    killTimer(gameTimerId);

                    QMessageBox::information(this, "胜利", "恭喜你猜对了!!!");

                    //切换到成功动画
                    winMovie.start();
                    ui->stackedWidget->setCurrentWidget(ui->Victory_page);

                    //启动定时器
                    winTimerId = startTimer(5000); //5s
                }

                //初始化字符串结果，清空
                resultStr.clear();
            }
        }

    }

}
//退格
void Widget::on_backspace_clicked()
{
    if(resultStr.size() == 1)
    {
        resultStr.clear();
        ui->textEdit->clear();
    }
    else
    {
        resultStr.chop(1); //截断最后一位字符
        ui->textEdit->setText(resultStr);
    }
}


void Widget::on_prompt_clicked()
{
    resultStr.clear();
    QString str = "随机数为：" + randStr;
    ui->textEdit->setText( str );
}

