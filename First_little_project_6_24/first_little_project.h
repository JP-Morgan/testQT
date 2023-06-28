
#ifndef FIRST_LITTLE_PROJECT_H
#define FIRST_LITTLE_PROJECT_H

#include <QDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class First_little_project; }
QT_END_NAMESPACE

class First_little_project : public QDialog

{
    Q_OBJECT

public:
    First_little_project(QWidget *parent = nullptr);
    ~First_little_project();

private slots:
    void on_pushButton_Delete_clicked();

    void on_checkBox_Underline_clicked(bool checked);

    void on_checkBox_Italic_clicked(bool checked);

    void on_checkBox_Bold_clicked(bool checked);

    void do_FontColor();//对颜色的修改
    //为什么跟上面的接口设计的不一样？
    //主要因为！颜色的修改只能同时出现一次！
    //所以.............只需要一个接口在接口中进行判断

private:
    Ui::First_little_project *ui;
};

#endif // FIRST_LITTLE_PROJECT_H
