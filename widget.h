#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#include<map.h>
#include"QPainter"
#include"me.h"
#include"QMouseEvent"
#include"fire.h"
#include"emey.h"
#include"boom.h"
#include<QtMultimedia>
#include<QAudioOutPut>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void initScene();//初始化场景

    //启动游戏
    void playGame();
    //更新所有游戏元素的坐标
    void updatePosition();
    //绘制到屏幕中
    void paintEvent(QPaintEvent*);
    //键盘控制飞机移动
    void mouseMoveEvent(QMouseEvent*);
    //碰撞检测
    void collisionDetecrion();
    //敌人出厂
    void emeyToScene();
    //时间检测事件
    void timingEvent();
    //经验检测事件
    void ExpEvent();
    //升级事件
    void lvUpEvent();
public:
    //定时器
    QTimer m_timer;
    //地图
    map m_map;
    //飞机
    me myPlane;
    //边框{生命值和经验值}
    QPixmap frame;

    //敌人相关
    emey emeys[EMEY_NUM];//敌人数量
    int e_record=0;//敌人出现间隔定时器
    int emeys_timer;//敌人出现间隔

   //爆炸相关
    boom booms[BOOM_NUM];

   //音乐相关
    QMediaPlayer *player=nullptr;//音乐主体
    QAudioOutput*out=nullptr;

    QMediaPlayer *MusicBoom=nullptr;//音乐主体
    QAudioOutput*BoomOut=nullptr;

    QMediaPlayer *up=nullptr;//升级主体
    QAudioOutput*upOut=nullptr;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
