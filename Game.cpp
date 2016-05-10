#include "Game.h"

QMediaPlayer * music;

Game::Game(QWidget * parent) {
    QGraphicsScene * scene = new QGraphicsScene();

    Player * player = new Player();

    //setBackgroundBrush(QBrush(QImage(":/images/bgImage.png")));
    QPixmap pim(":/images/bgImage.png");
    scene->setBackgroundBrush(pim.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //player->setRect(0,0,100,100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player); //adding player to the scene
    //add score
    score = new Score();
    scene->addItem(score); //adding score to the scene
    health = new Health();
    health->setPos(health->x(),y() + 25);
    scene->addItem(health); //adding health to the scene

    QGraphicsView * view = new QGraphicsView(scene);
    //setting of scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos((view->width()-100)/2,view->height()-/*player->rect().height()*/100);

    QTimer * timer = new QTimer();
    timer->connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //background music

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    if(music->state() == QMediaPlayer::PlayingState) {
        music->setPosition(0);
        music->play();
    }
    else if(music->state() == QMediaPlayer::StoppedState){
        music->play();
    }

    //show();
}
