#include "cell.hpp"

// neighbours
// 0 | 1 | 2
// 7 | x | 3
// 6 | 5 | 4
const Point directions[8] =
{
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
};

void Cell::setPosition(int row, int column)
{
	_currentState = 0;
	_futureState = 0;
	
	_position.row = row;
	_position.column = column;
	
	calculateNeighbours();
}

int Cell::getCurrentState()
{
	return _currentState;
}

void Cell::tick()
{
	if (_currentState == 1)
	{
		
	}
}

void Cell::calculateNeighbours()
{
	for (int i = 0; i < 8; i++)
	{
		_neighbours[i] = {_position.row + directions[i].row, _position.column + directions[i].column};
	}
}
