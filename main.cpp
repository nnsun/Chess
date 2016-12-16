#include "mainwindow.h"
#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game* game = new Game();
    MainWindow* w = new MainWindow(game);
    w->show();

    return a.exec();
}
