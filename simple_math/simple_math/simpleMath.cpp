#include "simpleMath.hpp"
#include <math.h>

float lerp(float a, float b, float w)
{
	return (1.0 - w) * a + w * b;
}

float clamp(float x, float lower, float upper)
{
	if (x < lower)
		x = lower;
	else if (x > upper)
		x = upper;
	
	return x;
}

float smoothStep(float a, float b, float x)
{
	x = clamp((x - a) / (b - a), 0.0, 1.0);
	
	return x * x * (3 - 2 * x);
}

float dotProduct(Vector2 v1, Vector2 v2)
{
	return sqrt((v1.getX() * v2.getX() + v1.getY() * v2.getY()));
}
