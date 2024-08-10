#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include"me.h"
#include<QCursor>
#include<ctime>
Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    initScene();//初始化
    playGame();
}

//初始化函数
void Widget::initScene()
{
    //设置窗口尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);
    //加载图标
    setWindowIcon(QIcon("://planWar//icon.jpeg"));
    //加载边框
    //frame.load(":/planWar/frame.png");
    //设置定时器
    m_timer.setInterval(GAME_RATE);
    setMouseTracking(1);

    //随机数种子
    srand((unsigned int)time(NULL));

    //音效设置
    player=new QMediaPlayer(this);
    MusicBoom=new QMediaPlayer(this);
    up=new QMediaPlayer(this);

    out=new QAudioOutput(this);
    BoomOut=new QAudioOutput(this);
    upOut=new QAudioOutput(this);

    player->setAudioOutput(out);
    MusicBoom->setAudioOutput(BoomOut);
    up->setAudioOutput(upOut);

    player->setSource(QUrl("qrc:/music/planWar/play.mp3"));
    MusicBoom->setSource(QUrl("qrc:/music/planWar/booms.mp3"));
    up->setSource(QUrl("qrc:/music/planWar/up.mp3"));

    //MusicBoom->setPlaybackRate(10);
   // MusicBoom->setV

    player->setLoops(100000000);

    player->play();

    emeys_timer=EMEY_TIMER;

}

void Widget::playGame()//游戏启动
{
    //设置定时器
    m_timer.start();
    connect(&m_timer,&QTimer::timeout,[=](){
        //敌人出场
        emeyToScene();
        //敌人子弹发射
        for(int i=0;i<EMEY_NUM;i++){
            if(!emeys[i].e_free)
            emeys[i].shoot();
        }
        //发射子弹
        myPlane.shoot();
        //更新元素坐标
        updatePosition();
        //碰撞检测
        collisionDetecrion();
        //绘制到屏幕中
        update();
        //时间检测事件
        //timingEvent();
        //经验检测事件
        ExpEvent();
    });
}

void Widget::updatePosition()//更新
{
    //更新地图坐标
    m_map.mapPosition();

    // //更新计算所有非空闲子弹坐标
    for(int i=0;i<FIRE_NUM;i++)
    {
        //如果非空闲计算发射位置
        if(!myPlane.my_fire[i].f_free)
        {
            myPlane.my_fire[i].updatePos("me");
        }
    }

    //更新敌人坐标
    for(int i=0;i<EMEY_NUM;i++)
    {
        //如果非空闲计算敌人位置
        if(!emeys[i].e_free)
        {
            emeys[i].updatePos();
        }
    }

    //更新敌人子弹信息
    for(int i=0;i<EMEY_NUM;i++)
    {
        if(!emeys[i].e_free)//如果敌人不空闲
        {
            for(int j=0;j<EMEY_FIRE_NUM;j++)
            {
                  emeys[i].emey1_fires[j].updatePos("emey");
            }
        }
    }
    //更新敌人生命值


    //更新爆炸信息
    for(int i=0;i<BOOM_NUM;i++)
    {
        if(!booms[i].b_free)
            booms[i].updateInfo();
    }

}

