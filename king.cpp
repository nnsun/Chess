#include "King.h"
#include "Board.h"

King::King(bool white) {
    this->white = white;
    pieceID = 'K';
    pieceName = "king";
}

bool King::checkMove(pair<int, int> distance) {
	if ((abs(distance.first) == 0 || abs(distance.first) == 1) && 
			(abs(distance.second) == 0 || abs(distance.second) == 1)) {
		return true;
	}
	return false;
}
