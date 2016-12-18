#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Piece.h"
#include <utility>
using namespace std;

class Board {
public:
    Board();
    Piece* getPieceAt(int);
    void movePiece(int, int);
	static pair<int, int> rowsColsAway(int, int);	
    string toString();
private:
    Piece* board[64];
};


#endif // BOARD_H
