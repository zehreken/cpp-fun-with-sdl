#include "triangle.hpp"
#include "simpleMath.hpp"
#include <iostream>
#include <cmath>

Triangle::Triangle()
{
	_center = {256, 256};
	_rotation = 0;
	
	calculateCorners();
	
	_rad_x = 60 * DEG_TO_RAD;
	_rad_y = 60 * DEG_TO_RAD;
	_rad_z = 60 * DEG_TO_RAD;
}

void Triangle::calculateCorners()
{
	const float radius = 100; // outer circle radius
	_x = {_center.getX() + radius * cos((90 + _rotation) * DEG_TO_RAD), _center.getY() + radius * sin((90 + _rotation) * DEG_TO_RAD)}; // top
	_y = {_center.getX() + radius * cos((210 + _rotation) * DEG_TO_RAD), _center.getY() + radius * sin((210 + _rotation) * DEG_TO_RAD)}; // left
	_z = {_center.getX() + radius * cos((330 + _rotation) * DEG_TO_RAD), _center.getY() + radius * sin((330 + _rotation) * DEG_TO_RAD)}; // right
}

void Triangle::draw(SDL_Renderer *p_renderer)
{
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(p_renderer, _x.getX(), _x.getY(), _y.getX(), _y.getY());
	SDL_RenderDrawLine(p_renderer, _y.getX(), _y.getY(), _z.getX(), _z.getY());
	SDL_RenderDrawLine(p_renderer, _z.getX(), _z.getY(), _x.getX(), _x.getY());
	
	SDL_RenderDrawPoint(p_renderer, _center.getX(), _center.getY());
	SDL_RenderDrawPoint(p_renderer, _x.getX(), _x.getY());
	SDL_RenderDrawPoint(p_renderer, _y.getX(), _y.getY());
	SDL_RenderDrawPoint(p_renderer, _z.getX(), _z.getY());
}

void Triangle::rotate(float degree)
{
	_rotation += degree;
	calculateCorners();
}

void triangle_test()
{
	std::cout << "trigonometry tests\n";
	std::cout << sin(30 * DEG_TO_RAD) << " " << sin(60 * DEG_TO_RAD) << " " << sin(90 * DEG_TO_RAD) << "\n";
	std::cout << cos(30 * DEG_TO_RAD) << " " << cos(60 * DEG_TO_RAD) << " " << cos(90 * DEG_TO_RAD) << "\n";
}
