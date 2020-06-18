#include "TicTacToe.h"

TicTacToe::TicTacToe() : BoardGame(3, 3) {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++)
			_board[i][j] = '-';
	}

	Gs = GameState::inProgress;
}

void TicTacToe::getPlayerMove(Move m) {
	if (m.getX() >= 3 || m.getY() >= 3 || _board[m.getX()][m.getY()] != '-')
		throw InvalidMoveException();

	_board[m.getX()][m.getY()] = 'x';


}


GameState TicTacToe::getGameState()
{

	for (int i = 0; i < 3; ++i)
	{
		if (_board[i][0] == _board[i][1] && _board[i][1] == _board[i][2] && _board[i][0] == 'x') //any of the rows is same

		{
			return GameState::playerWins;
		}

		if (_board[i][0] == _board[i][1] && _board[i][1] == _board[i][2] && _board[i][0] == 'o')

		{
			return GameState::computerWins;
		}

		if (_board[0][i] == _board[1][i] && _board[1][i] == _board[2][i] && _board[0][i] == 'x') //any of the columns is same

		{
			return GameState::playerWins;
		}

		if (_board[0][i] == _board[1][i] && _board[1][i] == _board[2][i] && _board[0][i] == 'o')

		{
			return GameState::computerWins;
		}
	}

	// 1st diagonal is same
	if (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2] && _board[0][0] == 'x')
	{
		return GameState::playerWins;


	}

	if (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2] && _board[0][0] == 'o')
	{
		return GameState::computerWins;

	}

	// 2nd diagonal is same
	if (_board[0][2] == _board[1][1] && _board[1][1] == _board[2][0] && _board[0][2] == 'x')
	{
		return GameState::playerWins;
	}

	if (_board[0][2] == _board[1][1] && _board[1][1] == _board[2][0] && _board[0][2] == 'o')
	{
		return GameState::computerWins;
	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++)
			if (_board[i][j] == '-')
				return GameState::inProgress;
	}

	return GameState::Tie;


}


TicTacToeRand::TicTacToeRand() : TicTacToe() {}

void TicTacToeRand::getComputerMove() {
	while (true) {
		int x = rand() % 2;
		int y = rand() % 2;
		if (_board[x][y] == '-') {
			_board[x][y] = 'o';
			break;
		}
	}

}

TicTacToeEdu::TicTacToeEdu() :TicTacToe() {}

void TicTacToeEdu::getComputerMove() {
	int flag = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (_board[i][0] == _board[i][1] && _board[i][0] == 'x' && _board[i][2] == '-') {
			_board[i][2] = 'o';
			++flag;
			break;
		}
		if (_board[i][0] == _board[i][2] && _board[i][0] == 'x' && _board[i][1] == '-') {
			_board[i][1] = 'o';
			++flag;
			break;
		}
		if (_board[i][2] == _board[i][1] && _board[i][2] == 'x' && _board[i][0] == '-') {
			_board[i][0] = 'o';
			++flag;
			break;
		}

		if (_board[0][i] == _board[1][i] && _board[0][i] == 'x' && _board[2][i] == '-') {
			_board[2][i] = 'o';
			++flag;
			break;
		}
		if (_board[0][i] == _board[2][i] && _board[0][i] == 'x' && _board[1][i] == '-') {
			_board[1][i] = 'o';
			++flag;
			break;
		}
		if (_board[2][i] == _board[1][i] && _board[2][i] == 'x' && _board[0][i] == '-') {
			_board[0][i] = 'o';
			++flag;
			break;
		}


	}

	if (flag == 0) {
		while (true) {
			int x = rand() % 2;
			int y = rand() % 2;
			if (_board[x][y] == '-') {
				_board[x][y] = 'o';
				break;
			}
		}
	}
}