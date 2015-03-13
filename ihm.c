#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "ihm.h"

void ihm(int* e1, int* e2)
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* input = NULL;
	TTF_Font* font = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	// input = SDL_CreateRGBSurface();
	font = TTF_OpenFont("./SourceCodePro-Regular.otf", 16);
	
	SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	SDL_Delay(1500);
	
	TTF_CloseFont(font);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	TTF_Quit();
	SDL_Quit();
}