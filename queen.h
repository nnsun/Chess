#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
public:
    Queen(bool = true);
	bool checkMove(pair<int, int>) override;
};


#endif // QUEEN_H
