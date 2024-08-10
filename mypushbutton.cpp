#include "mypushbutton.h"
#include"config.h"


MyPushButton::MyPushButton(QString a)
{
    pix.load(a);

    //设定按钮大小
    this->setFixedSize(QPixmap(a).size()/5);
    this->setIcon(QPixmap(a));
    this->setIconSize(QPixmap(a).size()/5);
    this->setStyleSheet("QPushButton {background-color: transparent;border: none;color: white;}");//透明设置
    this->move(GAME_WIDTH/2-QPixmap(a).width()/10,GAME_HEIGHT/2+200);
}

void MyPushButton::replaceIcon(QString a)
{
    QPixmap pix;
    pix.load(a);
    this->setFixedSize(QPixmap(a).size()/5);
    this->move(GAME_WIDTH/2-QPixmap(a).width()/10,GAME_HEIGHT/2+200);
    this->setIcon(QPixmap(a));
    this->setIconSize(QPixmap(a).size()/5);
    this->setStyleSheet("QPushButton {background-color: transparent;border: none;color: white;}");//透明设置
}
