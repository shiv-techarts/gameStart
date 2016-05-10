#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = 0);
    Bullet(int);
    //~Bullet();
public slots: //member function that will responde to a signal
    void move();
};

#endif // BULLET_H
