#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Piece.h"

class Board {
public:
    Board();
    Piece* getPieceAt(int);
    void movePiece(int, int);
    string toString();
private:
    Piece* board[64];
};


#endif // BOARD_H
