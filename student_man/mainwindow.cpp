#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QKeyEvent>
#include <QFile>
#include <QCoreApplication>
#include <QStatusBar>
#include <qlabel.h>
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
    //左边的树
    LeftTree();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F6)
    {
        QFile f;
        auto str = QCoreApplication::applicationDirPath();
        f.setFileName(str+"//"+"stuqss.css");
        f.open(QIODevice::ReadOnly);
        QString strQss = f.readAll();
        _Login.setStyleSheet(strQss);
        this->setStyleSheet(strQss);
    }
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
                _Login.close();
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
//状态栏
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
//左边的树
void MainWindow::LeftTree()
{
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QStringList name;

    name<<"学生管理系统";
    QTreeWidgetItem *Father = new QTreeWidgetItem(ui->treeWidget,name);
    ui->treeWidget->addTopLevelItem(Father);

    name.clear();
    name<<"学生管理";
    QTreeWidgetItem *Child1 = new QTreeWidgetItem(Father,name);

    name.clear();
    name<<"管理员管理";
    QTreeWidgetItem *Child2 = new QTreeWidgetItem(Father,name);
    Father->addChild(Child1);
    Father->addChild(Child2);
    //全部展开
    ui->treeWidget->expandAll();
}




