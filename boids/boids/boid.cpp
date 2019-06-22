#include "boid.hpp"
#include "globals.h"
#include "simpleMath.hpp"

Boid::Boid()
{
    
}

void Boid::update(float deltaTime)
{
//	_triangle.look(<#int mouseX#>, <#int mouseY#>)
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
