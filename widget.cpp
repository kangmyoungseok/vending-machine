#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

const int COIN_LIST[] = {500,100,50,10};

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
    ui->lcdNumber->display(money);
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money>=200);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=100);
}

int Widget::getChange(int coin)
{
    int change = money / coin;
    money %=coin;
    return change;
}



void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);

}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);

}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);

}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    QString msg = "Coin Change\n";
    int coinListNum = sizeof(COIN_LIST) / sizeof(int);
    for(int i=0; i<coinListNum; i++){
        int coinNum = getChange(COIN_LIST[i]);
        if(coinNum > 0){
            QString strCoinType = QString::number(COIN_LIST[i]);
            QString strCoinNum = QString::number(coinNum);
            msg += strCoinType + ":" + strCoinNum + "\n";
        }
    }
    changeMoney(0);
    msgBox.information(this,"coin reset",msg);


}
