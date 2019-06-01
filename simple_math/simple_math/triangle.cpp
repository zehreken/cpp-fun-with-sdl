#include "triangle.hpp"
#include "simpleMath.hpp"
#include <iostream>
#include <cmath>

Triangle::Triangle()
{
	_x = 1;
	_y = 1;
	_z = 1;
	_rad_x = 60 * DEG_TO_RAD;
	_rad_y = 60 * DEG_TO_RAD;
	_rad_z = 60 * DEG_TO_RAD;
}

void triangle_test()
{
	std::cout << "trigonometry tests\n";
	std::cout << sin(30 * DEG_TO_RAD) << " " << sin(60 * DEG_TO_RAD) << " " << sin(90 * DEG_TO_RAD) << "\n";
}
