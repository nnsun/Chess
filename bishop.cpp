#include "bishop.h"
#include "board.h"

Bishop::Bishop(bool white) {
    this->white = white;
    pieceID = 'B';
    pieceName = "bishop";
}

bool Bishop::checkMove(pair<int, int> distance) {
	if (abs(distance.first) == abs(distance.second)) {
		return true;
	}
	return false;
}
