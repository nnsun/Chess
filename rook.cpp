#include "Rook.h"
#include "Board.h"

Rook::Rook(bool white) {
    this->white = white;
    pieceID = 'R';
    pieceName = "rook";
}

bool Rook::checkMove(pair<int, int> distance) {
	if (distance.first == 0 || distance.second == 0) {
		return true;
	}
	return false;
}
