#include <iostream>
#include <SDL2/SDL.h>

SDL_Window *p_window;
SDL_Renderer *p_renderer;
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int CELL_SIZE = 1;

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
				
//				int imgFlags = IMG_INIT_PNG;
//				if (!(IMG_Init(imgFlags) & imgFlags))
//				{
//					printf( "SDL_image could not initialize. SDL_image Error: %s\n", IMG_GetError() );
//					success = false;
//				}
			}
		}
	}
	
	return success;
}

void update()
{
	SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(p_renderer);
	
	for (int row = 0; row < SCREEN_HEIGHT / CELL_SIZE; row++)
	{
		for (int column = 0; column < SCREEN_WIDTH / CELL_SIZE; column++)
		{
			SDL_Rect fillRect = {column * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE};
			if (rand() % 2 < 1)
			{
				SDL_SetRenderDrawColor(p_renderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(p_renderer, &fillRect);
			}
		}
	}
	
	SDL_RenderPresent(p_renderer);
	
	SDL_Delay(1000);
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
		}
		
		update();
	}
	
	return 0;
}
