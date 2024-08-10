#ifndef BOOM_H
#define BOOM_H

#include<QPixmap>
#include<QVector>
class boom
{
public:
    boom();
    void updateInfo();//更新爆炸图位置

public:
    QVector<QPixmap> p_boom;

    int b_x;
    int b_y;

    bool b_free;

    //爆炸间隔设置
    int b_Record;

    //爆炸时加载的图片下标
    int b_index;
};

#endif // BOOM_H
