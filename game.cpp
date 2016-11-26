#include "Game.h"

Game::Game() {
    playerTurn = true;
    whiteCheck = false;
    blackCheck = false;
    board = new Board();
}

bool Game::getPlayerTurn() {
    return playerTurn;
}

void Game::setPlayerTurn() {
    playerTurn = !playerTurn;
}

bool Game::getPlayerChecked() {
    if (playerTurn) {
        return whiteCheck;
    }
    return blackCheck;
}

Board* Game::getBoard() {
    return board;
}

