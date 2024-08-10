#ifndef EMEY_H
#define EMEY_H
#include"config.h"
#include<QPixmap>
#include"fire.h"
#include "emeyHp.h"
#include"boom.h"
class emey
{
public:
    emey();
    void updatePos();//更新敌人位置
    void shoot();
    void EmeyDiedEvent(boom booms[]);//死亡事件
public:
    QPixmap e_emey;

    int e_x;
    int e_y;

    //移动速度
    int e_speed;
    int emeyHurt;//敌人伤害

    //血量相关
    hp emey_hp;//敌人血量
    int maxHp;//血量上限

    int expNum;//经验总量

    //敌人是否闲置,出边界或死亡就设置为闲置，
    bool e_free;
    //bool isDie;//检测是否死亡

    //边框（碰撞检测）
    QRect e_rect;

    int fire_num;//敌人子弹数量
    int fire_speed;//敌人发射速度

    QVector<fire>emey1_fires; //敌人子弹

    int f_record=0;//发射间隔记录


};

#endif // EMEY_H
