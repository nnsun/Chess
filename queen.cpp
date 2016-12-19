#include "queen.h"
#include "board.h"

Queen::Queen(bool white) {
    this->white = white;
    pieceID = 'Q';
    pieceName = "queen";
}

bool Queen::checkMove(pair<int, int> distance) {
	if (distance.first == 0 || distance.second == 0 || abs(distance.first) == abs(distance.second)) {
		return true;
	}
	return false;
}
