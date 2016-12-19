#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <utility>
using namespace std;

class Game {
public:
    Game();
    bool isWhiteTurn();
    Board* getBoard();
    void setPlayerTurn();
    tuple<int, int, string, bool> handleMove(int);
	bool isLegalMove(int, Piece*, int);
private:
    bool whiteTurn;
    Board* board;
    int prevTile;
};

#endif // GAME_H
