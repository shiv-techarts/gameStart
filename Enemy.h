#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent = 0);
    Enemy(int);
    //~Enemy();
public slots: //member function that will responde to a signal
    void move();
};

#endif // ENEMY_H
