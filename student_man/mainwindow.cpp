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
    , m_StudentSql(nullptr)
    , m_SdudentSum(0)
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

    m_StudentSql = StudentSql::getinstance();

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(8); // 假设有7列数据
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "名字", "年龄", "年级", "班级", "学号", "手机号", "微信"});
    m_SdudentSum = m_StudentSql->FindStudents();
    auto students =m_StudentSql->FindAllStudent();

    ui->tableWidget->setRowCount(m_SdudentSum);
    int row = 0;
    for (const auto& student : students) {
        // 假设 Student 类有对应的成员函数来获取各个字段的值
        QTableWidgetItem* item_id = new QTableWidgetItem(QString::number(student.id));
        QTableWidgetItem* item_name = new QTableWidgetItem(student.name);
        QTableWidgetItem* item_age = new QTableWidgetItem(QString::number(student.age));
        QTableWidgetItem* item_grade = new QTableWidgetItem(QString::number(student.grade));
        QTableWidgetItem* item_class = new QTableWidgetItem(QString::number(student.myclass));
        QTableWidgetItem* item_student_id = new QTableWidgetItem(QString::number(student.studentid));
        QTableWidgetItem* item_phone = new QTableWidgetItem(student.phone);
        QTableWidgetItem* item_wechat = new QTableWidgetItem(student.wechat);

        ui->tableWidget->setItem(row, 0, item_id);
        ui->tableWidget->setItem(row, 1, item_name);
        ui->tableWidget->setItem(row, 2, item_age);
        ui->tableWidget->setItem(row, 3, item_grade);
        ui->tableWidget->setItem(row, 4, item_class);
        ui->tableWidget->setItem(row, 5, item_student_id);
        ui->tableWidget->setItem(row, 6, item_phone);
        ui->tableWidget->setItem(row, 7, item_wechat);

        ++row;
    }
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

    // 从左到右
    QString a = "学生数量：";
    m_StudentSql = StudentSql::getinstance();
    quint32 Sum = m_StudentSql->FindStudents();
    QString studentCount = QString::number(Sum);
    QString labelText1 = a + studentCount;
    statusBr->addWidget(new QLabel(labelText1, this));


    // 从右到左
    QString b = "admin";
    QString labelText2 = "用户: " + b;
    QLabel *label = new QLabel(labelText2, this);
    label->setStyleSheet("color: white;");
    statusBr->addPermanentWidget(label);
    // 添加另一个左侧内容
    //    QString anotherLeftContent = "左侧内容2";
    //    statusBr->addWidget(new QLabel(anotherLeftContent, this));



    // 添加另一个右侧内容
    //    QString anotherRightContent = "右侧内容2";
    //    QLabel *anotherRightLabel = new QLabel(anotherRightContent, this);
    //    statusBr->addPermanentWidget(anotherRightLabel);
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

