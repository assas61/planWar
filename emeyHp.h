#ifndef EMEYHP_H
#define EMEYHP_H

#include "qpixmap.h"
#include<QVector>
#include"config.h"
class hp
{
public:
    hp();
    //void updateInfo();//更新血量图位置
public:

    QVector<QPixmap> h_hp;

    int e_x;
    int e_y;

    int hpNum;//血量值

    int hpIndex;//要播放第几个血量照片
};

#endif // EMEYHP_H
