#include "Game.h"

Game::Game() {
    whiteTurn = true;
    board = new Board();
}

bool Game::isWhiteTurn() {
    return whiteTurn;
}

void Game::setPlayerTurn() {
    whiteTurn = !whiteTurn;
}

Board* Game::getBoard() {
    return board;
}

