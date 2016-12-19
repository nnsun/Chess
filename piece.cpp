#include "piece.h"

Piece::Piece(bool white) {
    this->white = white;
}

bool Piece::isWhite() {
    return white;
}

char Piece::getPieceID() {
    return pieceID;
}

string Piece::getPieceName() {
    return pieceName;
}
