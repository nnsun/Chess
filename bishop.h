#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(bool = true);
	bool checkMove(pair<int, int>) override;
};


#endif // BISHOP_H
