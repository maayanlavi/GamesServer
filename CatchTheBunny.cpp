#include "CatchTheBunny.h"

CatchTheBunny::CatchTheBunny() : BoardGame(9, 9),
childX(rand() % 9), childY(rand() % 9), bunnyX(rand() % 9), bunnyY(rand() % 9),
maxsteps(rand() % 81), counter(0) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			_board[i][j] = '-';
	}
	_board[childX][childY] = 'c';
	_board[bunnyX][bunnyY] = 'b';
}

void CatchTheBunny::getPlayerMove(Move m) {
	if (!((m.getX() == childX && m.getY() == childY + 1) || (m.getX() == childX && m.getY() == childY - 1) ||
		(m.getY() == childY && m.getX() == childX + 1) || (m.getY() == childY && m.getX() == childX - 1) ||
		(m.getY() == childY - 1 && m.getX() == childX - 1) || (m.getY() == childY + 1 && m.getX() == childX + 1) ||
		(m.getY() == childY - 1 && m.getX() == childX + 1) || (m.getY() == childY + 1 && m.getX() == childX - 1)))
		throw InvalidMoveException();

	_board[childX][childY] = '-';
	childX = m.getX();
	childY = m.getY();
	_board[m.getX()][m.getY()] = 'c';
	++counter;
}

//virtual void getComputerMove() {}
GameState CatchTheBunny::getGameState() {
	if (counter == maxsteps)
		return GameState::computerWins;
	if (bunnyX == childX && bunnyY == childY)
		return GameState::playerWins;

	return GameState::inProgress;
}


CatchTheBunnyRand::CatchTheBunnyRand() :CatchTheBunny() {}
void CatchTheBunnyRand::getComputerMove() {
	int randNum = rand() % 7;
	int flag = 0;
	while (flag == 0) {

		switch (randNum)
		{
		case 0: {
			if (_board[bunnyX][bunnyY + 1] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyY += 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		case 1: {
			if (_board[bunnyX][bunnyY - 1] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyY -= 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		case 2: {
			if (_board[bunnyX + 1][bunnyY - 1] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyX += 1;
				bunnyY -= 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		case 3: {
			if (_board[bunnyX - 1][bunnyY - 1] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyX -= 1;
				bunnyY -= 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		case 4: {
			if (_board[bunnyX + 1][bunnyY + 1] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyX += 1;
				bunnyY += 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		case 5: {
			if (_board[bunnyX - 1][bunnyY + 1] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyX -= 1;
				bunnyY += 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		case 6: {
			if (_board[bunnyX + 1][bunnyY] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyX += 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		case 7: {
			if (_board[bunnyX - 1][bunnyY] == '-') {
				_board[bunnyX][bunnyY] = '-';
				bunnyX -= 1;
				_board[bunnyX][bunnyY] = 'b';
				flag = 1;
			}
			break;

		}
		}
	}

}

CatchTheBunnyEdu::CatchTheBunnyEdu() : CatchTheBunny() {}
void CatchTheBunnyEdu::getComputerMove() {
	while (true) {
		int x = rand() % 8;
		int y = rand() % 8;
		if ((x == bunnyX + 1 || x == bunnyX - 1) && (y == bunnyY + 1 || y == bunnyY - 1) && _board[x][y] == '-') {
			_board[bunnyX][bunnyY] = '-';
			_board[x][y] = 'b';
			bunnyX = x;
			bunnyY = y;
			break;
		}
	}
	++counter;
}