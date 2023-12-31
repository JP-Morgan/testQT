﻿#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = nullptr);
    ~Page_Login();

private slots:
    void on_register_1_clicked();

    void on_return_2_clicked();

    void on_log_on_1_clicked();

    void on_register_2_clicked();

signals:
    void sendLoginSuccess();

private:
    Ui::Page_Login *ui;
};

#endif // PAGE_LOGIN_H
