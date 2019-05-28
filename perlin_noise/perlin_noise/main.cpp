#include <iostream>
#include "constants.hpp"
#include "perlineNoise.hpp"
#include <math.h>

float Gradient[IYMAX][IXMAX][2];

int main(int argc, const char * argv[])
{
	for (int x = 0; x < IXMAX; x++)
	{
		for (int y = 0; y < IYMAX; y++)
		{
			float vx = ((float)rand() / RAND_MAX) * 2 - 1;
			float vy = ((float)rand() / RAND_MAX) * 2 - 1;
			float length = sqrt(vx * vx + vy * vy);
			Gradient[y][x][0] = vx / length;
			Gradient[y][x][1] = vy / length;
		}
	}
	
	for (int x = 0; x < IXMAX; x++)
	{
		for (int y = 0; y < IYMAX; y++)
		{
			std::cout << perlin(y / 512.0, x / 512.0) << "\n";
//			std::cout << Gradient[y][x][0] << "\n";
		}
	}
	return 0;
}
