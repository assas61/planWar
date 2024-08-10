#ifndef FIRE_H
#define FIRE_H
#include<QPixmap>
#include"config.h"
class fire
{
public:
    fire(QString,int);

    void updatePos(QString name);//更新子弹位置
public:
    QPixmap m_fire;

    int m_x;
    int m_y;

    //移动速度
    int f_speed;
    //子弹是否闲置,出边界就设置为闲置，当需要发射子弹后设置为非限制，这样可以防止资源泄漏
    bool f_free;
    //子弹边框（碰撞检测）
    QRect f_rect;
    int hurt;//伤害
};

#endif // FIRE_H
