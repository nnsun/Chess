#include "Rook.h"
#include "Board.h"

Rook::Rook(bool white) {
    this->white = white;
    pieceID = 'R';
    pieceName = "rook";
}

bool Rook::checkMove(int oldTile, int newTile) {
	pair<int, int> distance = Board::rowsColsAway(oldTile, newTile);
	if (distance.first == 0 || distance.second == 0) {
		return true;
	}
	return false;
}
