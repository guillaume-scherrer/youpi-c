#include <string.h>
#include "ihm.h"

void ihm(int* e1, int* e2)
{
	static SDL_Window* window = NULL;
	static SDL_Renderer* renderer = NULL;
	text_t text;
	
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
	changeText(renderer, &text, "Nombre: 1654");
	
	SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, text.texture, NULL, &(text.rect));
	SDL_RenderPresent(renderer);
	
	SDL_Delay(1500);
	
	SDL_DestroyTexture(text.texture);
	SDL_FreeSurface(text.content);
	TTF_CloseFont(text.font);
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	TTF_Quit();
	SDL_Quit();
}

void changeText(SDL_Renderer* renderer, text_t* text, char* content)
{
	if(text->content)
		SDL_FreeSurface(text->content);
	
	if(text->texture)
		SDL_DestroyTexture(text->texture);
	
	text->content = TTF_RenderText_Blended(text->font, content, text->color);
	text->texture = SDL_CreateTextureFromSurface(renderer, text->content);
	text->rect.w = text->rect.h / 2 * strlen(content);
}