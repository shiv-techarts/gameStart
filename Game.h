#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QImage>
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Health.h"


class Game: public QGraphicsView {
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
};

#endif // GAME_H
