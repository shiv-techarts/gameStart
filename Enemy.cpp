#include <QList>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include "Game.h"

//#define PLAYER_COL

extern Game * game;
extern QMediaPlayer * music;

//for constant speed
Enemy::Enemy(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem(parent) {
    //random position of enemy
    //srand(time(0));
    if(music->state() == QMediaPlayer::PlayingState) {
        music->setPosition(0);
        music->play();
    }
    else if(music->state() == QMediaPlayer::StoppedState){
        music->play();
    }

    //random position of enemy
    int random_pos = rand() % 700;
    setPos(random_pos,0);

    //create a rect
    //setRect(0,0,100,100);
    //set image for an enemy
    setPixmap(QPixmap(":/images/enemy.png"));

    //connect
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

//for varing speed
Enemy::Enemy(int nSpeed) {
    //create a rect
    //setRect(0,0,100,100);
    //set image for an enemy
    setPixmap(QPixmap(":/images/enemy.png"));
    //connect
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(nSpeed);

}


void Enemy::move() {

//testing a code section
#ifdef PLAYER_COL
    //collision with player
    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for(auto i : colliding_items) { //C++11
       for(int i = 0; i < colliding_items.size(); i++) {
        if(typeid(*(colliding_items[i])) == typeid(Player)) {
            //remove items

            int val = game->health->getHealth();
            //display game over
            if(val == 0) {
                setPos(350,300);
                setPlainText(QString("Game Over"));
                setFont(QFont("times",16));
                setDefaultTextColor(Qt::black);
            } else {
                game->health->decrease();
            }
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
#else
    setPos(x(),y()+5);
    if(pos().y() - /*rect().height()*/100 > 550) {

        int val = game->health->getHealth();
        if(val == 0) {
            game->health->gameOver();
        }
        else {
            game->health->decrease();
        }
        scene()->removeItem(this);
        delete this;
    }
#endif
}
