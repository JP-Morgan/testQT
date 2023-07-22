
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *QM = menuBar();
    setMenuBar(QM);
    QMenu *m = QM->addMenu("对话框");
}

MainWindow::~MainWindow()
{
    delete ui;
}


