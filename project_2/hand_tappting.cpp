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
    butdelet = new QPushButton("删除");
    butclose = new QPushButton("取消");
    QHBoxLayout *HLayl3 = new QHBoxLayout();
    HLayl3->addWidget(butok);
    HLayl3->addWidget(butdelet);
    HLayl3->addWidget(butclose);

    QVBoxLayout *VLayl = new QVBoxLayout();
    VLayl->addLayout(HLayl);
    VLayl->addLayout(HLayl2);
    VLayl->addWidget(txtEdit);
    VLayl->addLayout(HLayl3);

    setLayout(VLayl);
}

Hand_tappting::~Hand_tappting()
{
}


