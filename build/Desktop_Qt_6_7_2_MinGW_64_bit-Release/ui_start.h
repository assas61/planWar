/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:

    void setupUi(QWidget *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName("start");
        start->resize(400, 750);
        start->setMinimumSize(QSize(400, 750));
        start->setMaximumSize(QSize(400, 750));

        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QWidget *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
