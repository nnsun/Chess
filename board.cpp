#include <iostream>
#include <algorithm>
#include "Board.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
using namespace std;


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

pair<int, int> Board::rowsColsAway(int prevTile, int nextTile) {
	int rowsAway = nextTile / 8 - prevTile / 8;
	int colsAway = nextTile % 8 - prevTile % 8;
	pair<int, int> rowColDiff = make_pair(rowsAway, colsAway);
	return rowColDiff;
}

int Board::rowsColsToPos(int start, pair<int, int> distance) {
	return start + 8 * distance.first + distance.second;
}

bool Board::validatePawnMove(int prevTile, int rowsAway, int colsAway) {
	pair<int, int> distance = make_pair(rowsAway, colsAway);
	int nextTile = Board::rowsColsToPos(prevTile, distance);
	Piece* currentPiece = getPieceAt(prevTile);
	Piece* nextTilePiece = getPieceAt(nextTile);
	int prevRow = prevTile / 8;
	int startRow = currentPiece->isWhite() ? 6 : 1;
	if (abs(distance.first) == 2 && prevRow != startRow) {
		return false;
	}
	if (abs(colsAway) == 1 && (nextTilePiece == nullptr || 
							   nextTilePiece->isWhite() == currentPiece->isWhite())) {
		return false;
	}
	if (abs(colsAway) == 0 && nextTilePiece != nullptr && 
			getPieceAt(Board::rowsColsToPos(prevTile, distance))) {
		return false;
	}

	return true;
}

bool Board::validateBishopMove(int prevTile, int rowsAway, int colsAway) {
	for (int i = 1; i < abs(rowsAway); i++) {
		pair<int, int> tempDist = make_pair(i * abs(rowsAway) / rowsAway, i * abs(colsAway) / colsAway);
		int tempPos = Board::rowsColsToPos(prevTile, tempDist);
		if (getPieceAt(tempPos) != nullptr) {
			return false;
		}
	}
	return true;
}

bool Board::validateRookMove(int prevTile, int rowsAway, int colsAway) {
	for (int i = 1; i < max(abs(rowsAway), abs(colsAway)); i++) {
		pair<int, int> tempDist;
		if (rowsAway == 0) {
			tempDist = make_pair(0, i * abs(colsAway) / colsAway);
			
		}
		else {
			tempDist = make_pair(i * abs(rowsAway) / rowsAway, 0);
		}
		int tempPos = Board::rowsColsToPos(prevTile, tempDist);
		if (getPieceAt(tempPos) != nullptr) {
			return false;
		}
	}
	return true;
}

bool Board::validateQueenMove(int prevTile, int rowsAway, int colsAway) {
	if (abs(rowsAway) == abs(colsAway)) {
		return validateBishopMove(prevTile, rowsAway, colsAway);
	}
	return validateRookMove(prevTile, rowsAway, colsAway);
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
