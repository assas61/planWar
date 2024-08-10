#ifndef MYHP_H
#define MYHP_H

#include "qpixmap.h"
#include"config.h"
class myHp
{
public:
    myHp();

public:

    QVector<QPixmap> h_myHp;

    int e_x;
    int e_y;

    int myHpNum;//血量值

    int myHpIndex;//要播放第几个血量照片
};

#endif // MYHP_H
