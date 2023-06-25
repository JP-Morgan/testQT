
#include "first_little_project.h"
#include "ui_first_little_project.h"


First_little_project::First_little_project(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::First_little_project)
{
    ui->setupUi(this);
    connect(ui->radioButton_Black,SIGNAL(clicked()), this, SLOT(do_FontColor()));
    connect(ui->radioButton_Red,SIGNAL(clicked()), this, SLOT(do_FontColor()));
    connect(ui->radioButton_Blue,SIGNAL(clicked()), this, SLOT(do_FontColor()));

}

First_little_project::~First_little_project()
{
    delete ui;
}



void First_little_project::on_pushButton_Delete_clicked()
{
    ui->plainTextEdit->clear();
}


void First_little_project::on_checkBox_Underline_clicked(bool checked)
{
    //QFont是字符类
    //我们要先拿到当前的字体我们才能修改他的字体！
    QFont font = ui->plainTextEdit->font();//获取当前的字体样式！
    font.setUnderline(checked);//进行修改字体
    ui->plainTextEdit->setFont(font);//更改方框里的样式！
}


void First_little_project::on_checkBox_Italic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();//获取当前的字体样式！
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);//更改方框里的样式！
}


void First_little_project::on_checkBox_Bold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void First_little_project::do_FontColor()
{
    QPalette pale = ui->plainTextEdit->palette();
    if(ui->radioButton_Black->isChecked())//是否被选中isChecked()
    {
        pale.setColor(QPalette::Text,Qt::black);//修改颜色！
    }
    if(ui->radioButton_Blue->isChecked())
    {
        pale.setColor(QPalette::Text,Qt::blue);//修改颜色！
    }
    if(ui->radioButton_Red->isChecked())
    {
        pale.setColor(QPalette::Text,Qt::red);//修改颜色！
    }
    ui->plainTextEdit->setPalette(pale);
}

