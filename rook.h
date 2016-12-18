#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(bool = true);
	bool checkMove(int, int) override;	
};


#endif // ROOK_H
