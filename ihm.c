#include <stdio.h>
#include <string.h>
#include "ihm.h"
#include "define.h"

void ihm(int* e1, int* e2)
{
	static SDL_Window* window = NULL;
	static SDL_Renderer* renderer = NULL;
	text_t text;
	int* numbers[] = {e1, e2};
	
	text.font = NULL;
	text.content = NULL;
	text.texture = NULL;
	text.rect = (SDL_Rect){10, 10, 0, 64};
	text.color = (SDL_Color){255, 255, 255, 255};
	
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	
	text.font = TTF_OpenFont("./SourceCodePro-Regular.otf", 64);
	changeText(renderer, &text, "Nombre: ");
	
	loop(renderer, &text, numbers, 2);
	
	SDL_DestroyTexture(text.texture);
	SDL_FreeSurface(text.content);
	TTF_CloseFont(text.font);
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	TTF_Quit();
	SDL_Quit();
}

void loop(SDL_Renderer* renderer, text_t* text, int** numbers, int numCount)
{
	static const char message[] = "Nombre: %d";
	char tmp[MAX_STRING_SIZE];
	int numDone = 0;
	int stop = 0;
	int number = 0;
	int numSize = 0;
	SDL_Event event;
	
	SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
	
	while(!stop && numDone < 2)
	{
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
			case SDL_QUIT:
			{
				stop = 1;
			} break;
			
			case SDL_KEYDOWN:
			{
				if(numSize < 4 && event.key.keysym.sym >= SDLK_KP_1 && event.key.keysym.sym <= SDLK_KP_0)
				{
					number *= 10;
					number += event.key.keysym.sym == SDLK_KP_0 ?
						0:
						event.key.keysym.sym - SDLK_KP_1 + 1;
					
					++numSize;
					
					sprintf(tmp, message, number);
					changeText(renderer, text, tmp);
				} else if(event.key.keysym.sym == SDLK_RETURN)
				{
					*(numbers[numDone]) = number;
					number = 0;
					++numDone;
					numSize = 0;
					
					sprintf(tmp, message, number);
					changeText(renderer, text, tmp);
				} else if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					stop = 1;
				}
			} break;
			
			default:
				break;
		}
		
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, text->texture, NULL, &(text->rect));
		SDL_RenderPresent(renderer);
	}
}

void changeText(SDL_Renderer* renderer, text_t* text, char* content)
{
	if(text->content)
	{
		SDL_FreeSurface(text->content);
	}
	
	if(text->texture)
	{
		SDL_DestroyTexture(text->texture);
	}
	
	text->content = TTF_RenderText_Blended(text->font, content, text->color);
	text->texture = SDL_CreateTextureFromSurface(renderer, text->content);
	text->rect.w = text->rect.h / 2 * strlen(content);
}