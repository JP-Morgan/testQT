
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tperson.h"
class TPerson;


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    TPerson *boy;
    TPerson *girl;
private slots:
    void do_ageChanged(size_t value);
    void do_spinChanged(szie_t arg1);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
