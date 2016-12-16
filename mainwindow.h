#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Game*);
    ~MainWindow();

private:
    Game* handler;
    Ui::MainWindow *ui;
    QWidget* container;
    QGridLayout* grid;
    QVBoxLayout* box;
    QPushButton* buttons[8][8];
    QSignalMapper *signalMap[8][8];
    int rowSelection;
    int columnSelection;
    Piece* currentPiece;

private slots:
    void buttonClicked(int );
};

#endif // MAINWINDOW_H
