#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(bool = true);
	bool checkMove(pair<int, int>) override;
};


#endif // KING_H
