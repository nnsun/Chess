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
	static int rowsColsToPos(int, pair<int, int>);
	bool validatePawnMove(int, int, int);
	bool validateBishopMove(int, int, int);
	bool validateRookMove(int, int, int);
	bool validateQueenMove(int, int, int);
	string toString();	
private:
    Piece* board[64];
};


#endif // BOARD_H
