#include "triangle.hpp"
#include "simpleMath.hpp"
#include <iostream>
#include <cmath>

const float RAD_0 = 0 * DEG_TO_RAD;
const float RAD_120 = 120 * DEG_TO_RAD;
const float RAD_240 = 240 * DEG_TO_RAD;
const float SPEED = 3;
const float ROTATION_SPEED = 2 * DEG_TO_RAD;

Triangle::Triangle()
{
	float randX = rand() % 100;
	float randY = rand() % 100;
	_center = {randX, randY};
	_rotation = 0;
	_direction = {_center.getX() + 0, _center.getY() + 20};
	
	calculateCorners();
	Vector2 target = {512, 256};
	auto diff = Vector2{target.getX() - _center.getX(), target.getY() - _center.getY()};
	
	std::cout << distance(_a, _b) << "\n";
	std::cout << distance(_b, _c) << "\n";
	std::cout << distance(_c, _a) << "\n";
	std::cout << "atan2: " << atan2(diff.getY(), diff.getX()) * RAD_TO_DEG << "\n";
	
	// rename this to _rad_a...
	_rad_x = 60 * DEG_TO_RAD;
	_rad_y = 60 * DEG_TO_RAD;
	_rad_z = 60 * DEG_TO_RAD;
}

void Triangle::calculateCorners()
{
	const float radius = 10; // outer circle radius
	_a = {_center.getX() + radius * cos(RAD_0 + _rotation), _center.getY() + radius * sin(RAD_0 + _rotation)}; // top
	_b = {_center.getX() + radius * cos(RAD_120 + _rotation), _center.getY() + radius * sin(RAD_120 + _rotation)}; // left
	_c = {_center.getX() + radius * cos(RAD_240 + _rotation), _center.getY() + radius * sin(RAD_240 + _rotation)}; // right
}

void Triangle::draw(SDL_Renderer *p_renderer)
{
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(p_renderer, _a.getX(), _a.getY(), _b.getX(), _b.getY());
	SDL_SetRenderDrawColor(p_renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(p_renderer, _b.getX(), _b.getY(), _c.getX(), _c.getY());
	SDL_SetRenderDrawColor(p_renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawLine(p_renderer, _c.getX(), _c.getY(), _a.getX(), _a.getY());
	
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawPoint(p_renderer, _center.getX(), _center.getY());
	SDL_RenderDrawPoint(p_renderer, _a.getX(), _a.getY());
	SDL_RenderDrawPoint(p_renderer, _b.getX(), _b.getY());
	SDL_RenderDrawPoint(p_renderer, _c.getX(), _c.getY());
	
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(p_renderer, _center.getX(), _center.getY(), _center.getX() + _direction.getX(), _center.getY() + _direction.getY());
}

void Triangle::rotate(float degree) // refactor this to accept radian
{
	_rotation += degree * DEG_TO_RAD;
	calculateCorners();
}

void Triangle::moveForward()
{
	_center = {_center.getX() + SPEED * cos(_rotation), _center.getY() + SPEED * sin(_rotation)};
}

void Triangle::look(int mouseX, int mouseY)
{
	Vector2 diff = {_center.getX() - mouseX, _center.getY() - mouseY};
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

	_direction = {20 * cos(_rotation), 20 * sin(_rotation)};
	calculateCorners();
}

void triangle_test()
{
	std::cout << "trigonometry tests\n";
	std::cout << sin(30 * DEG_TO_RAD) << " " << sin(60 * DEG_TO_RAD) << " " << sin(90 * DEG_TO_RAD) << "\n";
	std::cout << cos(30 * DEG_TO_RAD) << " " << cos(60 * DEG_TO_RAD) << " " << cos(90 * DEG_TO_RAD) << "\n";
}
