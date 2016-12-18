#include "Queen.h"
#include "Board.h"

Queen::Queen(bool white) {
    this->white = white;
    pieceID = 'Q';
    pieceName = "queen";
}

bool Queen::checkMove(int oldTile, int newTile) {
	pair<int, int> distance = Board::rowsColsAway(oldTile, newTile);
	if (distance.first == 0 || distance.second == 0 || abs(distance.first) == abs(distance.second)) {
		return true;
	}
	return false;
}
