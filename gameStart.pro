#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T19:24:22
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gameStart
TEMPLATE = app


SOURCES += \
    main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Player.cpp \
    Score.cpp \
    Health.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Player.h \
    Score.h \
    Health.h

RESOURCES += \
    res.qrc
