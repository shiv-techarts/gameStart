#include "Game.h"
#include "Health.h"
#include <QFont>

extern Game * game;

Health::Health(QGraphicsTextItem *parent) : QGraphicsTextItem(parent) {
    health = 3;
    checkHealth = 0;
    setPlainText(QString("Health: ") + QString::number(health)); //number to string conversion
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::white);
}


void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::white);
}


int Health::getHealth()
{
    return health;
}

int Health::gameOver()
{
    //setPos(350,300);
    setPlainText(QString("Game Over"));
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::white);
    checkHealth = -1;
    return 0;
}

void Health::setHealth()
{
    health = 3;
}
