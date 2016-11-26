#include "Piece.h"

Piece::Piece(bool white) {
    this->white = white;
    active = true;
}

bool Piece::isWhite() {
    return white;
}

bool Piece::isActive() {
    return active;
}

char Piece::getPieceID() {
    return pieceID;
}
