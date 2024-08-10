#include "map.h"
#include"config.h"
map::map()
{
//初始化加载地图的图像
    m_map1.load("://planWar//scene12.jpg");
m_map2.load("://planWar//scene12.jpg");

//初始化地图y轴坐标
m_map1_pY=-GAME_HEIGHT;
m_map2_pY=0;

//地图滚动速度
m_scrool_speed=MAP_SCROLL_SPEED;
}

//地图坐标设置
void map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_pY+=m_scrool_speed;
    m_map2_pY+=m_scrool_speed;
    //处理第二张图片滚动位置
    if(m_map2_pY>=GAME_HEIGHT){
        m_map2_pY=0;}

    if(m_map1_pY>=0){
        m_map1_pY=-GAME_HEIGHT;}

}
