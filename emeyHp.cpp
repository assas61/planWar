#include "emeyHp.h"

hp::hp() {

   // 图片
    for(int i=0;i<=HP_MAX;i++)
    {
        QString str=QString(":/planWar/hp%1_resized.png").arg(i);
        QPixmap pic=QPixmap(str);
        h_hp.push_back(pic);
    }
    e_x=0;
    e_y=0;

    hpNum=0;//血量值

    hpIndex=22;//要播放第几个血量照片
}
