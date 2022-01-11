#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{

    delete ui;

}

void Widget::changeMoney(int coin)
{
    money += coin;
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money>=200);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=100);
}



void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
    ui->lcdNumber->display(money);

}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
    ui->lcdNumber->display(money);


}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
    ui->lcdNumber->display(money);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
    ui->lcdNumber->display(money);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
    ui->lcdNumber->display(money);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    ui->lcdNumber->display(money);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
    ui->lcdNumber->display(money);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    int change500 = money / 500;
    money = money % 500;
    int change100 = money / 100;
    money = money % 100;
    int change50 = money / 50;
    money = money % 50;
    int change10 = money / 10;
    money = money % 10;
    char str[128];
    sprintf(str,"Coin Change is \n500: %d, 100: %d, 50: %d, 10: %d",change500,change100,change50,change10);
    msgBox.setText(str);
    msgBox.exec();
    ui->lcdNumber->display(money);
}
