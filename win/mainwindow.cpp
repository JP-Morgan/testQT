
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>//菜单栏
#include <QMenu>//添加菜单
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>//文本编辑
#include <QDockWidget>//浮动窗口

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //菜单栏
    QMenuBar *mBar/*栏*/ = menuBar();
    //添加菜单
    QMenu *pFile/*菜单*/ = mBar->addMenu("文件");
    //添加菜单下拉栏
    QAction *pNew/*动作*/ = pFile->addAction("new");
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("open");
    connect(pNew,&QAction::triggered,
            [=]()
            {
                qDebug()<<"NEW OK";
            }
            );
    connect(pOpen,&QAction::triggered,
            [=]()
            {
                qDebug()<<"open";
            }
            );
    //工具栏
    QToolBar *toolBar = addToolBar("toolBar");//默认会浮动
    //工具栏添加快捷键
    toolBar->addAction(pNew);
    //工具栏添加快捷键（按键）
    QPushButton *b = new QPushButton(this);
    b->setText("open");
        //添加小控件
    toolBar->addWidget(b);
    connect(b,&QPushButton::clicked,
            [=]()
            {
                qDebug()<<"open";
            }
            );

    //状态
    QStatusBar *statusbar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("状态:");
    statusbar->addWidget(label);
    //从左往右
    statusbar->addWidget(new QLabel("打开",this));
    //从右往左
    statusbar->addPermanentWidget(new QLabel("test",this));
    //核心
    QTextEdit *T = new QTextEdit(this);
    setCentralWidget(T);//中心

    //浮动
    QDockWidget *d =new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,d);

    QTextEdit *T2 = new QTextEdit(this);
    d->setWidget(T2);//添加类容到其他界面

    //
    //
    //
    //
    //
    //
    //
    //


}

MainWindow::~MainWindow()
{
    delete ui;
}


