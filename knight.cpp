#include "Knight.h"
#include "Board.h"

Knight::Knight(bool white) {
    this->white = white;
    pieceID = 'N';
    pieceName = "knight";
}

bool Knight::checkMove(int oldTile, int newTile) {
	pair<int, int> distance = Board::rowsColsAway(oldTile, newTile);
	if ((abs(distance.first) == 2 && abs(distance.second) == 1) || 
			(abs(distance.first) == 1 && abs(distance.second) == 2)) {
		return true;
	}
	return false;
}
