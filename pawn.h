#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
public:
    Pawn(bool = true);
	bool checkMove(pair<int, int>) override;
};


#endif // PAWN_H
