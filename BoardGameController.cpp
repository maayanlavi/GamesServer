#include "BoardGameController.h"

BoardGameController::BoardGameController (BoardGame* BG, Interface* IF) {
	theGame = BG;
	show = IF;
}
void BoardGameController::play() {
	show->printBoard(theGame);
	GameState gs = GameState::inProgress;
	while (gs == GameState::inProgress)
	{

		try {
			theGame->getPlayerMove(show->GetPlayerMoveByInterface());
			gs = theGame->getGameState();

		}
		catch (InvalidMoveException ex) {
			show->printBoard(theGame);
			show->printGameState(theGame);
			show->toString(ex.what());
		}

		show->printBoard(theGame);
		show->printGameState(theGame);
		if (theGame->getGameState() != GameState::inProgress)
			break;
		theGame->getComputerMove();
		std::cout << "comuter turn:" << std::endl;
		show->printBoard(theGame);
		show->printGameState(theGame);

	}
}