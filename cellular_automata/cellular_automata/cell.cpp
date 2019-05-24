#include "cell.hpp"
#include "grid.hpp"
#include <iostream>

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
extern Cell grid[COLUMN_COUNT][ROW_COUNT];

void Cell::setPosition(int row, int column)
{
	_currentState = 0;
	_futureState = 0;
	
	if (rand() % 2 < 1)
		_currentState = 1;
	else
		_currentState = 0;
	
	_position.row = row;
	_position.column = column;
	
	calculateNeighbours();
}

int Cell::getCurrentState()
{
	return _currentState;
}

int Cell::getLiveNeighbourCount()
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (_neighbours[i].row >= 0 &&
			_neighbours[i].row < ROW_COUNT &&
			_neighbours[i].column >= 0 &&
			_neighbours[i].column < COLUMN_COUNT)
		{
//			printf("column: %d row: %d state: %d\n", _neighbours[i].column, _neighbours[i].row, grid[_neighbours[i].column][_neighbours[i].row].getCurrentState());
			count += grid[_neighbours[i].column][_neighbours[i].row].getCurrentState();
		}
	}
	return count;
}

void Cell::tick()
{
	if (_currentState == 1)
	{
		_position;
		int liveNeighbourCount = getLiveNeighbourCount();
		if (liveNeighbourCount < 2)
		{
			_futureState = 0;
		}
		else if (liveNeighbourCount == 2 || liveNeighbourCount == 3)
		{
			_futureState = 1;
		}
		else
		{
			_futureState = 0;
		}
	}
	else
	{
		int liveNeighbourCount = getLiveNeighbourCount();
		if (liveNeighbourCount == 3)
		{
			_futureState = 1;
		}
		else
		{
			_futureState = 0;
		}
	}
}

void Cell::swap()
{
	_currentState = _futureState;
}

void Cell::calculateNeighbours()
{
	for (int i = 0; i < 8; i++)
	{
		_neighbours[i] = {_position.row + directions[i].row, _position.column + directions[i].column};
	}
}
