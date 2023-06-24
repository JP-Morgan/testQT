
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

private:
    Ui::First_little_project *ui;
};

#endif // FIRST_LITTLE_PROJECT_H
