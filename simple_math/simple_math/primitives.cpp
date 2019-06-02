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

Vector2 Vector2::getNormalized()
{
	return {_x / getMagnitude(), _y / getMagnitude()};
}

void primitives_test()
{
	Vector2 v1 = {0, 1};
	Vector2 v2 = {1, 0};
	
	std::cout << v1.getX() << " " << v1.getY() << " " << v1.getMagnitude() << " " << v1.getNormalized().getMagnitude() << "\n";
	std::cout << v2.getX() << " " << v2.getY() << " " << v2.getMagnitude() << " " << v2.getNormalized().getMagnitude() << "\n";
	std::cout << dotProduct(v1, v2) << "\n";
}
