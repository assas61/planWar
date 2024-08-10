#ifndef ME_H
#define ME_H
#include"QPixmap"
#include"QRect"
#include"fire.h"
#include "myhp.h"
#include<QVector>
class me
{
public:
    me();
    void shoot();//发射子弹
    void setPos(int x,int y);//位置信息
public:
    QPixmap m_plane;//飞机图
    QPixmap hurt;//受击图

    int m_x;//飞机坐标
    int m_y;


    int fire_num;//子弹容量
    int fire_timer;//子弹发射间隔

    myHp myHp;//血量
    int maxHp;//我方最高血量
    int lv;//等级
    int myHurt;//伤害

    //经验值
     struct exps{
        int curExp;//当前经验
        int curNeed;//当前升级所需经验值
        int nextNeed;//下一次升级所需经验
        QVector<QPixmap>pixExp;//经验图
        int expIndex;//所需经验图的下标
    };
     exps myExp;


    //飞机的受击框
    QRect hit_R;

    //fire my_fire[FIRE_NUM];
    QVector<fire>my_fire;//弹匣


    int f_record=0;//发射间隔记录

};

#endif // ME_H
