
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "page_login.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void MyMeun();
    void StatusBar();
    void LeftTree();

private:
    Ui::MainWindow *ui;
    Page_Login _Login;
};

#endif // MAINWINDOW_H
