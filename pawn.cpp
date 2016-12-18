#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(bool white) {
    this->white = white;
    pieceID = 'P';
    pieceName = "pawn";
}

bool Pawn::checkMove(int oldTile, int newTile) {
	pair<int, int> distance = Board::rowsColsAway(oldTile, newTile);
	int moveDirection = isWhite() ? -1 : 1;
	if ((distance.first == moveDirection && distance.second == 0) || (distance.first == moveDirection && distance.second == 1)) {
		return true;
	}
	return false;
}

