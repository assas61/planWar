#ifndef MAP_H
#define MAP_H
#include<QPixmap>
class map
{
public:
    map();
    //地图坐标设置
    void mapPosition();

    //地图图片对象
    QPixmap m_map1;
    QPixmap m_map2;

    //地图y轴坐标
    int m_map1_pY;
    int m_map2_pY;

    //地图滚动速度
    int m_scrool_speed;
};

#endif // MAP_H
