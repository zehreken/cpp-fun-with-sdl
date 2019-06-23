#include "boid.hpp"
#include "globals.h"
#include "simpleMath.hpp"

Boid boids[BOID_COUNT];

Boid::Boid()
{
	float randX = rand() % 35 + 100;
	float randY = rand() % 35 + 100;
	
	_position = {randX, randY};
}

void Boid::update(SDL_Renderer *p_renderer, float deltaTime, int mouseX, int mouseY)
{
	Vector2 diff = Vector2{mouseX - _position.getX(), mouseY - _position.getY()};
	Vector2 v1 = ruleOne();
	Vector2 v3 = ruleThree();
	diff = Vector2{diff.getX() * 4 + v1.getX(), diff.getY() * 4 + v1.getY()}; // Separation
	diff = Vector2{diff.getX() - v3.getX() * 40, diff.getY() - v3.getY() * 40};
	float newRotation = atan2(diff.getY(), diff.getX());
	
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

Vector2 Boid::getPosition()
{
	return _position;
}

void Boid::moveForward()
{
	_position = {_position.getX() + SPEED * cos(_rotation), _position.getY() + SPEED * sin(_rotation)};
}

Vector2 Boid::ruleOne() // Separation
{
	Vector2 v1 = {0, 0};
	int neighbourCount = 0;
	for (int i = 0; i < BOID_COUNT; i++)
	{
		if (this != &boids[i])
		{
			Boid temp = boids[i];
			if (distance(_position, temp.getPosition()) < 5)
			{
				v1 = {v1.getX() + temp.getPosition().getX(), v1.getY() + temp.getPosition().getY()};
				neighbourCount++;
			}
		}
	}
	if (neighbourCount > 0) v1 = {v1.getX() / neighbourCount, v1.getY() / neighbourCount};
	else v1 = _position;
	
	v1 = {v1.getX() - _position.getX(), v1.getY() - _position.getY()};
	return v1;
}

Vector2 Boid::ruleTwo() // Allignment
{
    return Vector2();
}

Vector2 Boid::ruleThree() // Cohesion
{
	Vector2 v3 = {0, 0};
	int neighbourCount = 0;
	for (int i = 0; i < BOID_COUNT; i++)
	{
		if (this != &boids[i])
		{
			Boid temp = boids[i];
			if (distance(_position, temp.getPosition()) < 60)
			{
				v3 = {v3.getX() + temp.getPosition().getX(), v3.getY() + temp.getPosition().getY()};
				neighbourCount++;
			}
		}
	}
	if (neighbourCount > 0) v3 = {v3.getX() / neighbourCount, v3.getY() / neighbourCount};
	else v3 = _position;
	
	v3 = {v3.getX() - _position.getX(), v3.getY() - _position.getY()};
	return v3;
}