void Widget::paintEvent(QPaintEvent *)//绘制
{

    QPainter p(this);
    //绘制地图
    p.drawPixmap(0,m_map.m_map1_pY,m_map.m_map1);
    p.drawPixmap(0,m_map.m_map2_pY,m_map.m_map2);

    //绘制边框
    //p.drawPixmap(-0,-50,frame);
    //绘制飞机
    p.drawPixmap(myPlane.m_x,myPlane.m_y,myPlane.m_plane);

    //绘制血条
    //qDebug()<<"当前播放图片下标为"<<myPlane.myHp.myHpIndex;
    p.drawPixmap(myPlane.myHp.e_x-2,myPlane.myHp.e_y,myPlane.myHp.h_myHp[myPlane.myHp.myHpIndex]);
    //绘制经验条
    p.drawPixmap(myPlane.myHp.e_x+267,myPlane.myHp.e_y,myPlane.myExp.pixExp[myPlane.myExp.expIndex]);
    //绘制等级
    if(myPlane.lv>=1&&myPlane.lv<=9)
    {
    QString lvPath=QString(":/planWar/%1.png").arg(myPlane.lv);
    p.drawPixmap(myPlane.myHp.e_x+225,myPlane.myHp.e_y-20,QPixmap(lvPath));
    }
    if(myPlane.lv>=10&&myPlane.lv<=99)
    {
        int leftLv=myPlane.lv/10;
        int righrLv=myPlane.lv%10;
        QString lvPathL=QString(":/planWar/%1.png").arg(leftLv);
        QString lvPathR=QString(":/planWar/%1.png").arg(righrLv);
        p.drawPixmap(myPlane.myHp.e_x+220,myPlane.myHp.e_y-20,QPixmap(lvPathL));
        p.drawPixmap(myPlane.myHp.e_x+220+QPixmap(lvPathL).width()/2+5,myPlane.myHp.e_y-20,QPixmap(lvPathR));
    }

    //绘制飞机受击框
    p.drawPixmap(myPlane.hit_R.x(),myPlane.hit_R.y(),myPlane.hurt);

    //绘制子弹
    for(int i=0;i<FIRE_NUM;i++)
    {
        //如果非空闲就绘制
        if(!myPlane.my_fire[i].f_free)
        {
            p.drawPixmap(myPlane.my_fire[i].m_x,myPlane.my_fire[i].m_y,myPlane.my_fire[i].m_fire);
        }
    }

    //绘制敌人和血条
    for(int i=0;i<EMEY_NUM;i++)
    {
        //如果非空闲绘制
        if(!emeys[i].e_free)
        {
            p.drawPixmap(emeys[i].e_x,emeys[i].e_y,emeys[i].e_emey);
            p.drawPixmap(emeys[i].emey_hp.e_x,emeys[i].emey_hp.e_y,emeys[i].emey_hp.h_hp[emeys[i].emey_hp.hpIndex]);
           // qDebug()<<"第"<<i<<"的敌人血条目前下标为"<<emeys[i].emey_hp.hpIndex;
        }
    }

    //绘制敌人子弹
    for(int i=0;i<EMEY_NUM;i++)
    {
        if(!emeys[i].e_free)
        {
           // qDebug()<<"敌人"<<i<<"出现";
            for(int j=0;j<EMEY_FIRE_NUM;j++)
            {
                //如果非空闲绘制
                if(!emeys[i].emey1_fires[j].f_free)
               // {
                   p.drawPixmap(emeys[i].emey1_fires[j].m_x,emeys[i].emey1_fires[j].m_y,emeys[i].emey1_fires[j].m_fire);
               // }
            }
        }
    }

    //绘制爆炸
    for(int i=0;i<BOOM_NUM;i++)
    {
        if(!booms[i].b_free){
            p.drawPixmap(booms[i].b_x,booms[i].b_y,
                         booms[i].p_boom[booms[i].b_index]);}
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event){

    //飞机移动
    this->setCursor(Qt::BlankCursor);

    int x=event->position().x()-65;
    int y=event->position().y()-myPlane.m_y/8;

    myPlane.setPos(x,y);
}

void Widget::collisionDetecrion()//碰撞检测
{
     //遍历非出厂敌人
    for(int i=0;i<EMEY_NUM;i++)
    {
        if(emeys[i].e_free)
            continue;

        //敌人和我方飞机碰撞
        if(emeys[i].e_rect.intersects(myPlane.hit_R))
        {
            float subHp= myPlane.maxHp*1.0*0.3;
            myPlane.myHp.myHpNum= myPlane.myHp.myHpNum-subHp;
            emeys[i].EmeyDiedEvent(booms);
            emeys[i].e_free=1;

            if(  myPlane.myHp.myHpNum<=0)
            {
                qDebug()<<"you died";
            }
            float per= myPlane.myHp.myHpNum*1.0/ myPlane.maxHp;//扣除百分比
            myPlane.myHp.myHpIndex=per*71;//切换到该百分比的生命
        }


        //遍历我方子弹
       for(int j=0;j<FIRE_NUM;j++)
       {

        //空闲子弹
        if(myPlane.my_fire[j].f_free)continue;

        //非空闲子弹
        if(emeys[i].e_rect.intersects(myPlane.my_fire[j].f_rect))//发生碰撞
        {

            emeys[i].emey_hp.hpNum-=myPlane.my_fire[j].hurt;//扣血
            float dec=emeys[i].emey_hp.hpNum*1.0/emeys[i].maxHp;//扣除百分比
            emeys[i].emey_hp.hpIndex=dec*23;//切换到该百分比的生命
            //qDebug()<<"敌人血量："<<emeys[i].emey_hp.hpNum<<"，扣除百分比："<<dec<<"轮转到第几张图："<<emeys[i].emey_hp.hpIndex;
            myPlane.my_fire[j].f_free=1;

            //敌方生命值降到0，触发死亡事件
            if( emeys[i].emey_hp.hpNum<=0)
            {
                 MusicBoom->play();
                emeys[i].EmeyDiedEvent(booms);//死亡事件
                myPlane.myExp.curExp+=emeys[i].expNum;//增加经验
            }
        }
    }

    //遍历敌方子弹
    for(int k=0;k<EMEY_FIRE_NUM;k++)
      {
          if(emeys[i].emey1_fires[k].f_rect.intersects(myPlane.hit_R))
        {
            if(emeys[i].emey1_fires[k].f_free)continue;//空闲跳过


            myPlane.myHp.myHpNum-=emeys[i].emey1_fires[k].hurt;

            if(  myPlane.myHp.myHpNum<=0)
            {
                qDebug()<<"you died";
            }
            float per= myPlane.myHp.myHpNum*1.0/ myPlane.maxHp;//扣除百分比
            myPlane.myHp.myHpIndex=per*71;//切换到该百分比的生命
            //qDebug()<<"扣除百分比"<<per<<"剩余生命值"<<myPlane.myHp.myHpNum<<"轮播到图片"<<myPlane.myHp.myHpIndex;
            emeys[i].emey1_fires[k].f_free=1;//敌人子弹置1
        }
      }
    }

}

void Widget::emeyToScene()//敌人出现
{
    e_record++;
    //未到出场时间间隔
    if(e_record<emeys_timer){
        return;}

    e_record=0;
    for(int i=0;i<EMEY_NUM;i++)
    {
        if(emeys[i].e_free){
            emeys[i].e_free=0;
        emeys[i].e_x=rand()%(GAME_WIDTH-emeys[i].e_rect.width());
        emeys[i].e_y=-emeys[i].e_rect.height();
        break;
        }
    }
}

void Widget::ExpEvent()
{
    while(myPlane.myExp.curExp>=myPlane.myExp.curNeed)//升级了
    {
        myPlane.myExp.curExp-=myPlane.myExp.curNeed;//当前剩余经验
        myPlane.myExp.nextNeed=myPlane.lv*100;//下一级升级所需经验
        myPlane.lv++;//升级
        up->play();
        lvUpEvent();
        myPlane.myExp.curNeed= myPlane.myExp.nextNeed;//更新下次的当前所需经验值
        //qDebug()<<"升级";
        //我方升级效果
        for(int i=0;i<myPlane.my_fire.size();i++){
             myPlane.my_fire[i].f_speed+=5;
            myPlane.my_fire[i].hurt+=20;}
        if(myPlane.fire_timer>0)
        myPlane.fire_timer-=10;
        myPlane.fire_num+=3;

        emeys_timer-=30;//敌人出场间隔变短

    }
    //我方无法升级
        float pre=myPlane.myExp.curExp*1.0/myPlane.myExp.curNeed;
        myPlane.myExp.expIndex=70*pre;
       // qDebug()<<myPlane.myExp.expIndex;
}




void Widget::lvUpEvent()
{

}


Widget::~Widget()
{
    delete ui;
}
