#pragma once
#include <iostream>
#include "BoardGame.h"
#include "Interface.h"
#include<memory>

#pragma once

class BoardGameController {

public:
	BoardGameController(BoardGame* BG, Interface* IF);
	void play();
	

private:
	Interface* show;
	BoardGame* theGame;
};



