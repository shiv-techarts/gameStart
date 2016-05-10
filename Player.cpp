//#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

extern Game * game;
//#define SPEED //for varing speed

Player::Player(QGraphicsRectItem *parent): QGraphicsPixmapItem(parent) {
    bullet = new QMediaPlayer();
    bullet->setMedia(QUrl("qrc:/sounds/fire.wav"));
    setPixmap(QPixmap(":/images/plane.png"));

}

void Player::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left && pos().x() > 0) {
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right && pos().x() + /*rect().width()*/100 < 800) {
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Escape) {
        game->health->setHealth();
        game->score->setScore();
        game->health->checkHealth = 0;
    }
    /*
    else if(event->key() == Qt::Key_Up) {
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down) {
        setPos(x(),y()+10);
    }
    */
    else if(event->key() == Qt::Key_Space) {
        if(bullet->state() == QMediaPlayer::PlayingState) {
            bullet->setPosition(0);
        }
        else if(bullet->state() == QMediaPlayer::StoppedState){
            bullet->play();
        }

#ifdef SPEED

        static int speed = 70;
        try {
            if(speed < 10)
                throw speed;
        } catch(int) {
            speed = 70;
        }
        Bullet * bullet = new Bullet(speed--);

#else
        //create a Bullet
         Bullet * bullet = new Bullet();
#endif
        //qDebug() << "Bullet is Created";
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void Player::spawn() {
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
