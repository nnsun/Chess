#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
    Game();
    bool getPlayerTurn();
    void setPlayerTurn();
    bool getPlayerChecked();
    Board* getBoard();
private:
    bool playerTurn;
    bool whiteCheck;
    bool blackCheck;
    Board* board;
};

#endif // GAME_H
