#ifndef PIECE_H
#define PIECE_H

#include <vector>
using namespace std;

class Piece {
public:
    Piece(bool = true);
    bool isWhite();
    bool isActive();
    char getPieceID();
protected:
    bool white;
    bool active;
    char pieceID;
};

#endif // PIECE_H
