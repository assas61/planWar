#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString a);

    void replaceIcon(QString a);

    QPixmap pix;
signals:
};

#endif // MYPUSHBUTTON_H
