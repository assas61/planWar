QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boom.cpp \
    emey.cpp \
    emeyHp.cpp \
    fire.cpp \
    main.cpp \
    map.cpp \
    me.cpp \
    myhp.cpp \
    mypushbutton.cpp \
    start.cpp \
    widget.cpp

HEADERS += \
    boom.h \
    config.h \
    emey.h \
    emeyHp.h \
    fire.h \
    map.h \
    me.h \
    myhp.h \
    mypushbutton.h \
    start.h \
    widget.h

FORMS += \
    start.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    hp.qrc \
    image.qrc \
    lvNum.qrc \
    music.qrc \
    myExp.qrc \
    myHp.qrc

