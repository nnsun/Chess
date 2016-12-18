#include "King.h"
#include "Board.h"

King::King(bool white) {
    this->white = white;
    pieceID = 'K';
    pieceName = "king";
}

bool King::checkMove(int oldTile, int newTile) {
	pair<int, int> distance = Board::rowsColsAway(oldTile, newTile);
	if ((abs(distance.first) == 0 || abs(distance.first) == 1) && 
			(abs(distance.second) == 0 || abs(distance.second) == 1)) {
		return true;
	}
	return false;
}
