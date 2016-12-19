#include "knight.h"
#include "board.h"

Knight::Knight(bool white) {
    this->white = white;
    pieceID = 'N';
    pieceName = "knight";
}

bool Knight::checkMove(pair<int, int> distance) {
	if ((abs(distance.first) == 2 && abs(distance.second) == 1) || 
			(abs(distance.first) == 1 && abs(distance.second) == 2)) {
		return true;
	}
	return false;
}
