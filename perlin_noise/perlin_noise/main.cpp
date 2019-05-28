#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "constants.hpp"
#include "perlineNoise.hpp"

SDL_Window *p_window;
SDL_Renderer *p_renderer;

float Gradient[IYMAX][IXMAX][2];
float noise[SCREEN_HEIGHT][SCREEN_WIDTH];

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		p_window = SDL_CreateWindow("perlin_noise", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (p_window == NULL)
		{
			printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);
			if (p_renderer == NULL)
			{
				printf("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 255);
			}
		}
	}
	
	return success;
}

void renderNoise()
{
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(p_renderer);
	
	const int CELL_SIZE = 1;
	for (int x = 0; x < IXMAX; x++)
	{
		for (int y = 0; y < IYMAX; y++)
		{
			int color = noise[y][x] * 255;
			SDL_Rect fillRect = {x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
			SDL_SetRenderDrawColor(p_renderer, color, color, color, 0xFF);
			SDL_RenderFillRect(p_renderer, &fillRect);
		}
	}
	
	SDL_RenderPresent(p_renderer);
}

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
			noise[y][x] = perlin(y / 512.0, x / 512.0);
//			std::cout << perlin(y / 512.0, x / 512.0) << "\n";
//			std::cout << Gradient[y][x][0] << "\n";
		}
	}
	
	if (!init())
	{
		printf("Error initializing\n");
		return -1;
	}
	
	bool quit = false;
	bool isStable = false;
	while (!quit)
	{
		SDL_Event e;
		while(SDL_PollEvent( &e ) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYUP)
			{
//				if (e.key.keysym.sym == SDLK_SPACE)
//				{
//					if (!isStable)
//					{
//						isStable = true;
//						renderHeatMap();
//					}
//				}
			}
		}
		
//		if (!isStable)
//			update();
		renderNoise();
		
		SDL_Delay(20);
	}
	
	return 0;
}
