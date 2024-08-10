#include "emey.h"
#include "qdebug.h"

emey::emey(){
    //图片资源
    e_emey.load(":/planWar/emey(1).png");
    //敌机位置
    e_x=0;
    e_y=0;

    e_free=1;
    //isDie=0;

    e_speed=EMEY_SPEED;

    e_rect.setHeight(e_emey.height());
    e_rect.setWidth(e_emey.width());
    e_rect.moveTo(e_x,e_y);

    //血量初始化
    emey_hp.hpIndex=22;
    emey_hp.hpNum=100;
    maxHp=emey_hp.hpNum;
    //经验初始化
    expNum=60;

    fire_speed=FIRE_TIMER+50;
    //初始化子弹
    fire_num=EMEY_FIRE_NUM;
    emeyHurt=20;//初始化敌人子弹伤害

   fire f(":/planWar/emey_fire.png",emeyHurt);
    for (int i = 0; i < 20; ++i)
    {
        emey1_fires.push_back(f); // 使用相同的路径初始化数组中的每个元素
    }
}

void emey::updatePos()
{
//空闲敌机 不计算坐标
    if(e_free)
    return;

    e_y+=e_speed;

    emey_hp.e_y=e_y-30;//更新血条位置
    emey_hp.e_x=e_x;//更新血条位置

    e_rect.moveTo(e_x,e_y);

    if(e_y>=GAME_HEIGHT+e_rect.height())//出界
    {
        e_free=1;
        //更新生命值
        emey_hp.hpIndex=22;//敌人血量照片
        emey_hp.hpNum=maxHp;
    }
}

void emey::shoot()
{
    //累加时间间隔
    f_record++;

    //如果记录的数字未达到发射时间间隔，就不发射子弹
    if(f_record<fire_speed)
        return;

    //达到发射时间
    f_record=0;

    for(int i=0;i<fire_num;i++)
    {
        //如果是空闲子弹
        if(emey1_fires[i].f_free)
       {
           // 修改为非空闲
            emey1_fires[i].f_free=0;
            //初始化发射坐标
            emey1_fires[i].m_x=e_x+e_emey.width()/3;
            emey1_fires[i].m_y=e_y+50;
          //qDebug()<<"发射成功,子弹状态为"<<emey1_fires[i].f_free;
            break;
        }
    }
}

void emey::EmeyDiedEvent(boom booms[])
{
    e_free=1;//敌人状态
    for(int k=0;k<20;k++)
        emey1_fires[k].f_free=1;//敌人子弹置1

    //敌人的生命值重置
    emey_hp.hpIndex=22;//敌人血量照片
    emey_hp.hpNum=maxHp;

    //爆炸
    for(int k=0;k<BOOM_NUM;k++)
    {
        if(booms[k].b_free)
        {
            booms[k].b_free=0;
            //更新爆炸坐标
            booms[k].b_x=this->e_x;
            booms[k].b_y=this->e_y;

            break;
        }
    }
}


