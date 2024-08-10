#include "boom.h"
#include "qdebug.h"
#include"config.h"
boom::boom()
{
    //图片
    for(int i=1;i<=BOOM_MAX;i++)
    {
        QString str=QString(":/planWar/boom%1.png").arg(i);
        QPixmap pic=QPixmap(str);
        p_boom.push_back(pic);
    }

     b_x=0;
     b_y=0;

     b_free=1;

    //爆炸间隔设置
     b_Record=0;

    //爆炸时加载的图片下标
     b_index=1;
}

void boom::updateInfo()
{
//空闲不爆炸
    if(b_free)return;

    b_Record++;

    if(b_Record<BOOM_TIMER)//如果爆炸间隔的记录时间没有到爆炸间隔，就不切图
        return;

    b_Record=0;
    //切图
    b_index++;
    if(b_index>BOOM_MAX-1)//播放完了
    {
        b_index=0;
        b_free=1;
    }
}
