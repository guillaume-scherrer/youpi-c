#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct text_t
{
	TTF_Font* font;
	SDL_Surface* content;
	SDL_Texture* texture;
	SDL_Rect rect;
	SDL_Color color;
} text_t;

void ihm(int* e1, int* e2);

void loop(SDL_Renderer* renderer, text_t* text);

void changeText(SDL_Renderer* renderer, text_t* text, char* content);