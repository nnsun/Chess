#include "pawn.h"

Pawn::Pawn(bool white) {
    this->white = white;
    pieceID = 'P';
    pieceName = "pawn";
}

bool Pawn::checkMove(pair<int, int> distance) {
	int moveDirection = isWhite() ? -1 : 1;
	if (distance.first == moveDirection && (distance.second == 0 || abs(distance.second) == 1)) {
		return true;
	}
	
	if (distance.first == (moveDirection * 2) && distance.second == 0) {
		return true;
	}
	return false;
}
