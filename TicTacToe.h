#include <iostream>
#include "BoardGame.h"

#pragma once

class TicTacToe : public BoardGame {

public:
	TicTacToe();
	virtual void getPlayerMove(Move m);
	virtual GameState getGameState();

};

class TicTacToeRand : public TicTacToe {
public:
	TicTacToeRand();
	virtual void getComputerMove();
	
};


class TicTacToeEdu : public TicTacToe {
public:
	TicTacToeEdu();
	virtual void getComputerMove();
		
};


