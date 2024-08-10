#include "me.h"
#include"config.h"
#include "qdebug.h"
me::me() {
    //初始化加载图片
    m_plane.load("://planWar//me.png");
    hurt.load(":/planWar/hurt.png");
    //初始化坐标
    m_x=GAME_WIDTH/2-m_plane.width()/2;
    m_y=GAME_HEIGHT-m_plane.height();
    //初始化受击框
    hit_R.setWidth(hurt.width());
    hit_R.setHeight(hurt.height());
    hit_R.moveTo(m_x+m_plane.width()/4+21,m_y+m_plane.height()/4+30);

    myHurt=25;//初始化伤害值

    //初始化子弹容器
    fire_num=FIRE_NUM;
    fire f("://planWar//fire2.png",myHurt);
    for(int i=0;i<fire_num;i++)
    {
        my_fire.push_back(f);
    }
    fire_timer=FIRE_TIMER;

    //初始化血量
     maxHp=100;//血量最大值
     myHp.myHpNum=maxHp;//血量
     myHp.myHpIndex=70;//血量替换图

     lv=1;//等级

     //经验初始化
     myExp.curExp=0;
     myExp.curNeed=100;
     myExp.nextNeed=100;
     myExp.expIndex=0;
     for(int i=1;i<=71;i++)
     {
        QString path=QString(":/planWar/myExp%1.png").arg(i);
        myExp.pixExp.push_back(QPixmap(path));
     }

}

void me::shoot()
{
    //判断子弹容量是否够用
    //qDebug()<<"未扩容"<<my_fire.size();
    if(my_fire.size()<fire_num)
    {
        fire f("://planWar//fire1(1).png",myHurt);
        for(int i=1;i<=fire_num-my_fire.size();i++)
        {
            my_fire.push_back(f);
            qDebug()<<"已扩容"<<i<<"次"<<my_fire.size();
        }

    }

    //累加时间间隔
    f_record++;

    //如果记录的数字未达到发射时间间隔，就不发射子弹
    if(f_record<fire_timer)
        return;

    //达到发射时间
    f_record=0;
    for(int i=0;i<fire_timer;i++)
    {
        //如果是空闲子弹
        if(my_fire[i].f_free)
        {
            //修改为非空闲
            my_fire[i].f_free=0;
            //初始化发射坐标
            my_fire[i].m_x=m_x+m_plane.width()/3+7;
            my_fire[i].m_y=m_y-50;
            break;
        }
    }

}
void me::setPos(int x, int y)
{
    m_x=x;
    m_y=y;
    hit_R.moveTo(m_x+m_plane.width()/4+21,m_y+m_plane.height()/4+30);
}

