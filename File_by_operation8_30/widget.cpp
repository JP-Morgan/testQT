
#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include <QFileDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


//读文件
void Widget::on_read_clicked()
{
    QString fileraed = QFileDialog::getOpenFileName(this/*作用于*/,/*标题*/"open",/*路径*/"../");
    if(!fileraed.isEmpty())
    {
//        文件对象
        QFile file(fileraed);

//        打开文件,只读默认只支持utf_8
        bool isok = file.open(QIODevice::ReadOnly);
        if(isok == true)
        {
        //            读文件——一次性读完
        //            QByteArray array = file.readAll();

        //            //显示到编辑区
        //            ui->textEdit->setText(QString(array));
        //一行一行的读
            QByteArray array;
            while(!file.atEnd())
            {
                array += file.readLine();
            }
            ui->textEdit->setText(array);
        }

        {

        }
        //关闭文件
        file.close();
    }
}


void Widget::on_pushButton_2_clicked()
{
    QString path =QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(path.isEmpty() == false)
    {
        QFile file;
        file.setFileName(path);
        //打开文件
        bool isok = file.open(QIODeviceBase::WriteOnly);
        if(isok == true)
        {
            //获取类容
            QString str = ui->textEdit->toPlainText();

//            file.write(str.toUtf8());
            file.write(str.toStdString().data());

        }
        file.close();
    }
}

