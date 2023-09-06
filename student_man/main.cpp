#include "mainwindow.h"
#include "page_login.h"
#include <QApplication>
#include "studentsql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    StudentSql sql;
//    w.show();
//    Page_Login p;
//    p.show();
    return a.exec();
}
