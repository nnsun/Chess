#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Piece.h"

class Board {
public:
    Board();
    string toString();
private:
    Piece* board[64];
};


#endif // BOARD_H
