#include "Score.h"
#include <QFont>

Score::Score(QGraphicsTextItem *parent) : QGraphicsTextItem(parent) {
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setFont(QFont("times",16));
    setDefaultTextColor(Qt::white);
}


void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}


int Score::getScore()
{
    return score;
}

void Score::setScore()
{
    score = 0;
}
