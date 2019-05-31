#include "primitives.hpp"
#include "simpleMath.hpp"
#include <iostream>

Vector2::Vector2()
{
    _x = 0;
    _y = 0;
	_magnitude = dotProduct(*this, *this);
}

Vector2::Vector2(float x, float y)
{
	_x = x;
	_y = y;
	_magnitude = dotProduct(*this, *this);
}

float Vector2::getX()
{
	return _x;
}

float Vector2::getY()
{
	return _y;
}

float Vector2::getMagnitude()
{
	return _magnitude;
}

void primitives_test()
{
	Vector2 v1 = {1, 1};
	Vector2 v2 = {1, 0};
	
	std::cout << v1.getX() << " " << v1.getY() << " " << v1.getMagnitude() << "\n";
	std::cout << v2.getX() << " " << v2.getY() << " " << v2.getMagnitude() << "\n";
}
