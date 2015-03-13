#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "ihm.h"

void ihm(int* e1, int* e2)
{
	SDL_Window* window = NULL;
	TTF_Font* font = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	// font = TTF_OpenFont();
	
	SDL_Delay(1500);
	
	TTF_CloseFont(font);
	SDL_DestroyWindow(window);
	
	TTF_Quit();
	SDL_Quit();
}