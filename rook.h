#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(bool = true);
	bool checkMove(pair<int, int>) override;
};


#endif // ROOK_H
