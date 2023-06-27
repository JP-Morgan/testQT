#include "hand_tappting.h"


Hand_tappting::Hand_tappting(QWidget *parent)
    : QDialog(parent)
{
    chkBoxUnder = new QCheckBox("下划线");
    chkBoxItalic = new QCheckBox("斜体");
    chkBoxBold = new QCheckBox("加粗");
    QHBoxLayout *HLayl = new QHBoxLayout();
    HLayl->addWidget(chkBoxUnder);
    HLayl->addWidget(chkBoxItalic);
    HLayl->addWidget(chkBoxBold);

    RadioBlack = new QRadioButton("黑色");
    RadioRad = new QRadioButton("红色");
    RadioBlue = new QRadioButton("蓝色");

    QHBoxLayout *HLayl2 = new QHBoxLayout();
    HLayl2->addWidget(RadioBlack);
    HLayl2->addWidget(RadioRad);
    HLayl2->addWidget(RadioBlue);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("你好 QT\nhello");
    QFont font = txtEdit->font();
    font.setPointSize(30);
    txtEdit->setFont(font);

    butok = new QPushButton("确定");
    butdelet = new QPushButton("关闭");
    butclose = new QPushButton("取消");
    QHBoxLayout *HLayl3 = new QHBoxLayout();
    HLayl3->addStretch();
    HLayl3->addWidget(butdelet);
    HLayl3->addStretch();
    HLayl3->addWidget(butok);
    HLayl3->addWidget(butclose);

    QVBoxLayout *VLayl = new QVBoxLayout();
    VLayl->addLayout(HLayl);
    VLayl->addLayout(HLayl2);
    VLayl->addWidget(txtEdit);
    VLayl->addLayout(HLayl3);

    setLayout(VLayl);
    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxItalic(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxBold(bool)));

    connect(RadioRad,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));
    connect(RadioBlack,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));
    connect(RadioBlue,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));

    connect(butok,SIGNAL(clicked()),this,SLOT(accept()));
    connect(butdelet,SIGNAL(clicked()),this,SLOT(reject()));
    connect(butclose,SIGNAL(clicked()),this,SLOT(close()));

    setWindowTitle("手写界面");

}

Hand_tappting::~Hand_tappting()
{
}

void Hand_tappting::do_chkBoxUnder(bool QChecked)
{
    QFont font = txtEdit->font();
    font.setUnderline(QChecked);
    txtEdit->setFont(font);
}

void Hand_tappting::do_chkBoxItalic(bool QChecked)
{
    QFont font = txtEdit->font();
    font.setItalic(QChecked);
    txtEdit->setFont(font);
}

void Hand_tappting::do_chkBoxBold(bool QChecked)
{
    QFont font = txtEdit->font();
    font.setBold(QChecked);
    txtEdit->setFont(font);
}

void Hand_tappting::do_setFontColor()
{
    //QPalette在QT中我们如何改变某个控件的颜色外观呢？比如改变背景、文字颜色等。QT提供了调色板类QPalette专门用于管理对话框的外观显示。
    //每个控件或者窗体都包含一个QPalette对象，在显示时会根据其QPalette对象中对各个部分各状态下的颜色的描述进行绘制。
    QPalette Palet=txtEdit->palette();
    if(RadioBlack->isChecked())
    {
        Palet.setColor(QPalette::Text,Qt::black);
    }
    if(RadioRad->isChecked())
    {
        Palet.setColor(QPalette::Text,Qt::red);
    }
    if(RadioBlue->isChecked())
    {
        Palet.setColor(QPalette::Text,Qt::blue);
    }
    txtEdit->setPalette(Palet);
}



