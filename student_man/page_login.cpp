#include "page_login.h"
#include "ui_page_login.h"

Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->login);
}

Page_Login::~Page_Login()
{
    delete ui;
}
//注册
void Page_Login::on_register_1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sign_up);
}

//注册界面——返回
void Page_Login::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->login);
}

//登录
void Page_Login::on_log_on_1_clicked()
{
    //数据库查找用户名与密码

    //失败就提示

    //成功就进入
    emit sendLoginSuccess();

}
//确认注册
void Page_Login::on_register_2_clicked()
{

}

