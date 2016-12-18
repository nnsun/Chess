#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Game.h"
#include <QDebug>

MainWindow::MainWindow(Game* game) :
    QMainWindow(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(720, 540));
    QWidget::setWindowTitle("Qt Chess");

    container = new QWidget(this);
    setCentralWidget(container);
    box = new QVBoxLayout(container);

    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignCenter);
    box->addLayout(grid);

    handler = game;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            buttons[i][j] = new QPushButton(container);
            buttons[i][j]->setFixedSize(QSize(64, 64));
            grid->setSpacing(0);
            grid->addWidget(buttons[i][j], i, j);
            string style = "";
            if (i == 1) {
                style += "background-image: url(:/img/pawn_black.png);";
            }
            else if (i == 6) {
                style += "background-image: url(:/img/pawn_white.png);";
            }
            else if (i == 0) {
                switch (j) {
                case 0:
                case 7:
                    style += "background-image: url(:/img/rook_black.png);";
                    break;
                case 1:
                case 6:
                    style += "background-image: url(:/img/knight_black.png);";
                    break;
                case 2:
                case 5:
                    style += "background-image: url(:/img/bishop_black.png);";
                    break;
                case 3:
                    style += "background-image: url(:/img/queen_black.png);";
                    break;
                case 4:
                    style += "background-image: url(:/img/king_black.png);";
                }

            }
            else if (i == 7) {
                switch (j) {
                case 0:
                case 7:
                    style += "background-image: url(:/img/rook_white.png);";
                    break;
                case 1:
                case 6:
                    style += "background-image: url(:/img/knight_white.png);";
                    break;
                case 2:
                case 5:
                    style += "background-image: url(:/img/bishop_white.png);";
                    break;
                case 3:
                    style += "background-image: url(:/img/queen_white.png);";
                    break;
                case 4:
                    style += "background-image: url(:/img/king_white.png);";
                }
            }

            if ((i + j) % 2 == 0) {
                style += "background-color: white;";
            }
            else {
                style+= "background-color: gray;";
            }

            buttons[i][j]->setStyleSheet(QString::fromStdString(style));

            signalMap[i][j] = new QSignalMapper(this);
            connect(buttons[i][j], SIGNAL(clicked()), signalMap[i][j], SLOT(map()));
			signalMap[i][j]->setMapping(buttons[i][j], i * 8 + j);
			connect(signalMap[i][j], SIGNAL(mapped(int)), this, SLOT(buttonClicked(int)));

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked(int tile) {
	tuple<int, int, string, bool> redrawTuple = handler->handleMove(tile);
	if (get<0>(redrawTuple) >= 0) {
		updateBoard(get<0>(redrawTuple), get<1>(redrawTuple), get<2>(redrawTuple), get<3>(redrawTuple));		
	}
}

void MainWindow::updateBoard(int prevTile, int nextTile, string pieceName, bool white) {	
	int prevRow = prevTile / 8;
	int prevCol = prevTile % 8;
	
	int nextRow = nextTile / 8;
	int nextCol = nextTile % 8;
	
	string prevTileStyle = "";
	string nextTileStyle = "";
	
	if ((prevRow + prevCol) % 2 == 0) {
		prevTileStyle += "background-color: white;";
	}
	else {
		prevTileStyle += "background-color: gray;";
	}
	
	if ((nextRow + nextCol) % 2 == 0) {
		nextTileStyle += "background-color: white;";
	}
	else {
		nextTileStyle += "background-color: gray;";
	}
	
	nextTileStyle += "background-image: url(:/img/";
	nextTileStyle += pieceName + "_";
	nextTileStyle += white ? "white.png);" : "black.png);";
	
	buttons[prevRow][prevCol]->setStyleSheet(QString::fromStdString(prevTileStyle));
	buttons[nextRow][nextCol]->setStyleSheet(QString::fromStdString(nextTileStyle));
}
