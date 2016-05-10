/*
 * 08 May 2016
 * Shiv Pratap Singh
 * QTCreator
 * OS Compatibility: Linux, Microsoft Windows
 * Architecture: x86
 * A Starters Game
*/

#include <QApplication>
#include "Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    //game->show();

    return a.exec();
}
