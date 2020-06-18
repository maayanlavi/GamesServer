#pragma once
#include <iostream>
#include "GameAlgorithm.h"
#include "BoardGame.h"
#include <string>



class Interface {
public:
	virtual void printBoard(BoardGame* BG) = 0;
	virtual Move GetPlayerMoveByInterface() = 0;
	virtual void printGameState(BoardGame* BG) = 0;
	virtual void toString(std::string str) const = 0;

};


class ConsoleInterFace : public Interface {

	virtual void printBoard(BoardGame* BG);
	virtual Move GetPlayerMoveByInterface();
	virtual void printGameState(BoardGame* BG);
	void toString(std::string str) const;


};

class GraphicalInterface : public Interface {};
