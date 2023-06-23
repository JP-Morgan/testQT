
#ifndef TEST1_2_H
#define TEST1_2_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class test1_2; }
QT_END_NAMESPACE

class test1_2 : public QMainWindow

{
    Q_OBJECT

public:
    test1_2(QWidget *parent = nullptr);
    ~test1_2();

private:
    Ui::test1_2 *ui;
};

#endif // TEST1_2_H
