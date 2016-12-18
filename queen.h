#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(bool = true);
	bool checkMove(int, int) override;	
};


#endif // QUEEN_H
