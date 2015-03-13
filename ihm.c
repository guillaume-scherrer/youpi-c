//#include <SDL2/SDL.h>
#include "SDL2/include/SDL.h"
#include "ihm.h"

void ihm(int* e1, int* e2)
{
	SDL_Window* window;
	
	SDL_Init(SDL_INIT_VIDEO);
	
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	
	SDL_Delay(1500);
	
	SDL_DestroyWindow(window);
	
	SDL_Quit();
}