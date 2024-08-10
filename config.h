#ifndef CONFIG_H
#define CONFIG_H

//*****游戏数据配置
#define  GAME_WIDTH 492//宽度
#define GAME_HEIGHT 812//高度
#define GAME_TITLE "雷霆战机 v2.0"
#define GAME_RATE 8//定时器刷新时间

//*****地图数据配置
#define MAP_SCROLL_SPEED 2

//******子弹数据配置
#define FIRE_SPEED 2//子弹速度
#define FIRE_NUM 20//子弹数量
#define FIRE_TIMER 100//子弹发射间隔

//*******敌人数据配置
#define EMEY_SPEED 1//移动速度
#define EMEY_NUM 20//总数量
#define EMEY_TIMER 500//敌人出现的间隔
#define EMEY_FIRE_NUM 20//敌人子弹数量


//*******爆炸数据配置
#define BOOM_NUM 100//爆炸数量
#define BOOM_MAX 8//爆炸图片数
#define BOOM_TIMER 5//图片播放速度

//*******血量数据配置
#define HP_NUM 100
#define HP_MAX 23

#endif // CONFIG_H
