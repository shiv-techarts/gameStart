//#include <iostream>
#include <QList>
#include <typeinfo>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

extern Game * game;

//for constant speed
Bullet::Bullet(QGraphicsItem * parent) : QObject() , QGraphicsPixmapItem(parent)  {
    //create a rect
    //setRect(45,0,10,20);

    //set image for bullet
    setPixmap(QPixmap(":/images/bullet.png"));
    //connect
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

//for varing speed
Bullet::Bullet(int nSpeed) {
    //create a rect
    //setRect(45,0,10,10);

    //set image for bullet
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(nSpeed);

}


void Bullet::move() {
    //collision with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for(auto i : colliding_items) { //C++11
       for(int i = 0; i < colliding_items.size(); i++) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            //remove items
            if(game->health->checkHealth == -1) {
                game->health->gameOver(); //game over
                game->health->checkHealth = 0; //health set
            }
            else {
                game->score->increase();
            }
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet
    setPos(x(),y()-10);
    if(pos().y() + /*rect().height()*/100 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
