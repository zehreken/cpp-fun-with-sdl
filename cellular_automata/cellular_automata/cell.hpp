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
protected:
	void calculateNeighbours();
	Point _position;
	Point _neighbours[8];
private:
	int _currentState;
	int _futureState;
	int getLiveNeighbourCount();
};

class NeumannCell : public Cell
{
public:
	void setPosition(int row, int column);
protected:
	void calculateNeighbours();
};

class ExtendedNeumannCell : public Cell
{
public:
	void setPosition(int row, int column);
protected:
	void calculateNeighbours();
};

class MooreCell : public Cell
{
protected:
	void calculateNeighbours();
};

#endif /* Cell_hpp */
