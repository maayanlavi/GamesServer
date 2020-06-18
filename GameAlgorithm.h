#include <iostream>
#pragma once



enum class GameState { playerWins, computerWins, Tie, inProgress };


class Move {
private:
	int _x;
	int _y;
public:
	Move(int x, int y) : _x(x), _y(y) {}
	Move(const Move& m) : _x(m._x), _y(m._y) {}
	int getX() const { return _x; }
	int getY() const { return _y; }
};


class GameAlgorithm {
public:

	virtual void getPlayerMove(Move m) = 0;
	virtual void getComputerMove() = 0;
	virtual GameState getGameState() = 0;

};

class InvalidMoveException
{
public:
	InvalidMoveException() = default;
	const std::string what()const { return "invalid move!"; };
};


