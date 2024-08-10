#include "start.h"
#include "ui_start.h"
#include<config.h>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include<widget.h>
start::start(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::start)
{
    ui->setupUi(this);
setMouseTracking(1);
    //设置窗口尺寸
        setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon("://planWar//icon.jpeg"));

    //初始化按钮
        MyPushButton *startBtn=new MyPushButton(":/planWar/btn_start.png");
    startBtn->setParent(this);

    //设置音乐
    btn=new QMediaPlayer(this);
    player=new QMediaPlayer(this);

    out=new QAudioOutput(this);
    out_btn=new QAudioOutput();

    player->setAudioOutput(out);
    btn->setAudioOutput(out_btn);

    player->setSource(QUrl("qrc://music//planWar//main.mp3"));
    btn->setSource(QUrl("qrc:/music/planWar/start.mp3"));

    player->setLoops(100);
    player->play();

    //按钮作用
    connect(startBtn,&QPushButton::clicked,[=](){
        startBtn->setEnabled(0);//禁止再次点击
        w=new Widget();
        startBtn->replaceIcon(":planWar/btn_start_push.png");
        btn->play(); 
        // 使用 QTimer 来在100毫秒后执行操作2
        QTimer::singleShot(500, this, [=]() {
              startBtn->setEnabled(1);//取消禁止再次点击
            this->hide();
            player->stop();
            w->show();
        });

    });

}


void start::paintEvent(QPaintEvent *)//绘制
{
    //绘制背景
    QPainter painter(this);
    QPixmap pix;
    pix.load("://planWar//startScene.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
 }

// void start::mouseMoveEvent(QMouseEvent *e)
// {
//     player=new QMediaPlayer(this);
//     out=new QAudioOutput(this);
//     player->setAudioOutput(out);
//     out->setVolume(100);
//     player->setSource(QUrl("qrc://music//planWar//start.mp3"));
//     int i=0;
//     if(e->pos().x()>=GAME_WIDTH/2-QPixmap(":/planWar/btn_start.png").width()/10&&
//         e->pos().x()<=GAME_WIDTH/2-QPixmap(":/planWar/btn_start.png").width()/10+QPixmap(":/planWar/btn_start.png").width()/2&&
//         e->pos().y()>=GAME_HEIGHT/2+200&&
//         e->pos().y()<=GAME_HEIGHT/2+150+QPixmap(":/planWar/btn_start.png").height()/4)
//     {
//         player->play();
//     }
//     else player->stop();
// }

start::~start()
{
    delete ui;
}



