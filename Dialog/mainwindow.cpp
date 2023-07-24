
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *QM = menuBar();
    setMenuBar(QM);
    QMenu *m = QM->addMenu("对话框");
    QAction *p1 = m->addAction("模态对话框");
    connect(p1,&QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
            }
            );
    QAction *p2 = m->addAction("非模态对话框");
    connect(p2,&QAction::triggered,
            [=]()
            {

                //dlg.show();
                QDialog *q= new QDialog;
                q->setAttribute(Qt::WA_DeleteOnClose);
                q->show();
            }
            );
    QAction *p3 = m->addAction("对话框");
    connect(p3,&QAction::triggered,
            [=]()
            {
                QMessageBox::about(this,"对话框", "*************");
            }
            );
    QAction *p4 = m->addAction("问他对话框");
    connect(p4,&QAction::triggered,
            [=]()
            {
                int ret = QMessageBox::question(this,"问题","**********",QMessageBox::Ok,QMessageBox::Cancel);

                switch (ret) {
                case QMessageBox::Ok:
                    qDebug()<< "ok";break;
                case QMessageBox::Cancel:
                    qDebug()<< "no";break;
                default:
                    break;
                }
            }
            );
    QAction *p5 = m->addAction("文件对话框");
    connect(p5,&QAction::triggered,
            [=]()
            {
                QString pasth = QFileDialog::getOpenFileName(
                    this,
                    "文件对话框",
                    "../",
                    "souce(*.cpp *.h);;Text(*.txt);;all(*.*)"
                    );
                qDebug()<<pasth;
            }
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}


