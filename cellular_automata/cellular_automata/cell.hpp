#ifndef cell_hpp
#define cell_hpp

struct Point
{
	int row;
	int column;
};

class Cell
{
public:
	void setPosition(int row, int column);
	int getCurrentState();
	void tick();
	void swap();
private:
	int _currentState;
	int _futureState;
	Point _position;
	Point _neighbours[8];
	void calculateNeighbours();
	int getLiveNeighbourCount();
};

#endif /* Cell_hpp */