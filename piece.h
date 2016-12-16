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
    string getPieceName();
protected:
    bool white;
    bool active;
    char pieceID;
    string pieceName;
};

#endif // PIECE_H
