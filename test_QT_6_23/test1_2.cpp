
#include "test1_2.h"
#include "ui_test1_2.h"


test1_2::test1_2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::test1_2)
{
    ui->setupUi(this);
}

test1_2::~test1_2()
{
    delete ui;
}


