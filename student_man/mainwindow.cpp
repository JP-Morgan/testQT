#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _Login.show();
    //this->hide();

    connect(&_Login, &Page_Login::sendLoginSuccess, this,
            [=]()
            {
                this->show();
            }
            );
    //菜单
    MyMeun();
    //底下状态栏
    StatusBar();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//菜单控制
void MainWindow::MyMeun()
{
    // 新建菜单栏
    QMenuBar *menuBr = menuBar();
    setMenuBar(menuBr);
    // 添加菜单
    QMenu *pFile = menuBr->addMenu("File");
    // 添加菜单项
    QAction *pexit = pFile->addAction("退出");
    QAction *pre_login = pFile->addAction("重新登陆");
    connect(pexit, &QAction::triggered,
            [=]()
            {
                this->close();
            }
            );
    connect(pre_login, &QAction::triggered,
            [=]()
            {
                _Login.show();
                this->close();
            }
            );
}

void MainWindow::StatusBar()
{
    QStatusBar *statusBr = statusBar();
    // 第一种
//    QLabel *fileType = new QLabel(this);
//    fileType->setText("Normal text file");
//    statusBr->addWidget(fileType);
    // 第二种
    //从左到有
    //statusBr->addWidget(new QLabel("UTF8", this));
    //从有到左
    QString a = "admin";
    QString tr = "用户:";
    tr+=a;
    statusBr->addPermanentWidget(new QLabel(tr, this));
}



