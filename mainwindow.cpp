#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Game.h"

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
    rowSelection = -1;
    columnSelection = -1;
    currentPiece = nullptr;

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
            signalMap[i][j]->setMapping(buttons[i][j], i * 10 + j);
            connect(signalMap[i][j], SIGNAL(mapped(int)), this, SLOT(buttonClicked(int)));

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked(int pos) {
    int row = pos / 10;
    int column = pos % 10;
    int tile = row * 8 + column;

    if (rowSelection == -1 && columnSelection == -1 && currentPiece == nullptr) {
        if (handler->getBoard()->getPieceAt(tile) != nullptr) {
            rowSelection = row;
            columnSelection = column;
        }
        currentPiece = handler->getBoard()->getPieceAt(tile);
    }
    else {
        handler->getBoard()->movePiece(rowSelection * 8 + columnSelection, tile);

        string prevTileStyle = "";
        string nextTileStyle = "";
        if ((rowSelection + columnSelection) % 2 == 0) {
            prevTileStyle += "background-color: white;";
        }
        else {
            prevTileStyle += "background-color: gray;";
        }

        if ((row + column) % 2 == 0) {
            nextTileStyle += "background-color: white;";
        }
        else {
            nextTileStyle += "background-color: gray;";
        }



        nextTileStyle += "background-image: url(:/img/";
        nextTileStyle += currentPiece->getPieceName() + "_";
        if (currentPiece->isWhite()) {
            nextTileStyle += "white.png);";
        }
        else {
            nextTileStyle += "black.png);";
        }

        buttons[rowSelection][columnSelection]->setStyleSheet(QString::fromStdString(prevTileStyle));
        buttons[row][column]->setStyleSheet(QString::fromStdString(nextTileStyle));

        rowSelection = -1;
        columnSelection = -1;

        handler->setPlayerTurn();
        currentPiece = nullptr;
    }
}
