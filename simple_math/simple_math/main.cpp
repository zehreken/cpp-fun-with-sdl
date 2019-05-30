#include <iostream>
#include <SDL2/SDL.h>
#include "simpleMath.hpp"

const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int CELL_SIZE = 1;
SDL_Window *p_window;
SDL_Renderer *p_renderer;

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
		p_window = SDL_CreateWindow("simple_math", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

void renderGraph()
{
	SDL_SetRenderDrawColor(p_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(p_renderer);
	
	for (int column = 0; column < SCREEN_WIDTH; column++)
	{
//		float y = lerp(0.0, 1.0, column / (float)SCREEN_WIDTH);
//		float y = smoothStep(0.0, 1.0, column / (float)SCREEN_WIDTH);
		float y = clamp(column / (float)SCREEN_WIDTH, 0.2, 0.8);
		
		int iy = y * SCREEN_WIDTH;
		SDL_Rect fillRect = {column * CELL_SIZE, iy * CELL_SIZE, CELL_SIZE, CELL_SIZE};
		SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(p_renderer, &fillRect);
	}
	
	SDL_RenderPresent(p_renderer);
}

int main(int argc, const char * argv[])
{
	if (!init())
	{
		printf("Error initializing\n");
		return -1;
	}
	
	bool quit = false;
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
			}
		}
		
		renderGraph();
		
		SDL_Delay(20);
	}
	
    return 0;
}