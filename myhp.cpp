#include "myhp.h"

myHp::myHp() {

    for(int i=1;i<=71;i++)
    {
        QString str=QString(":/planWar/myHp%1.png").arg(i);
        QPixmap pic=QPixmap(str);
        h_myHp.push_back(pic);
    }

    e_x=3;
    e_y=805;

     myHpNum=0;//血量值

     myHpIndex=0;//要播放第几个血量照片
}
