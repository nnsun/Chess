#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
    Game();
    bool isWhiteTurn();
    void setPlayerTurn();
    Board* getBoard();
private:
    bool whiteTurn;
    Board* board;
};

#endif // GAME_H
