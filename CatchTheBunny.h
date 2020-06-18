#include <iostream>
#include "BoardGame.h"

#pragma once


class CatchTheBunny : public BoardGame {
public:
	CatchTheBunny();
	
	virtual void getPlayerMove(Move m);
	virtual GameState getGameState();

protected:
	int childX;
	int childY;
	int bunnyX;
	int bunnyY;
	int maxsteps;
	int counter;
};



class CatchTheBunnyRand : public CatchTheBunny {
public:
	CatchTheBunnyRand();
	virtual void getComputerMove();

};


class CatchTheBunnyEdu : public CatchTheBunny {
public:
	CatchTheBunnyEdu();
	virtual void getComputerMove();
};

