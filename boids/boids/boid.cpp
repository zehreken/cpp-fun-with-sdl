#include "boid.hpp"
#include "globals.h"
#include "simpleMath.hpp"

Boid::Boid()
{
	float randX = rand() % 100;
	float randY = rand() % 100;
	
	_position = {randX, randY};
}

void Boid::update(SDL_Renderer *p_renderer, float deltaTime, int mouseX, int mouseY)
{
//	_triangle.look(<#int mouseX#>, <#int mouseY#>)
	Vector2 diff = Vector2{_position.getX() - mouseX, _position.getY() - mouseY}.getNormalized();
	float newRotation = atan2(diff.getY(), diff.getX()) + PI;
	
	float rDiff = _rotation - newRotation;
	rDiff = abs(rDiff);
	if (rDiff > PI / 50)
	{
		if (rDiff > PI && _rotation > newRotation)
			newRotation += 2 * PI;
		else if (rDiff > PI && _rotation < newRotation)
			newRotation -= 2 * PI;
		
		if (_rotation < newRotation)
			_rotation += ROTATION_SPEED;
		else
			_rotation -= ROTATION_SPEED;
	}
	
	// Keep rotation in range 0 - 2PI
	if (_rotation < 0)
		_rotation += 2 * PI;
	if (_rotation > 2 * PI)
		_rotation -= 2 * PI;
	
	moveForward();
	
	_triangle.setPosition(_position);
	_triangle.setRotation(_rotation);
	_triangle.draw(p_renderer);
	
//	_direction = {20 * cos(_rotation), 20 * sin(_rotation)};
//	calculateCorners();
}

void Boid::moveForward()
{
	_position = {_position.getX() + SPEED * cos(_rotation), _position.getY() + SPEED * sin(_rotation)};
}

Vector2 Boid::ruleOne() // Separation
{
	Vector2 v1;
	int neighbourCount = 0;
	for (int i = 0; i < BOID_COUNT; i++)
	{
		if (this != &boids[i])
		{
			if (distance(_position, boids[i]._position) < 20)
			{
				v1 = {v1.getX() + boids[i]._position.getX(), v1.getY() + boids[i]._position.getY()};
				neighbourCount++;
			}
		}
	}
	if (neighbourCount > 1) v1 = {v1.getX() / neighbourCount, v1.getY() / neighbourCount};
	else v1 = _position;
	
	return v1;
}

Vector2 Boid::ruleTwo() // Allignment
{
    return Vector2();
}

Vector2 Boid::ruleThree() // Cohesion
{
    return Vector2();
}
