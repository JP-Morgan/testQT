
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口固定大小
    this->setMaximumSize(270,400);
    this->setMinimumSize(270,400);
    //设置字体
    QFont f("微软雅黑",20);
    ui->mianlineEdit->setFont(f);
    //设置图片
    QIcon con("F:\\代码\\GitHub\\testQT\\calculator_7_20\\pic\\删除.png");
    ui->delButton->setIcon(con);

    ui->equalButton->setStyleSheet("background-color: rgb(175,238,238)");
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_oneButton_clicked()
{
    expression += "1";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_twoButton_clicked()
{
    expression += "2";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_threeButton_clicked()
{
    expression += "3";
    ui->mianlineEdit->setText(expression);
}

void Widget::on_fourButton_clicked()
{
    expression += "4";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_fiveButton_clicked()
{
    expression += "5";
    ui->mianlineEdit->setText(expression);
}

void Widget::on_sixButton_clicked()
{
    expression += "6";
    ui->mianlineEdit->setText(expression);
}

void Widget::on_sevenButton_clicked()
{
    expression += "7";
    ui->mianlineEdit->setText(expression);
}

void Widget::on_eightButton_clicked()
{
    expression += "8";
    ui->mianlineEdit->setText(expression);
}

void Widget::on_nineButton_clicked()
{
    expression += "9";
    ui->mianlineEdit->setText(expression);
}

void Widget::on_zeroButton_clicked()
{
    expression += "0";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_divButton_clicked()
{
    expression += "/";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_mulButton_clicked()
{
    expression += "*";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_minButton_clicked()
{
    expression += "-";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_addButton_clicked()
{
    expression += "+";
    ui->mianlineEdit->setText(expression);
}


void Widget::on_cleanButton_clicked()
{
    expression.clear();
    ui->mianlineEdit->clear();
}


void Widget::on_delButton_clicked()
{
    expression.chop(1);
    ui->mianlineEdit->setText(expression);
}

void Widget::on_equalButton_clicked()
{
    QStack<int> s_num, s_opt;

    char opt[128] = {0};
    int i = 0, tmp = 0, num1, num2;

    // 把QString转换成QByteArray
    QByteArray ba = expression.toUtf8();

    strcpy(opt, ba.data());
    //在此更新的代码中，  QByteArray 由  expression QString 使用  toUtf8() 函数，
    //返回  QByteArray.这确保了与  QByteArray::append()
    while (opt[i] != '\0' || s_opt.empty() != true)
    {
        if (opt[i] >= '0' && opt[i] <= '9')
        {
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if (opt[i] < '0' || opt[i] > '9')
            {
                s_num.push(tmp);
                tmp = 0;
            }
        }
        else           //操作符
        {
            if (s_opt.empty() == true || Priority(opt[i]) > Priority(s_opt.top()) ||
                (s_opt.top() == '(' && opt[i] != ')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }

            if (s_opt.top() == '(' && opt[i] == ')')
            {
                s_opt.pop();
                i++;
                continue;
            }

            if (Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == ')' && s_opt.top() != '(') ||
                (opt[i] == '\0' && s_opt.empty() != true))
            {
                char ch = s_opt.top();
                s_opt.pop();
                switch(ch)
                {
                case '+':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 + num2);
                    break;
                case '-':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 - num2);
                    break;
                case '*':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 * num2);
                    break;
                case '/':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1 / num2);
                    break;
                }
            }
        }
    }
    ui->mianlineEdit->setText(QString::number(s_num.top()));
    expression.clear();
}
int Widget::Priority(char ch)
{
    switch(ch)
    {
    case '(':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
