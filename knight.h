#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
public:
    Knight(bool = true);
	bool checkMove(pair<int, int>) override;
};


#endif // KNIGHT_H
