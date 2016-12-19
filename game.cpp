#include "game.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "mainwindow.h"
#include <typeinfo>

Game::Game() {
    whiteTurn = true;
    board = new Board();
    prevTile = -1;
}

bool Game::isWhiteTurn() {
    return whiteTurn;
}

Board* Game::getBoard() {
    return board;
}

void Game::setPlayerTurn() {
    whiteTurn = !whiteTurn;
}

tuple<int, int, string, bool> Game::handleMove(int nextTile) {
	if (prevTile == -1) {
		Piece* pieceSelection = board->getPieceAt(nextTile);
		if (pieceSelection != nullptr && pieceSelection->isWhite() == whiteTurn) {
			prevTile = nextTile;
		}
		return tuple<int, int, string, bool>(-1, -1, "", false);
	}
	else {
		if (nextTile == prevTile) {
			prevTile = -1;
			return tuple<int, int, string, bool>(-1, -1, "", false);
		}
		Piece* pieceSelection = board->getPieceAt(prevTile);
		if (pieceSelection != nullptr && isLegalMove(prevTile, pieceSelection, nextTile)) {
			board->movePiece(prevTile, nextTile);
			setPlayerTurn();
			int tempPrev = prevTile;			
			prevTile = -1;
			return tuple<int, int, string, bool>
					(tempPrev, nextTile, pieceSelection->getPieceName(), pieceSelection->isWhite());
		}
		prevTile = -1;
		return tuple<int, int, string, bool>(-1, -1, "", false);		
	}
}

bool Game::isLegalMove(int prevTile, Piece* piece, int nextTile) {
	char pieceID = piece->getPieceID();
	switch (pieceID) {
		case 'P':
			static_cast<Pawn*>(piece);
			break;
		case 'N':
			static_cast<Knight*>(piece);
			break;
		case 'B':
			static_cast<Bishop*>(piece);
			break;
		case 'R':
			static_cast<Rook*>(piece);
			break;
		case 'Q':
			static_cast<Queen*>(piece);
			break;
		case 'K':
			static_cast<King*>(piece);
			break;
	}

	Piece* nextTilePiece = board->getPieceAt(nextTile);
	if (nextTilePiece != nullptr && piece->isWhite() == nextTilePiece->isWhite()) {
		return false;
	}
	
	pair<int, int> distance = Board::rowsColsAway(prevTile, nextTile);
	int rowsAway = distance.first;
	int colsAway = distance.second;
	
	if (piece->checkMove(distance)) {
		if (piece->getPieceID() == 'P') {
			return board->validatePawnMove(prevTile, rowsAway, colsAway);
		}
		
		if (piece->getPieceID() == 'B') {
			return board->validateBishopMove(prevTile, rowsAway, colsAway);
		}
		
		if (piece->getPieceID() == 'R') {
			return board->validateRookMove(prevTile, rowsAway, colsAway);
		}
		
		if (piece->getPieceID() == 'Q') {
			return board->validateQueenMove(prevTile, rowsAway, colsAway);
		}
		
		return true;
	}
	return false;
}


