#include "fire.h"
#include "qdebug.h"

fire::fire(QString path,int hurts) {
    //加载图片
    m_fire.load(path);

    //子弹坐标
    m_x=GAME_WIDTH*0.5-m_fire.width()*0.5;
    m_y=GAME_HEIGHT*0.5;

    //子弹状态
    f_free=1;//空闲

    //子弹速度
    f_speed=FIRE_SPEED;

    hurt=hurts;//伤害值

    //子弹框架
    f_rect.setWidth(m_fire.width());
    f_rect.setHeight(m_fire.height());
    f_rect.moveTo(m_x,m_y);

}

void fire::updatePos(QString name)
{


    //空闲状态下不用计算坐标
    if(f_free)
    {
        return;
    }

   //如果是本人调用
    if(name=="me")
    {
    //非空闲向上移动
    m_y-=f_speed;
    f_rect.moveTo(m_x,m_y);

    if(m_y<=-f_rect.height())
        f_free=1;//子弹超出窗口设置为空闲
    }
    if(name=="emey")//如果是敌人调用
    {
        //qDebug()<<"敌人子弹发射";
        //非空闲向下移动
        m_y+=f_speed;
        f_rect.moveTo(m_x,m_y);

        if(m_y>=GAME_HEIGHT+f_rect.height()){
            f_free=1;//子弹超出窗口设置为空闲
        }
    }
}

