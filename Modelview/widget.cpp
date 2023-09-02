#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QSqlTableModel>//表格模型
#include <QSqlRecord>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //链接数据库
    MySql_link();
    //模型设置
    MySql_set("student");
    //数据库增加

    //删除

    //修改

    //查看


}

Widget::~Widget()
{
    delete ui;
}

void Widget::MySql_link(QString HostName, QString UserName, QString Password, QString DatabaseName, int Port)
{
//    链接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //链接数据库
    db.setHostName(HostName);//数据库服务器ip
    db.setUserName(UserName);//数据库用户名
    db.setPassword(Password);//密码
    db.setDatabaseName(DatabaseName);//使用那个数据库
    db.setPort(Port);

    if(!db.open())//开失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    qDebug()<<"成功";
}
//设置模型
void Widget::MySql_set(QString table_name)
{
    //设置模型
    model = new QSqlTableModel(this);
    model->setTable(table_name);//指定表

    //    把mode放在view
    ui->tableView->setModel(model);

    //显示mode数据
    model->select();

    //在界面改头民称
    model->setHeaderData(0,/*水平*/Qt::Horizontal,"学号");
    model->setHeaderData(1,/*水平*/Qt::Horizontal,"姓名");
    model->setHeaderData(2,/*水平*/Qt::Horizontal,"年龄");
    model->setHeaderData(3,/*水平*/Qt::Horizontal,"成绩");

    //设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //视图不让修改，只读
   // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Widget::MySql_delete()
{

}



//添加
void Widget::on_MySql_add_clicked()
{
    //添加空记录
    QSqlRecord record = model->record();//获取一个空记录
//    获取行号
    int row = model->rowCount();
    model->insertRecord(row , record);

}

//确定
void Widget::on_MySql_Yes_clicked()
{
    model->submitAll();//提交动作
}


void Widget::on_MySql_No_clicked()
{
    model->revertAll();//取消所有动作
    model->submitAll();//取消所有动作
}


void Widget::on_MySql_delet_clicked()
{
    //获取选择的模型
    QItemSelectionModel *sModel = ui->tableView->selectionModel();
    //取出模型中的缩影
    QModelIndexList list = sModel->selectedRows();
    //删除所有行
    for(int i = 0; i < list.size(); i++)
    {
        model->removeRow(list.at(i).row() );
    }
}



void Widget::on_MySql_find_clicked()
{
    QString naem = ui->lineEdit->text();
    if(naem == nullptr)
    {
        MySql_set("student");
    }
    else {
        QString str = QString("name = '%1'").arg(naem);
        //过滤
        model->setFilter(str);
        //重新显示
        model->select();
    }

}

