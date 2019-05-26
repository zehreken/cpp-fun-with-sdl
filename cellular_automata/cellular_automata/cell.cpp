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
//extern Cell grid[COLUMN_COUNT][ROW_COUNT];
//extern NeumannCell grid[COLUMN_COUNT][ROW_COUNT];
extern ExtendedNeumannCell grid[COLUMN_COUNT][ROW_COUNT];

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

void NeumannCell::setPosition(int row, int column)
{
	Cell::setPosition(row, column);
	NeumannCell::calculateNeighbours();
}

void ExtendedNeumannCell::setPosition(int row, int column)
{
	Cell::setPosition(row, column);
	ExtendedNeumannCell::calculateNeighbours();
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
			count += grid[_neighbours[i].column][_neighbours[i].row].getCurrentState();
		}
	}
	return count;
}

void Cell::tick()
{
	if (_currentState == 1)
	{
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

// neighbours
// 0 | 1 | 2
// 7 | x | 3
// 6 | 5 | 4
const Point neumannDirections[8] =
{
	{-10000, -10000},
	{-1, 0},
	{-10000, 10000},
	{0, 1},
	{10000, 10000},
	{1, 0},
	{10000, -10000},
	{0, -1},
};
void NeumannCell::calculateNeighbours()
{
	for (int i = 0; i < 8; i++)
	{
		_neighbours[i] = {_position.row + neumannDirections[i].row, _position.column + neumannDirections[i].column};
	}
}

// neighbours
// 0 | 1 | 2
// 7 | x | 3
// 6 | 5 | 4
const Point extendedNeumannDirections[8] =
{
	{-2, 0},
	{-1, 0},
	{0, 2},
	{0, 1},
	{2, 0},
	{1, 0},
	{0, -2},
	{0, -1},
};
void ExtendedNeumannCell::calculateNeighbours()
{
	for (int i = 0; i < 8; i++)
	{
		_neighbours[i] = {_position.row + extendedNeumannDirections[i].row, _position.column + extendedNeumannDirections[i].column};
	}
}
