#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(bool white) {
    this->white = white;
    pieceID = 'B';
    pieceName = "bishop";
}

bool Bishop::checkMove(int oldTile, int newTile) {
	pair<int, int> distance = Board::rowsColsAway(oldTile, newTile);
	if (abs(distance.first) == abs(distance.second)) {
		return true;
	}
	return false;
}
