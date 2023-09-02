
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>//表格模型
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void MySql_link(QString HostName = "127.0.0.1", QString UserName = "root",QString Password = "Morgan2004",QString DatabaseName = "qwe",int Port = 3306);
    void MySql_set(QString table_name = "");
    void MySql_delete();


private slots:
    void on_MySql_add_clicked();

    void on_MySql_Yes_clicked();

    void on_MySql_No_clicked();

    void on_MySql_delet_clicked();

    void on_MySql_find_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};

#endif // WIDGET_H
