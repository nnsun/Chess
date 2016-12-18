#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(bool = true);
	bool checkMove(int, int) override;
};


#endif // PAWN_H
