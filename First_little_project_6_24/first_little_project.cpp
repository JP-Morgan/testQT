
#include "first_little_project.h"
#include "ui_first_little_project.h"


First_little_project::First_little_project(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::First_little_project)
{
    ui->setupUi(this);
}

First_little_project::~First_little_project()
{
    delete ui;
}


