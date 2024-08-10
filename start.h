#ifndef START_H
#define START_H
#include <QWidget>
#include<QPainter>
#include<widget.h>
#include<QtMultimedia>
#include<QAudioOutPut>
namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();
    void paintEvent(QPaintEvent*);
    // void mouseMoveEvent(QMouseEvent*);

    Widget *w=nullptr;//将widget放入他的成员中


    QMediaPlayer *btn=nullptr;//按钮
    QAudioOutput*out_btn=nullptr;

    QMediaPlayer *player=nullptr; //音乐主体
    QAudioOutput*out=nullptr;
private:
    Ui::start *ui;
};

#endif // START_H
