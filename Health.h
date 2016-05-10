#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem {
public:
    Health(QGraphicsTextItem * parent = 0);
    void decrease();
    int getHealth();
    int gameOver(); //display game over message
    void setHealth(); //set health after game over
    int checkHealth; //public variable
private:
    int health;
};

#endif // HEALTH_H
