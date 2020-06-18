#include <iostream>
#include <vector>
#include "GameAlgorithm.h"

#pragma once

class BoardGame : public GameAlgorithm {
public:
	BoardGame(int rows, int cols) : _rows(rows), _cols(cols), _board(rows, std::vector<char>(cols)) {
		Gs = GameState::inProgress;
	}

	BoardGame(const BoardGame& other) : _rows(other._rows), _cols(other._cols), _board(other._board) {
		Gs = GameState::inProgress;
	}

	virtual void getPlayerMove(Move m) {}
	virtual void getComputerMove() {}
	virtual GameState getGameState() { return GameState::inProgress; }
	
	int getRows() {
		return _rows;
	}
	int getCols() {
		return _cols;
	}
	std::vector<std::vector<char>> getBoard() { return _board; }

	GameState Gs;

protected:
	int _rows;
	int _cols;
	std::vector<std::vector<char>> _board;

};
