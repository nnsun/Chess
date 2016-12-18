#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool = true);
	bool checkMove(pair<int, int>) override;
};


#endif // BISHOP_H
