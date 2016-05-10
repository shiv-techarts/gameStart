#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>


class Player:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsRectItem * parent = 0);
    void keyPressEvent(QKeyEvent *event); //check for pressed key
public slots:
    void spawn(); //enemy entry to the scene
private:
    QMediaPlayer * bullet; //audio entrance to scene
};

#endif // MYRECT_H

