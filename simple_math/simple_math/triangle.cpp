#include "triangle.hpp"
#include "simpleMath.hpp"
#include <iostream>
#include <cmath>

const float RAD_90 = 90 * DEG_TO_RAD;
const float RAD_210 = 210 * DEG_TO_RAD;
const float RAD_330 = 330 * DEG_TO_RAD;

Triangle::Triangle()
{
	_center = {256, 256};
	_rotation = 0;
	_direction = {_center.getX() + 0, _center.getY() + 20};
	
	calculateCorners();
	Vector2 target = {512, 256};
	auto diff = Vector2{target.getX() - _center.getX(), target.getY() - _center.getY()};
	
	std::cout << distance(_x, _y) << "\n";
	std::cout << distance(_y, _z) << "\n";
	std::cout << distance(_z, _x) << "\n";
	std::cout << "atan2: " << atan2(diff.getY(), diff.getX()) * RAD_TO_DEG << "\n";
	
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
	SDL_SetRenderDrawColor(p_renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(p_renderer, _x.getX(), _x.getY(), _y.getX(), _y.getY());
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(p_renderer, _y.getX(), _y.getY(), _z.getX(), _z.getY());
	SDL_RenderDrawLine(p_renderer, _z.getX(), _z.getY(), _x.getX(), _x.getY());
	
	SDL_RenderDrawPoint(p_renderer, _center.getX(), _center.getY());
	SDL_RenderDrawPoint(p_renderer, _x.getX(), _x.getY());
	SDL_RenderDrawPoint(p_renderer, _y.getX(), _y.getY());
	SDL_RenderDrawPoint(p_renderer, _z.getX(), _z.getY());
	
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(p_renderer, _center.getX(), _center.getY(), _center.getX() + _direction.getX(), _center.getY() + _direction.getY());
}

void Triangle::rotate(float degree)
{
	_rotation += degree;
	calculateCorners();
}

void Triangle::look(int mouseX, int mouseY)
{
	Vector2 diff = {_center.getX() - mouseX, _center.getY() - mouseY};
	_rotation = atan2(diff.getY(), diff.getX()) * RAD_TO_DEG + 90;
	_direction = {100 * cos((_rotation - 90) * DEG_TO_RAD), 100 * sin((_rotation - 90) * DEG_TO_RAD)};
	calculateCorners();
}

void triangle_test()
{
	std::cout << "trigonometry tests\n";
	std::cout << sin(30 * DEG_TO_RAD) << " " << sin(60 * DEG_TO_RAD) << " " << sin(90 * DEG_TO_RAD) << "\n";
	std::cout << cos(30 * DEG_TO_RAD) << " " << cos(60 * DEG_TO_RAD) << " " << cos(90 * DEG_TO_RAD) << "\n";
}
