#include "Interface.h"

void ConsoleInterFace::toString (std::string str) const
{
	std::cout << std::endl << str << std::endl;
}

void ConsoleInterFace::printBoard(BoardGame* BG) {
	std::cout << "  ";
	for (int j = 0; j < BG->getCols(); j++)
		std::cout << j << " ";
	std::cout << std::endl;

	for (int i = 0; i < BG->getRows(); i++) {
		std::cout << i << " ";
		for (int j = 0; j < BG->getCols(); j++) 
			std::cout << BG->getBoard()[i][j] << " ";
		std::cout << std::endl;
	}
}
Move ConsoleInterFace::GetPlayerMoveByInterface() {
	int x, y;
	std::cout << "enter row number" << std::endl;
	std::cin >> x;
	std::cout << "enter col number" << std::endl;
	std::cin >> y;
	Move m(x, y);
	return m;
}

void ConsoleInterFace::printGameState(BoardGame* BG) {
	switch (BG->getGameState()) {
	case GameState::computerWins:
		std::cout << "computerWins" << std::endl;
		break;
	case GameState::inProgress:
		std::cout << "inProgress" << std::endl;
		break;
	case GameState::playerWins:
		std::cout << "playerWins" << std::endl;
		break;
	case GameState::Tie:
		std::cout << "Tie" << std::endl;
		break;
	}
}