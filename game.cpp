#include "Game.h"
#include <QDebug>
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "mainwindow.h"

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
			return tuple<int, int, string, bool>(tempPrev, nextTile, pieceSelection->getPieceName(), pieceSelection->isWhite());					
		}
		prevTile = -1;
		return tuple<int, int, string, bool>(-1, -1, "", false);		
	}
}

bool Game::isLegalMove(int prevTile, Piece* piece, int nextTile) {
	char pieceID = piece->getPieceID();
	switch (pieceID) {
		case 'P':
			static_cast<Pawn>(piece);
			break;
		case 'N':
			static_cast<Knight>(piece);
			break;
		case 'B':
			static_cast<Bishop>(piece);
			break;
		case 'R':
			static_cast<Rook>(piece);
			break;
		case 'Q':
			static_cast<Queen>(piece);
			break;
		case 'K':
			static_cast<King>(piece);
			break;
	}
	Piece* nextTilePiece = board->getPieceAt(nextTile);
	if (nextTilePiece != nullptr && piece->isWhite() == nextTilePiece->isWhite()) {
		return false;
	}
	
	if (piece->checkMove(prevTile, nextTile)) {
		return true;		
	}
	return false;
}


