#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>
using namespace std;

class Piece {
public:
    Piece(bool = true);
    bool isWhite();
    char getPieceID();
    string getPieceName();
	virtual bool checkMove(pair<int, int>) = 0;
protected:
    bool white;
    char pieceID;
    string pieceName;
};

#endif // PIECE_H
