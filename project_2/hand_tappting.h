
#ifndef HAND_TAPPTING_H
#define HAND_TAPPTING_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


class Hand_tappting : public QDialog

{
    Q_OBJECT

public:
    Hand_tappting(QWidget *parent = nullptr);
    ~Hand_tappting();
private:
    //QCheckBox为复选按钮
    QCheckBox* chkBoxUnder;
    QCheckBox* chkBoxItalic;
    QCheckBox* chkBoxBold;

    //QRadioButton勾选按键
    QRadioButton* RadioBlack;
    QRadioButton* RadioRad;
    QRadioButton* RadioBlue;

    //QPlainTextEdit文本
    QPlainTextEdit* txtEdit;

    //QPushButton普通点击按钮
    QPushButton* butok;
    QPushButton* butclose;
    QPushButton* butdelet;

};

#endif // HAND_TAPPTING_H
