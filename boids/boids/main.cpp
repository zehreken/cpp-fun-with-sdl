#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "triangle.hpp"

const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
SDL_Window *p_window;
SDL_Renderer *p_renderer;

int mouseX;
int mouseY;

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
		p_window = SDL_CreateWindow("boids", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

int main(int argc, const char * argv[])
{
	if (!init())
	{
		printf("Error initializing\n");
		return -1;
	}
	
	const int BOID_COUNT = 100;
	Triangle tris[BOID_COUNT];
	
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
			else if (e.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&mouseX, &mouseY);
			}
			else if (e.type == SDL_KEYUP)
			{
			}
		}
		
		SDL_SetRenderDrawColor(p_renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(p_renderer);
		
		for (int i = 0; i < BOID_COUNT; i++)
		{
			tris[i].moveForward();
			tris[i].look(mouseX, mouseY);
			tris[i].draw(p_renderer);
		}
		
		SDL_RenderPresent(p_renderer);
		
		SDL_Delay(20);
	}
	return 0;
}
