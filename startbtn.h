#ifndef STARTBTN_H
#define STARTBTN_H

#include "qpushbutton.h"
#include <QWidget>

class startBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit startBtn(QWidget *parent = nullptr);

signals:
};

#endif // STARTBTN_H
