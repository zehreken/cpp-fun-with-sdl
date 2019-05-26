#include <iostream>
#include <SDL2/SDL.h>
#include "grid.hpp"
#include "cell.hpp"

SDL_Window *p_window;
SDL_Renderer *p_renderer;

//Cell grid[COLUMN_COUNT][ROW_COUNT];
//NeumannCell grid[COLUMN_COUNT][ROW_COUNT];
ExtendedNeumannCell grid[COLUMN_COUNT][ROW_COUNT];

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
		p_window = SDL_CreateWindow("cellular_automata", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

void update()
{
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(p_renderer);
	
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			SDL_Rect fillRect = {column * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE};
			if (grid[column][row].getCurrentState() == 1)
			{
				SDL_SetRenderDrawColor(p_renderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(p_renderer, &fillRect);
			}
			grid[column][row].tick();
		}
	}
	
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			grid[column][row].swap();
		}
	}
	
	SDL_RenderPresent(p_renderer);
	
	SDL_Delay(20);
}

int main(int argc, const char * argv[])
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			grid[column][row].setPosition(row, column);
		}
	}
	
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
		}
		
		update();
	}
	
	return 0;
}
