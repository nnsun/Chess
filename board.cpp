#include <iostream>
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"


Board::Board() {
    for (int i = 0; i < 64; i++) {
        board[i] = nullptr;
    }

    for (int i = 0; i < 8; i++) {
        board[48 + i] = new Pawn(true);
        board[8 + i] = new Pawn(false);
    }

    board[0] = new Rook(false);
    board[1] = new Knight(false);
    board[2] = new Bishop(false);
    board[3] = new Queen(false);
    board[4] = new King(false);
    board[5] = new Bishop(false);
    board[6] = new Knight(false);
    board[7] = new Rook(false);

    board[56] = new Rook(true);
    board[57] = new Knight(true);
    board[58] = new Bishop(true);
    board[59] = new Queen(true);
    board[60] = new King(true);
    board[61] = new Bishop(true);
    board[62] = new Knight(true);
    board[63] = new Rook(true);
}

Piece* Board::getPieceAt(int pos) {
    return board[pos];
}

void Board::movePiece(int prev, int next) {
    board[next] = board[prev];
    board[prev] = nullptr;
}

string Board::toString() {
    string boardStr = "";
    for (int i = 0; i < 64; i++) {
        if (board[i] == nullptr) {
            boardStr += '.';
            boardStr += ' ';
        }
        else {
            boardStr += board[i]->getPieceID();
            boardStr += ' ';
        }
        if (i % 8 == 7) {
            boardStr += '\n';
        }
    }
    return boardStr;
}
